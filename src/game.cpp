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
  Background background;
 
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
      delete sound;
    }

    // Checks if the player has collided with the second enemy.
    if (collision.checkSpriteCollision(player.getSprite(), secondEnemy.getSecondEnemySprite()))
    {
      sf::sleep(sf::seconds(3));
      gameWindow.close();
      delete sound;
    }

    // Checks if the player is touching the ground.
    bool isOnGround = collision.checkSpriteCollisionWithGround(player.getSprite(), environment.getSpriteBlocks());
    if (isOnGround)
    {
      player.resetVelocity();
    }
    else 
    {
      player.fallingVelocity();
    }
    
    // Sets the camera to the player.
    sf::Vector2u windowSize = gameWindow.getSize();
    float viewX = player.getSprite().getPosition().x - windowSize.x / 2.0f;
    float viewY = player.getSprite().getPosition().y - windowSize.y / 2.0f;
    sf::View view(sf::FloatRect(viewX, viewY, windowSize.x, windowSize.y));
    gameWindow.setView(view);
    
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
  delete sound;
}