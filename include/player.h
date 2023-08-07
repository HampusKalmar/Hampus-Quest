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
    const float maxAirTime = 1.0f;
    
    float airTime;
    float deltaTime;
    float timer;
    float initialJumpHeight;
    
    int animationStep;
    
    bool isMovingRight = false;
    bool isMovingLeft = false;
    bool isOnGround = false;
    bool isJumping = false;
    bool isFalling = false;

    float spawnPointX;
    float spawnPointY;

  public:
    Player();
    void movePlayerRight();
    void movePlayerLeft();
    void jumpPlayer(float deltaTime);
    void updatePlayerMovement();
    void playerAnimation();
    void resetVelocity();
    void fallingVelocity();
    void setOnGround(bool onGround);
    bool getOnGround() const;
    void resetPlayer(float x, float y);
    void setInitialJumpHeight(float y);
    void setSpawnPoint(float x, float y) { spawnPointX = x; spawnPointY = y; }
    sf::Sprite getSprite() const;
};

#endif