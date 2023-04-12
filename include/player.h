#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "../include/input.h"

class Player
{
  private:
    sf::Texture texture;
    sf::Sprite sprite;
    Input input;
    sf::Vector2f velocity;
    const float gravity = 9.81f;
    const float downVelocity = 600.0f;
    const float jumpVelocity = -600.0f;
    const float maxJumpHeight = 150.0f;
    const float maxAirTime = 2.2f;
    float airTime;
    bool isJumping = false;

  public:
    void printPlayerSprite();
    void jumpPlayer(float deltaTime);
    sf::Sprite getSprite() const;
};

#endif