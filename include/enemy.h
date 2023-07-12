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
    std::vector<sf::Sprite> sprites;
    std::vector<bool> isEnemyMovingRight;
    std::vector<sf::Vector2f> initialPosition;
    sf::Clock clock; 
    bool isMovingRight = false;
    float timer;
    float deltaTime;
    int animationStep;

  public:
    Enemy();
    void leftEnemyMovement(sf::Sprite& enemySprite, float leftBoundary);
    void rightEnemyMovement(sf::Sprite& enemySprite, float rightBoundary);
    void updateEnemyMovement();
    void enemyAnimation();
    void addEnemies(const std::vector<sf::Vector2f>& positions);
    std::vector<sf::Sprite>& getEnemySprites();
};

#endif