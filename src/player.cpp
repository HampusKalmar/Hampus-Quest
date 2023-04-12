#include "../include/player.h"

void Player::printPlayerSprite()
{
  texture.loadFromFile("assets/images/hampus.png");

  sprite.setTexture(texture);
  sprite.setPosition(0, 730);
}

void Player::jumpPlayer()
{
  if (input.isUpKeyPressed())
  {
    if (!isJumping)
    {
      isJumping = true;
      velocity.y = jumpVelocity;
       airTime = 0.0f;
    }
    else if (isJumping && velocity.y < 0.0f && airTime < maxAirTime)
    {
      velocity.y -= gravity * deltaTime;
    }
  }
    if (isJumping)
    {
      velocity.y += gravity * deltaTime;
      airTime += deltaTime;
    
      if (airTime > maxAirTime || (velocity.y > 0 && sprite.getPosition().y >= 730.0f))
      {
        isJumping = false;
        velocity.y = downVelocity;
      }
    }
    sprite.move(velocity * deltaTime);
}

sf::Sprite Player::getSprite() const
{
  return sprite;
}