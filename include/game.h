#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include <iostream>

class Game
{
  private:
    sf::RenderWindow window;
    sf::Event event;
    sf::Color color;

  public:
    void gameWindow();
};

#endif