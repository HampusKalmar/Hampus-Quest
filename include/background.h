#ifndef BACKGROUND_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Background
{
  private:
    sf::Texture texture;
    sf::Sprite backgroundSprite;
    sf::Sprite sprite;

  public:
    Background();
    void setBackground(sf::RenderWindow& window, const sf::View &view);
};

#endif