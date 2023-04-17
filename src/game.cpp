#include "../include/game.h"
#include "../include/sound.h"
#include "../include/player.h"
#include "../include/input.h"
#include "../include/environment.h"
#include "../include/background.h"

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

  Background background(window);

  // Environment environment;

  sf::RenderWindow gameWindow(sf::VideoMode(1400, 900), "Hampus Quest");

  gameWindow.setFramerateLimit(45);
  // environment.drawGround(gameWindow.getSize().x);

  while (gameWindow.isOpen())
  {
    while (gameWindow.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        gameWindow.close();
      }
    }

    //for (const auto& sprite : environment.getTopGround())
    //{
     // gameWindow.draw(sprite);
   // }

    // Sets the camera to the player.
    //sf::Vector2u windowSize = gameWindow.getSize();
    //float viewX = player.getSprite().getPosition().x - windowSize.x / 2.0f;
    //float viewY = player.getSprite().getPosition().y - windowSize.y / 2.0f;
    //sf::View view(sf::FloatRect(viewX, viewY, windowSize.x, windowSize.y));

    gameWindow.clear(sf::Color(0, 0, 70));
    gameWindow.draw(enemy.getEnemySprite());
    gameWindow.draw(player.getSprite());
    player.updatePlayerMovement();
    enemy.updateEnemyMovement();
    background.draw();
    gameWindow.display();
  }
  delete sound;
}