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
    std::vector<sf::Sprite> sprites;
    std::vector<bool> isEnemyMovingUp;
    std::vector<sf::Vector2f> initialPos;
    bool isMovingUp = false;
    bool isMovingDown = false;
    float timer;
    float deltaTime;
    int animationStep;

  public:
    SecondEnemy();
    void upEnemyMovement(sf::Sprite& enemySprite, float upBoundary);
    void downEnemyMovement(sf::Sprite& enemySprite, float downBoundary);
    void updateSecondEnemyMovement();
    void secondEnemyAnimation();
    void addEnemies(const std::vector<sf::Vector2f>& positions);
    std::vector<sf::Sprite>& getSecondEnemySprite();
};

#endif