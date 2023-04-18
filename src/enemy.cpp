#include "../include/enemy.h"

Enemy::Enemy()
{
  textureOne.loadFromFile("assets/images/enemyFirst.png");
  textureTwo.loadFromFile("assets/images/enemySecond.png");
  textureThree.loadFromFile("assets/images/enemyFinal.png");

  sprite.setTexture(textureOne);
  sprite.setPosition(200, 770);

  timer = 0.0f;
  animationStep = 0;
}

void Enemy::leftEnemyMovement()
{
  if (sprite.getPosition().x > 100)
  {
    sprite.move(sf::Vector2f(- 1.17f, 0.f));
  }
}

void Enemy::rightEnemyMovement()
{
  if (sprite.getPosition().x < 400)
  {
    sprite.move(sf::Vector2f(1.17f, 0.f));
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

void Enemy::enemyAnimation()
{
  deltaTime = clock.restart().asSeconds();
  timer += deltaTime;
  if (timer >= 0.22f)
  {
    timer -= 0.22f;
    animationStep = (animationStep + 1) % 3;
    if (animationStep == 0)
    {
      sprite.setTexture(textureOne);
    }
    else if (animationStep == 1)
    {
      sprite.setTexture(textureTwo);
    }
    else if (animationStep == 2)
    {
      sprite.setTexture(textureThree);
    }
  }
}

sf::Sprite Enemy::getEnemySprite() const
{
  return sprite;
}