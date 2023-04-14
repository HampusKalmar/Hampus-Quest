#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "SFML/Graphics.hpp"
#include <iostream>

class Background
{
  private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RenderWindow& window;

  public:
    Background(sf::RenderWindow& window);
    void draw();
};

#endif