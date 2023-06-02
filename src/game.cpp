#include "../include/game.h"

/**
 * The Game constructor initializes the game window and sets the framerate limit.
 */
Game::Game() :
  gameWindow(sf::VideoMode(1000, 900), "Hampus Quest", sf::Style::Close | sf::Style::Titlebar)
{
  gameWindow.setFramerateLimit(30);
  if (!trophyTexture.loadFromFile("assets/images/trophy.png"))
  {
    std::cout << "Could not load the trophy texture" << std::endl;
  }
  trophySprite.setTexture(trophyTexture);
  trophySprite.setScale(1.5f, 1.5f);
  trophySprite.setPosition(993, 747);
}

/**
 * The Game destructor frees the memory allocated to the Sound, the MainMenu and the GameOverMenu objects.
 */
Game::~Game()
{
  delete sound;
  delete mainMenu;
  delete gameOverMenu;
}

/**
 * Sets the view of the game window to the player.
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
  gameWindow.draw(getTrophySprite());
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
    theGameIsOver = true;
  }

  if (collision.checkSpriteCollision(player.getSprite(), secondEnemy.getSecondEnemySprite()))
  {
    sound->stopGameMusic();
    theGameIsOver = true;
  }

  float fallingThreshold = 950.0f;

  if (player.getSprite().getPosition().y > fallingThreshold)
  {
    sound->stopGameMusic();
    theGameIsOver = true;
  }

  if (collision.checkSpriteCollision(player.getSprite(), trophySprite))
  {
    gameWon();
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
    gameOverMenu->handleGameOverMenuEvent(event);
  
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
      gameStarted = false;
      gameWindow.close();
    }
    else if (mainMenu->isPlayPressed())
    {
      gameStarted = true;
      sound->stopMenuMusic();
      sound->gameMusic();
    }

    if (gameOverMenu->isExitTheGamePressed())
    {
      gameStarted = false;
      gameWindow.close();
    }

    if (gameStarted)
    {
      if (!theGameIsOver)
      {
        gameCollision();
        setCamera();
        drawGameObjects();
      }

      if (!theGameIsOver)
      {
        if (!inGameMusicIsPlaying)
        {
          sound->gameMusic();
          inGameMusicIsPlaying = true;
        }
      }
      else
      {
        gameWindow.clear();
        gameOverMenu->displayMenu(gameWindow, player.getSprite());
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
}

/**
 * A method that creates a text showing the player has won the game.
 */
void Game::gameWon()
{
  sound->stopGameMusic();
  gameWindow.clear();

  if (!font.loadFromFile("assets/fonts/slkscre.ttf"))
  {
    std::cout << "Could not load the font" << std::endl;
  }

  congratulationsText.setFont(font);
  congratulationsText.setString("Congratulations! You have won the game");
  congratulationsText.setCharacterSize(20);
  congratulationsText.setFillColor(sf::Color::White);
  congratulationsText.setPosition(700, 400);

  gameWindow.draw(congratulationsText);
  gameWindow.display();

  sf::sleep(sf::seconds(3));
  gameWindow.close();
}

sf::Sprite Game::getTrophySprite()
{
  return trophySprite;
}

/**
 * A start method that starts the main game loop and will be called in main.
 */
void Game::start()
{
  gameLoop();
}