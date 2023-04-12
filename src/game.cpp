#include "../include/game.h"
#include "../include/sound.h"
#include "../include/player.h"
#include "../include/input.h"

/**
 * The gameWindow method initializes and manages the game window, handles user input events,
 * and displays the player sprite in the game window.
*/
void Game::gameWindow()
{
  Sound* sound = new Sound();
  sound->menuMusic();

  Player player;

  sf::RenderWindow gameWindow(sf::VideoMode(1400, 900), "Hampus Quest");

  window.setFramerateLimit(20);

  while (gameWindow.isOpen())
  {
    while (gameWindow.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        gameWindow.close();
      }
    }
    gameWindow.clear(sf::Color(0, 0, 70));
    player.updatePlayerMovement();
    gameWindow.draw(player.getSprite());
    gameWindow.display();
  }
  delete sound;
}