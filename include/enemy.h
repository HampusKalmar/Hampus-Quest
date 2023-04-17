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
    bool isMovingRight = false;

  public:
    Enemy();
    void leftEnemyMovement();
    void rightEnemyMovement();
    void updateEnemyMovement();
    sf::Sprite getEnemySprite() const;
};

#endif