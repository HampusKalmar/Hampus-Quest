#include "../include/game.h"
#include "../include/sound.h"
#include "../include/player.h"
#include "../include/input.h"
#include "../include/environment.h"
#include "../include/background.h"
#include "../include/enemy.h"
#include "../include/collision.h"
#include "../include/second-enemy.h"

/**
 * The gameWindow method initializes and manages the game window, handles user input events,
 * and displays the player sprite in the game window.
 */
void Game::gameWindow()
{
  Sound* sound = new Sound();
  sound->menuMusic();

  Player player;
  Enemy enemy;
  Environment environment;
  Collision collision;
  SecondEnemy secondEnemy;
  //Background Background(window);
 
  sf::RenderWindow gameWindow(sf::VideoMode(1000, 900), "Hampus Quest", sf::Style::Close | sf::Style::Titlebar);

  gameWindow.setFramerateLimit(30);

  while (gameWindow.isOpen())
  {
    while (gameWindow.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        gameWindow.close();
      }
    }

    // Checks if the player has collided with the enemy.
    if (collision.checkSpriteCollision(player.getSprite(), enemy.getEnemySprite()))
    {
      sf::sleep(sf::seconds(3));
      gameWindow.close();
    }

    if (collision.checkSpriteCollision(player.getSprite(), environment.getSpriteBlocks()))
    {
      std::cout << "collision detected" << std::endl;
    }

    // Sets the camera to the player.
    sf::Vector2u windowSize = gameWindow.getSize();
    float viewX = player.getSprite().getPosition().x - windowSize.x / 2.0f;
    float viewY = player.getSprite().getPosition().y - windowSize.y / 2.0f;
    sf::View view(sf::FloatRect(viewX, viewY, windowSize.x, windowSize.y));
    gameWindow.setView(view);
    gameWindow.clear(sf::Color(0, 0, 70));
    gameWindow.draw(enemy.getEnemySprite());
    gameWindow.draw(secondEnemy.getSecondEnemySprite());
    gameWindow.draw(player.getSprite());
    environment.drawGround(gameWindow);
    player.playerAnimation();
    player.updatePlayerMovement();
    enemy.enemyAnimation();
    enemy.updateEnemyMovement();
    secondEnemy.updateSecondEnemyMovement();
    //background.draw();
    gameWindow.display();
  }
  delete sound;
}