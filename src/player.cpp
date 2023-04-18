#include "../include/player.h"

/**
 * Player class contructor.
 */
Player::Player()
{
  textureOne.loadFromFile("assets/images/newSpriteOne.png");
  textureTwo.loadFromFile("assets/images/newSpriteTwo.png");
  sprite.setTexture(textureOne);
  sprite.setScale(2.0f, 2.0f);
  sprite.setPosition(0, 708);

  timer = 0.0f;
  animationStep = 0;
}

/**
 * Method to make the player be able to jump.
 */
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

/**
 * Makes the player move right.
 */
void Player::movePlayerRight()
{
  if (input.isRightKeyPressed())
  {
    sprite.move(sf::Vector2f(5.20f, 0.f));
    sprite.setScale(2.0f, 2.0f);
  }
}

/**
 * Makes the player move left.
 */
void Player::movePlayerLeft()
{
  if (input.isLeftKeyPressed())
  {
    sprite.move(sf::Vector2f(-5.20f, 0.f));
    sprite.setScale(- 2.0f, 2.0f);
    // check deltaTime here and in movePlayerRight()!!!!!!!!
  }
}

/**
 * Method to be called inside the main game loop.
 */
void Player::updatePlayerMovement()
{
  this->movePlayerRight();
  this->movePlayerLeft();
  this->jumpPlayer(deltaTime);
}

/**
 * Creates the animation for the player.
 */
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

/**
 * Returns a copy of the sprite associated with the player object.
 */
sf::Sprite Player::getSprite() const
{
  return sprite;
}