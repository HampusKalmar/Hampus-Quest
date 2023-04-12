#include "../include/game.h"
#include "../include/sound.h"
#include "../include/player.h"

void Game::gameWindow()
{
  Sound* sound = new Sound();
  sound->menuMusic();

  Player player;
  player.printPlayerSprite();

  sf::RenderWindow gameWindow(sf::VideoMode(1400, 900), "Hampus Quest");

  window.setFramerateLimit(30);

  sf::Clock clock;
  while (gameWindow.isOpen())
  {
    sf::Time deltaTime = clock.restart();
    while (gameWindow.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        gameWindow.close();
      }
    }
    gameWindow.clear(sf::Color(0, 0, 70));
    player.jumpPlayer(deltaTime.asSeconds());
    gameWindow.draw(player.getSprite());
    gameWindow.display();
  }
  delete sound;
}