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

  isOnGround = false;
  timer = 0.0f;
  animationStep = 0;
  sprite.move(sf::Vector2f(0, 9.81f));
}

void Player::resetPlayer(float x, float y)
{
  sprite.setPosition(x, y);
  resetVelocity();
  isJumping = false;
  isFalling = false;
}

/**
 * Method to make the player be able to jump.
 *
 * @param deltaTime The time since the last frame update.
 */
void Player::jumpPlayer(float deltaTime)
{
  if (input.isUpKeyPressed() && isOnGround)
  {
    if (!isJumping)
    {
      isJumping = true;
      initialJumpHeight = sprite.getPosition().y;
      velocity.y = jumpVelocity;
      airTime = 0.0f;
      isOnGround = false;
    }
    else if (airTime < maxAirTime)
    {
      velocity.y -= gravity * deltaTime;
    }
  }

  if (isJumping)
  {
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
 * Resets the vertical velocity of the player.
 */
void Player::resetVelocity()
{
  velocity.y = 0.0f;
}

/**
 * Modifies the players vertical velocity to simulate falling.
 */
void Player::fallingVelocity()
{
  velocity.y += gravity * deltaTime + 22.0f;
}

/**
 * Sets the initial jump height for the player.
 *
 * @param y The initial height value to set for the jump.
 */
void Player::setInitialJumpHeight(float y)
{
  initialJumpHeight = y;
}

/**
 * Sets the on-ground status of the player.
 *
 * @param onGround A boolean value indicating if the player is standing on the ground or not.
 */
void Player::setOnGround(bool onGround)
{
  isOnGround = onGround;
}

/**
 * Returns the on-ground status of the player.
 *
 * @return Returns true if the player is on the ground, otherwise false.
 */
bool Player::getOnGround() const 
{
  return isOnGround;
}

/**
 * Returns a copy of the sprite associated with the player object.
 *
 * @return A copy of the player sprite. 
 */
sf::Sprite Player::getSprite() const
{
  return sprite;
}