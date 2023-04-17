#ifndef ENEMY_H

#include "SFML/Graphics.hpp"
#include <iostream>

class Enemy
{
  
  private:
    sf::Texture textureOne;
    sf::Texture textureTwo;
    sf::Texture textureThree;
    sf::Sprite sprite;
    sf::Clock clock;
    bool isMovingRight = false;
    float timer;
    float deltaTime;
    int animationStep;

  public:
    Enemy();
    void leftEnemyMovement();
    void rightEnemyMovement();
    void updateEnemyMovement();
    void enemyAnimation();
    sf::Sprite getEnemySprite() const;
};

#endif