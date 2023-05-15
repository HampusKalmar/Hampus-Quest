#include "../include/game.h"

/**
 * The Game constructor initializes the game window and sets the framerate limit.
 */
Game::Game() :
  gameWindow(sf::VideoMode(1000, 900), "Hampus Quest", sf::Style::Close | sf::Style::Titlebar)
{
  gameWindow.setFramerateLimit(30);
}

/**
 * The Game destructor frees the memory allocated to the sound and the main menu objects.
 */
Game::~Game()
{
  delete sound;
  delete mainMenu;
  delete gameOverMenu;
}

/**
 * Sets the view of the game indow to the player.
 */
void Game::setCamera()
{
  sf::Vector2u windowSize = gameWindow.getSize();
  float viewX = player.getSprite().getPosition().x - windowSize.x / 2.0f;
  float viewY = player.getSprite().getPosition().y - windowSize.y / 2.0f;
  sf::View view(sf::FloatRect(viewX, viewY, windowSize.x, windowSize.y));
  gameWindow.setView(view);
}

/**
 * Draws the game objects on the game window. 
 */
void Game::drawGameObjects()
{
  gameWindow.clear(sf::Color(0, 0, 70));
  gameWindow.draw(enemy.getEnemySprite());
  gameWindow.draw(secondEnemy.getSecondEnemySprite());
  environment.drawGround(gameWindow);
  gameWindow.draw(player.getSprite());
  player.playerAnimation();
  player.updatePlayerMovement();
  enemy.enemyAnimation();
  enemy.updateEnemyMovement();
  secondEnemy.updateSecondEnemyMovement();
  secondEnemy.secondEnemyAnimation();
  gameWindow.display();
}

/**
 * A method that checks for different types of collisions. 
 */
void Game::gameCollision()
{
  if (collision.checkSpriteCollision(player.getSprite(), enemy.getEnemySprite()))
  {
    sound->stopGameMusic();
    gameOver();
  }

  if (collision.checkSpriteCollision(player.getSprite(), secondEnemy.getSecondEnemySprite()))
  {
    sound->stopGameMusic();
    gameOver();
  }

  bool isOnGround = collision.checkSpriteCollisionWithGround(player.getSprite(), environment.getSpriteBlocks());
  if (isOnGround)
  {
    player.resetVelocity();
  }
  else 
  {
    player.fallingVelocity();
  }
}

/**
 * A method that handles user input events.
 */
void Game::handleEvents()
{
  while (gameWindow.pollEvent(event))
  {
    mainMenu->handleEvent(event);
    gameOverMenu->handleEvent(event);
    if (event.type == sf::Event::Closed)
    {
      gameWindow.close();
    }
  }
}

/**
 * The gameLoop method is the main loop of the game. 
 */
void Game::gameLoop()
{
  gameWindow.setActive(true);
  theGameIsOver = false;
  gameStarted = false;

  while (gameWindow.isOpen())
  {
    handleEvents();
    if (mainMenu->isExitPressed())
    {
      gameWindow.close();
    }
    else if (mainMenu->isPlayPressed())
    {
      gameStarted = true;
      sound->stopMenuMusic();
      sound->gameMusic();
    }

    if (gameStarted)
    {
      if (!theGameIsOver) // Add a check to avoid updating the game state after game over
      {
        gameCollision();
        setCamera();
        drawGameObjects();
      }

      if (!theGameIsOver) // Add a check to avoid playing the menu music during game over
      {
        if (!inGameMusicIsPlaying)
        {
          sound->gameMusic();
          inGameMusicIsPlaying = true;
        }
      }
      else
      {
        theGameIsOver = false;
        gameWindow.clear();
        gameOverMenu->displayMenu(gameWindow);
        gameWindow.display();
      }
    }
    else
    {
      mainMenu->displayMenu(gameWindow);
      if (!menuMusicIsPlaying)
      {
        sound->menuMusic();
        menuMusicIsPlaying = true;
      }
    }
  }
  delete sound;
  delete mainMenu;
  delete gameOverMenu;
}

void Game::gameOver()
{
  sound->stopGameMusic();
  gameWindow.clear();
  gameOverMenu->displayMenu(gameWindow);
  theGameIsOver = true;
  gameWindow.display();
}

/**
 * A start method that starts the main game loop.
 */
void Game::start()
{
  gameLoop();
}