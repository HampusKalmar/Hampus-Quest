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
  sprite.setPosition(50, 700);

  timer = 0.0f;
  animationStep = 0;
  sprite.move(sf::Vector2f(0, 9.81f));
}

void Player::resetPlayer()
{
  sprite.setPosition(50, 700);
}

/**
 * Method to make the player be able to jump.
 */
void Player::jumpPlayer(float deltaTime)
{
  if (input.isUpKeyPressed())
  {
    if (!isJumping)
    {
      isJumping = true;
      initialJumpHeight = sprite.getPosition().y;
      velocity.y = jumpVelocity;
      airTime = 0.0f;
    }
    else if (airTime < maxAirTime)
    {
      velocity.y -= gravity * deltaTime;
    }
  }

  if (isJumping)
  {
    // float descendingGravityDelta = gravity * 0.3f;
    // velocity.y += (velocity.y >= 0.0f) ? -descendingGravityDelta : gravity * deltaTime;
    airTime += deltaTime;
    sprite.move(0, velocity.y * deltaTime);
  
    if (sprite.getPosition().y >= initialJumpHeight)
    {
      isJumping = false;
      isFalling = true;
      velocity.y = 0.0f;
      airTime = 0.0f;
    }
  }

  if (velocity.y > 0.0f && !isFalling)
  {
    isFalling = true;
  }
  else
  {
    isFalling = false;
  }
  sprite.move(velocity * deltaTime);
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

void Player::resetVelocity()
{
  velocity.y = 0.0f;
}

void Player::fallingVelocity()
{
  velocity.y += gravity * deltaTime + 22.0f;
}

void Player::setInitialJumpHeight(float y)
{
  initialJumpHeight = y;
}

/**
 * Returns a copy of the sprite associated with the player object.
 */
sf::Sprite Player::getSprite() const
{
  return sprite;
}