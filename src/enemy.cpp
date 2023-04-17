#include "../include/enemy.h"

Enemy::Enemy()
{
  textureOne.loadFromFile("assets/images/enemySpriteOne.png");
  textureTwo.loadFromFile("assets/images/enemySpriteTwo.png");
  textureThree.loadFromFile("assets/images/enemySpriteThree.png");

  sprite.setTexture(textureOne);
  sprite.setPosition(200, 750);
}

void Enemy::leftEnemyMovement()
{
  if (sprite.getPosition().x > 100)
  {
    sprite.move(sf::Vector2f(- 1.f, 0.f));
  }
}

void Enemy::rightEnemyMovement()
{
  if (sprite.getPosition().x < 400)
  {
    sprite.move(sf::Vector2f(1.f, 0.f));
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
    sprite.setScale(- 1.f, 1.f);
    //sprite.setOrigin(sprite.getLocalBounds().width / 1.f, sprite.getLocalBounds().height / 1.f);
    rightEnemyMovement();
  }
  else
  {
    sprite.setScale(1.f, 1.f);
    leftEnemyMovement();
  }
}

sf::Sprite Enemy::getEnemySprite() const
{
  return sprite;
}