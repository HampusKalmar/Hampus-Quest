#include "../include/enemy.h"

Enemy::Enemy()
{
  textureOne.loadFromFile("assets/images/enemyFirst.png");
  textureTwo.loadFromFile("assets/images/enemySecond.png");
  textureThree.loadFromFile("assets/images/enemyFinal.png");

  addEnemies({sf::Vector2f(200, 748), sf::Vector2f(1406, 808), sf::Vector2f(1950, 768)});

  timer = 0.0f;
  animationStep = 0;
}

void Enemy::leftEnemyMovement(sf::Sprite& enemySprite, float leftBoundary)
{
   if (enemySprite.getPosition().x > leftBoundary)
  {
    enemySprite.move(sf::Vector2f(- 1.17f, 0.f));
  }
}

void Enemy::rightEnemyMovement(sf::Sprite& enemySprite, float rightBoundary)
{
   if (enemySprite.getPosition().x < rightBoundary)
  {
    enemySprite.move(sf::Vector2f(1.17f, 0.f));
  }
}

void Enemy::updateEnemyMovement()
{
  for (size_t i = 0; i < sprites.size(); ++i)
  {
    auto& sprite = sprites[i];
    float leftBoundary = initialPosition[i].x - 100;
    float rightBoundary = initialPosition[i].x + 100;

    if (sprite.getPosition().x <= leftBoundary)
    {
      isEnemyMovingRight[i] = true;
      sprite.setScale(-2.0f, 2.0f); 
    }
    else if (sprite.getPosition().x >= rightBoundary)
    {
      isEnemyMovingRight[i] = false;
      sprite.setScale(2.0f, 2.0f); 
    }

    if (isEnemyMovingRight[i])
    {
      rightEnemyMovement(sprite, rightBoundary);
    }
    else
    {
      leftEnemyMovement(sprite, leftBoundary);
    }
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
      for (auto& enemySprite : sprites)
        enemySprite.setTexture(textureOne);
    }
    else if (animationStep == 1)
    {
      for (auto& enemySprite : sprites)
        enemySprite.setTexture(textureTwo);
    }
    else if (animationStep == 2)
    {
      for (auto& enemySprite : sprites)
        enemySprite.setTexture(textureThree);
    }
  }
}

void Enemy::addEnemies(const std::vector<sf::Vector2f>& positions)
{
  for (const auto& pos : positions)
  {
    sf::Sprite sprite;
    sprite.setTexture(textureOne);
    sprite.setScale(2.0f, 2.0f);
    sprite.setPosition(pos);
    sprites.push_back(sprite);

    isEnemyMovingRight.push_back(true);
    initialPosition.push_back(pos);
  }
}

std::vector<sf::Sprite>& Enemy::getEnemySprites()
{
  return sprites;
}