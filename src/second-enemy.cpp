#include "../include/second-enemy.h"

/**
 * The SecondEnemy constructor. 
 */
SecondEnemy::SecondEnemy()
{
  textureOne.loadFromFile("assets/images/secondEnemy1.png");
  textureTwo.loadFromFile("assets/images/secondEnemy2.png");

  addEnemies({sf::Vector2f(600, 700), sf::Vector2f(1200, 790), sf::Vector2f(1695, 800),  sf::Vector2f(2660, 900), sf::Vector2f(3950, 900), sf::Vector2f(4560, 920), sf::Vector2f(5000, 950)});

  timer = 0.0f;
  animationStep = 0;
}

/**
 * Moves the enemy sprite upwards if its above the specified boundary.
 *
 * @param enemySprite The sprite of the enemy that needs to be moved.
 * @param upBoundary The upper boundary which determines whether the enemy need to be mobved up. 
 */
void SecondEnemy::upEnemyMovement(sf::Sprite& enemySprite, float upBoundary)
{
  if (enemySprite.getPosition().y > upBoundary)
  {
    enemySprite.move(sf::Vector2f(0.f, -1.17f));
  }
}

/**
 * Moves the enemy sprite downwards if its below the specified boundary.
 * 
 * @param enemySprite The sprite of the enemy that needds be moved.
 * @param downBoundary The lower boundary.
 */
void SecondEnemy::downEnemyMovement(sf::Sprite& enemySprite, float downBoundary)
{
  if (enemySprite.getPosition().y < downBoundary)
  {
    enemySprite.move(sf::Vector2f(0.f, 1.17f));
  }
}

/**
 * Updates the movement of the SecondEnemy based on its current position. 
 */
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

/**
 * Animates the SecondEnemy sprites. 
 */
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

/**
 * Adds enemies to the game at the specified positions.
 *
 * @param positions A vector of positions where the enemies should be placed. 
 */
void SecondEnemy::addEnemies(const std::vector<sf::Vector2f>& positions)
{
  for (const auto& pos : positions)
  {
    sf::Sprite sprite;
    sprite.setTexture(textureOne);
    sprite.setScale(1.75f, 1.75f);
    sprite.setPosition(pos);
    sprites.push_back(sprite);

    isEnemyMovingUp.push_back(true);
    initialPos.push_back(pos);
  }
  adjustEnemyPositions();
}

/**
 * Adjusts the enemy sprites to their initial x-position. 
 */
void SecondEnemy::adjustEnemyPositions()
{
  for (size_t i = 0; i < sprites.size(); ++i)
  {
    auto& sprite = sprites[i];
    sprite.setPosition(initialPos[i].x, sprite.getPosition().y);
  }
}

/**
 * Returns the sprites of the SecondEnemy. 
 */
std::vector<sf::Sprite>& SecondEnemy::getSecondEnemySprite()
{
  return sprites;
}