#include "../include/second-enemy.h"

SecondEnemy::SecondEnemy()
{
  textureOne.loadFromFile("assets/images/secondEnemy1.png");
  textureTwo.loadFromFile("assets/images/secondEnemy2.png");

  addEnemies({sf::Vector2f(600, 700), sf::Vector2f(800, 800), sf::Vector2f(1000, 800)});

  timer = 0.0f;
  animationStep = 0;
}

void SecondEnemy::upEnemyMovement(sf::Sprite& enemySprite, float upBoundary)
{
  if (enemySprite.getPosition().y > upBoundary)
  {
    enemySprite.move(sf::Vector2f(0.f, -1.17f));
  }
}

void SecondEnemy::downEnemyMovement(sf::Sprite& enemySprite, float downBoundary)
{
  if (enemySprite.getPosition().y < downBoundary)
  {
    enemySprite.move(sf::Vector2f(0.f, 1.17f));
  }
}

void SecondEnemy::updateSecondEnemyMovement()
{
  for (size_t i = 0; i < sprites.size(); ++i)
  {
    auto& sprite = sprites[i];
    float upBoundary = initialPos[i].y - 180;
    float downBoundary = initialPos[i].y + 50;

    if (sprite.getPosition().y <= upBoundary)
    {
      isEnemyMovingUp[i] = false;
    }
    else if (sprite.getPosition().y >= downBoundary)
    {
      isEnemyMovingUp[i] = true;
    }

    if (isEnemyMovingUp[i])
    {
      upEnemyMovement(sprite, upBoundary);
    }
    else
    {
      downEnemyMovement(sprite, downBoundary);
    }
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

    for (auto& sprite : sprites)
    {
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
}

void SecondEnemy::addEnemies(const std::vector<sf::Vector2f>& positions)
{
  for (const auto& pos : positions)
  {
    sf::Sprite sprite;
    sprite.setTexture(textureOne);
    sprite.setScale(2.0f, 2.0f);
    sprite.setPosition(pos);
    sprites.push_back(sprite);

    isEnemyMovingUp.push_back(true);
    initialPos.push_back(pos);
  }
}

std::vector<sf::Sprite>& SecondEnemy::getSecondEnemySprite()
{
  return sprites;
}