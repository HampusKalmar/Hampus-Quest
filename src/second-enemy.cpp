#include "../include/second-enemy.h"

SecondEnemy::SecondEnemy()
{
  textureOne.loadFromFile("assets/images/secondEnemy1.png");
  textureTwo.loadFromFile("assets/images/secondEnemy2.png");

  sprite.setTexture(textureOne);
  sprite.setScale(1.7f, 1.7f);
  sprite.setPosition(600, 700);

  timer = 0.0f;
  animationStep = 0;
}

void SecondEnemy::upEnemyMovement()
{
  if (sprite.getPosition().y > 400.0f)
  {
    sprite.move(sf::Vector2f(0.0f, -2.2f));
  }
}

void SecondEnemy::downEnemyMovement()
{
   if (sprite.getPosition().y < 660.0f)
  {
    sprite.move(sf::Vector2f(0.0f, 2.2f));
  }
}

void SecondEnemy::updateSecondEnemyMovement()
{
    if (sprite.getPosition().y <= 400.0f)
  {
    isMovingUp = false;
  }
  else if (sprite.getPosition().y >= 660.0f)
  {
    isMovingUp = true;
  }

  if (isMovingUp)
  {
    upEnemyMovement();
  }
  else
  {
    downEnemyMovement();
  }
}

sf::Sprite SecondEnemy::getSecondEnemySprite() const
{
  return sprite;
}