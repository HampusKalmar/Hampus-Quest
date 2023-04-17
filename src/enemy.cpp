#include "../include/enemy.h"

Enemy::Enemy()
{
  textureOne.loadFromFile("assets/images/enemySpriteOne.png");
  textureTwo.loadFromFile("assets/images/enemySpriteTwo.png");
  textureThree.loadFromFile("assets/images/enemySpriteThree.png");

  sprite.setTexture(textureOne);
  sprite.setPosition(200, 730);
}

void Enemy::leftEnemyMovement()
{
  if (sprite.getPosition().x > 100)
  {
    sprite.move(sf::Vector2f(- 1.f, 0.f));
    std::cout << "Enemy moved left" << std::endl;
  }
}

void Enemy::rightEnemyMovement()
{
  if (sprite.getPosition().x < 400)
  {
    sprite.move(sf::Vector2f(1.f, 0.f));
    std::cout << "Enemy moved right" << std::endl;
  }
}

void Enemy::updateEnemyMovement()
{
  if (sprite.getPosition().x <= 100)
  {
    isMovingRight = true;
  }
  else if (sprite.getPosition().x >= 400)
  {
    isMovingRight = false;
  }

  if (isMovingRight)
  {
    rightEnemyMovement();
  }
  else
  {
    leftEnemyMovement();
  }
}

sf::Sprite Enemy::getEnemySprite() const
{
  return sprite;
}