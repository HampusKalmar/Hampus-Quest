#include "../include/collision.h"

bool Collision::checkSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2)
{
  sf::FloatRect rect1 = sprite1.getGlobalBounds();
  sf::FloatRect rect2 = sprite2.getGlobalBounds();

  return rect1.intersects(rect2);
}