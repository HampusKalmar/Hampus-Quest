#ifndef BACKGROUND_H

#include "SFML/Graphics.hpp"
#include <iostream>

class Background
{
  private:
    sf::Texture texture;
    sf::Sprite backgroundSprite;

  public:
    Background();
    void setBackground(sf::RenderWindow& window, const sf::View &view);
};

#endif