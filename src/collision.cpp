#include "../include/collision.h"

/**
 * A method to see if the player intersects with an enemy sprite. 
 */
bool Collision::checkSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2)
{
  sf::FloatRect rect1 = sprite1.getGlobalBounds();
  sf::FloatRect rect2 = sprite2.getGlobalBounds();

  return rect1.intersects(rect2);
}

/**
 * A method that checks if the player sprite intersects with the ground sprites. 
 */
bool Collision::checkSpriteCollisionWithGround(sf::Sprite playerSprite, std::vector<sf::Sprite> groundSprites)
{
  sf::FloatRect rect1 = playerSprite.getGlobalBounds();
  for (const auto& groundSprite : groundSprites)
  {
    sf::FloatRect rect2 = groundSprite.getGlobalBounds();

    if (rect1.intersects(rect2))
    {
      return true;
    }
  }
  return false;
}