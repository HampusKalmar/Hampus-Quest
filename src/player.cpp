#include "../include/player.h"

Player::Player()
{
  textureOne.loadFromFile("assets/images/newSpriteOne.png");
  textureTwo.loadFromFile("assets/images/newSpriteTwo.png");
  sprite.setTexture(textureOne);
  sprite.setPosition(0, 730);

  timer = 0.0f;
  animationStep = 0;
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
    sprite.move(sf::Vector2f(5.20f, 0.f));
  }
}

void Player::movePlayerLeft()
{
  if (input.isLeftKeyPressed())
  {
    sprite.move(sf::Vector2f(-5.20f, 0.f));
    // check deltaTime here and in movePlayerRight()!!!!!!!!
  }
}

void Player::updatePlayerMovement()
{
  time = clock.restart();
  this->movePlayerRight();
  this->movePlayerLeft();
  this->jumpPlayer(time.asSeconds());
}

void Player::playerAnimation()
{
  deltaTime = clock.restart().asSeconds();
  timer += deltaTime;
  if (timer >= 0.30f)
  {
    timer -= 0.30f;
    if (!isMovingRight || isMovingLeft)
    {
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
    else
    {
      animationStep = 0;
      sprite.setTexture(textureOne);
    }
  }
  if (isMovingLeft)
  {
    sprite.setScale(- 1.f, 1.f);
  }
  else
  {
    sprite.setScale(1.f, 1.f);
  }
}


sf::Sprite Player::getSprite() const
{
  return sprite;
}