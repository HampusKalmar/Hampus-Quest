#include "../include/player.h"

Player::Player()
{
  texture.loadFromFile("assets/images/hampus.png");
  sprite.setTexture(texture);
  sprite.setPosition(0, 730);
}

// Make the player jump.
void Player::jumpPlayer(float deltaTime)
{
  float gravityDelta = gravity * deltaTime;

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
      velocity.y -= gravityDelta;
    }
  }
  
  if (isJumping)
  {
    velocity.y += gravityDelta;
    airTime += deltaTime;
    
    if (airTime > maxAirTime || (velocity.y > 0 && sprite.getPosition().y >= 730.0f))
    {
      isJumping = false;
      velocity.y = downVelocity;
    }
  }
  sprite.move(velocity * deltaTime);

  if (sprite.getPosition().y >= 730.0f)
  {
    sprite.setPosition(sprite.getPosition().x, 730.0f);
    isJumping = false;
    velocity.y = 0.0f;
  }

  if (isJumping && sprite.getPosition().y <= 730.0f - maxJumpHeight)
  {
    isJumping = false;
    velocity.y = downVelocity;
    airTime = downVelocity;
  }
}

void Player::movePlayerRight()
{
  if (input.isRightKeyPressed())
  {
    sprite.move(sf::Vector2f(2.50, 0));
  }
}

void Player::movePlayerLeft()
{
  if (input.isLeftKeyPressed())
  {
    sprite.move(sf::Vector2f(-2.50, 0));
  }
}

void Player::updatePlayerMovement()
{
  time = clock.restart();
  this->movePlayerRight();
  this->movePlayerLeft();
  this->jumpPlayer(time.asSeconds());
}

sf::Sprite Player::getSprite() const
{
  return sprite;
}