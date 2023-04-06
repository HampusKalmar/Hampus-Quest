#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include <iostream>

class Player
{
  private:
    sf::Texture texture;
    sf::Sprite sprite;

  public:
    void printPlayerSprite();
    sf::Sprite getSprite() const;
};

#endif