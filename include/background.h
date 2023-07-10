#ifndef BACKGROUND_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Background
{
  private:
    sf::Texture textureOne;
    sf::Texture textureTwo;
    sf::Texture texturePlain;
    sf::Sprite backgroundSpriteOne;
    sf::Sprite backgroundSpriteTwo;
    sf::Sprite backgroundSpritePlain;
    sf::Sprite sprite;

  public:
    Background();
    void setBackground(sf::RenderWindow& window, const sf::View &view);
};

#endif