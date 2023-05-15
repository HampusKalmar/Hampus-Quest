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
   if (sprite.getPosition().y < 700.0f)
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
  else if (sprite.getPosition().y >= 700.0f)
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

void SecondEnemy::secondEnemyAnimation()
{
  deltaTime = clock.restart().asSeconds();
  timer += deltaTime;
  if (timer >= 0.22f)
  {
    timer -= 0.22f;
    animationStep = (animationStep + 1) % 2;
    if (animationStep == 0)
    {
      sprite.setTexture(textureOne);
    }
    else if (animationStep == 1)
    {
      sprite.setTexture(textureTwo);
    }
  }
}

sf::Sprite SecondEnemy::getSecondEnemySprite() const
{
  return sprite;
}