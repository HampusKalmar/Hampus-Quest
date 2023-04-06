#include "../include/game.h"
#include "../include/sound.h"

void Game::gameWindow()
{
  Sound gameMusic;
  gameMusic.menuMusic();

  sf::RenderWindow gameWindow(sf::VideoMode(1400, 900), "Hampus Quest");

  window.setFramerateLimit(30);

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
    gameWindow.display();
  }
}