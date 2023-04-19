#ifndef BACKGROUND_H

#include "SFML/Graphics.hpp"
#include <iostream>

class Background
{
  private:
    sf::Texture texture;
    sf::Sprite sprite;

  public:
    void backgroundColor(sf::RenderTarget& target, const sf::Color& topColor, const sf::Color& bottomColor);
};

#endif