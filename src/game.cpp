#include "../include/game.hpp"

void Game::gameWindow()
{
  sf::RenderWindow gameWindow(sf::VideoMode(1400, 900), "Hampus Quest");

  window.setFramerateLimit(25);

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