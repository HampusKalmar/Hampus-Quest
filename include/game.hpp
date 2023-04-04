#ifndef GAME_HPP
#define GAME_HPP

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