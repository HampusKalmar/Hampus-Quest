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
  trophySprite.setScale(2.0f, 2.0f);
  trophySprite.setPosition(5000, 972);
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
  view = gameWindow.getView();
  background.setBackground(gameWindow, view);
  environment.drawGround(gameWindow);
  environment.drawStones(gameWindow);
  for (const auto& sprite : enemy.getEnemySprites())
  {
    gameWindow.draw(sprite);
  }

  for (const auto& sprite : secondEnemy.getSecondEnemySprite())
  {
    gameWindow.draw(sprite);
  }
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
  for (const auto& sprite : enemy.getEnemySprites())
  {
    if (collision.checkSpriteCollision(player.getSprite(), sprite))
    {
      sound->stopGameMusic();
      theGameIsOver = true;
    }
  }

  for (const auto& sprite : secondEnemy.getSecondEnemySprite())
  {
    if (collision.checkSpriteCollision(player.getSprite(), sprite))
    {
      sound->stopGameMusic();
      theGameIsOver = true;
    }
  }
 

  float fallingThreshold = 1200.0f;

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
    if (theGameIsOver) {
      gameOverMenu->handleGameOverMenuEvent(event);
    } else {
      mainMenu->handleEvent(event);
    }
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
  bool isGameOverMenuActive = false;

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

    if (gameStarted)
    {
      if (!theGameIsOver)
      {
        gameCollision();
        setCamera();
        drawGameObjects();
      }
      else
      {
        isGameOverMenuActive = true;
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

    if (isGameOverMenuActive)
    {
      gameWindow.clear();
      gameOverMenu->displayMenu(gameWindow, player.getSprite());
      gameWindow.display();

      if (gameOverMenu->isRestartGamePressed())
      {
        resetGame();
        drawGameObjects();
        sound->gameMusic();
        isGameOverMenuActive = false;
        gameStarted = true;
        theGameIsOver = false;
      }

      if (gameOverMenu->isExitTheGamePressed())
      {
        gameStarted = false;
        gameWindow.close();
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

  sf::Vector2f center = gameWindow.getView().getCenter();

  sf::FloatRect textRect = congratulationsText.getLocalBounds();
  congratulationsText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
  congratulationsText.setPosition(center);

  gameWindow.draw(congratulationsText);
  gameWindow.display();

  sf::sleep(sf::seconds(3));
  gameWindow.close();
}

sf::Sprite Game::getTrophySprite()
{
  return trophySprite;
}

void Game::resetGame()
{
  player.resetPlayer();
}

/**
 * A start method that starts the main game loop and will be called in main.
 */
void Game::start()
{
  gameLoop();
}