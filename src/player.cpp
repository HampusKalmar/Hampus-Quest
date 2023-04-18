#include "../include/player.h"

Player::Player()
{
  textureOne.loadFromFile("assets/images/newSpriteOne.png");
  textureTwo.loadFromFile("assets/images/newSpriteTwo.png");
  sprite.setTexture(textureOne);
  sprite.setPosition(0, 800);

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
    sprite.setScale(1.f, 1.f);
  }
}

void Player::movePlayerLeft()
{
  if (input.isLeftKeyPressed())
  {
    sprite.move(sf::Vector2f(-5.20f, 0.f));
    sprite.setScale(- 1.f, 1.f);
    // check deltaTime here and in movePlayerRight()!!!!!!!!
  }
}

void Player::updatePlayerMovement()
{
  this->movePlayerRight();
  this->movePlayerLeft();
  this->jumpPlayer(deltaTime);
}

void Player::playerAnimation()
{
  deltaTime = clock.restart().asSeconds();
  isMovingRight = input.isRightKeyPressed();
  isMovingLeft = input.isLeftKeyPressed();

  if (isMovingRight)
  {
    timer += deltaTime;
    if (timer >= 0.23f)
    {
      timer -= 0.23f;
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
  else if (isMovingLeft)
  {
    timer += deltaTime;
    if (timer >= 0.23f)
    {
      timer -= 0.23f;
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
}


sf::Sprite Player::getSprite() const
{
  return sprite;
}