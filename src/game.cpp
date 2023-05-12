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
  gameWindow.clear();
  background.backgroundColor(gameWindow, sf::Color(0, 0, 70), sf::Color::Black);
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
    sf::sleep(sf::seconds(3));
    gameWindow.close();
    //delete sound;
  }

  if (collision.checkSpriteCollision(player.getSprite(), secondEnemy.getSecondEnemySprite()))
  {
    sound->stopGameMusic();
    sf::sleep(sf::seconds(3));
    gameWindow.close();
    //delete sound;
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
  bool gameStarted = false;
  bool menuMusicIsPlaying = false;
  bool inGameMusicIsPlaying = false;

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
      gameCollision();
      setCamera();
      drawGameObjects();
      inGameMusicIsPlaying = true;
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
  delete mainMenu;
  delete sound;
}

/**
 * A start method that starts the main game loop.
 */
void Game::start()
{
  gameLoop();
}