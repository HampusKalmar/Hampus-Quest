#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "../include/input.h"
#include <cmath>

class Player
{
  private:
    sf::Texture textureOne;
    sf::Texture textureTwo;
    sf::Sprite sprite;
    Input input;
    sf::Vector2f velocity;
    sf::Clock clock;
    sf::Time time;
    const float gravity = 9.81f;
    const float downVelocity = 600.0f;
    const float jumpVelocity = -400.0f;
    const float maxJumpHeight = 50.0f;
    const float maxAirTime = 1.5f;
    
    float airTime;
    float deltaTime;
    float timer;
    
    int animationStep;
    
    bool isMovingRight = false;
    bool isMovingLeft = false;
    bool isOnGround = false;
    bool isJumping = false;

  public:
    Player();
    void movePlayerRight();
    void movePlayerLeft();
    void jumpPlayer(float deltaTime);
    void updatePlayerMovement();
    void playerAnimation();
    void resetVelocity();
    void fallingVelocity();
    sf::Sprite getSprite() const;
};

#endif