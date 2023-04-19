#ifndef SECOND_ENEMY_H

#include "SFML/Graphics.hpp"
#include <iostream>

class SecondEnemy
{
  
  private:
    sf::Texture textureOne;
    sf::Texture textureTwo;
    sf::Sprite sprite;
    sf::Clock clock;
    bool isMovingUp = false;
    bool isMovingDown = false;
    float timer;
    float deltaTime;
    int animationStep;

  public:
    SecondEnemy();
    void upEnemyMovement();
    void downEnemyMovement();
    void updateSecondEnemyMovement();
    void secondEnemyAnimation();
    sf::Sprite getSecondEnemySprite() const;
};

#endif