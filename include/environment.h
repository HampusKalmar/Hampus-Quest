#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include <cmath>

class Environment
{
  private:
    sf::Texture texture;
    sf::Sprite topGround;
    sf::Sprite bottomGround;
    std::vector<sf::Sprite> topGroundSprites;
    std::vector<sf::Sprite> bottomGroundSprite;

  public:
    Environment();
    void drawGround(float windowWidth);
    std::vector<sf::Sprite> getTopGround() const;
};

#endif