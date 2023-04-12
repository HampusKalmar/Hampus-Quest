#include "../include/player.h"

Player::Player()
{
  texture.loadFromFile("assets/images/hampus.png");
  sprite.setTexture(texture);
  sprite.setPosition(0, 730);
}

void Player::movePlayerRight()
{
  if (input.isRightKeyPressed())
  {
    sprite.move(sf::Vector2f(0.27, 0));
  }
}

void Player::movePlayerLeft()
{
  if (input.isLeftKeyPressed())
  {
    sprite.move(sf::Vector2f(- 0.27, 0));
  }
}

void Player::updatePlayerMovement()
{
  this->movePlayerRight();
  this->movePlayerLeft();
}

sf::Sprite Player::getSprite() const
{
  return sprite;
}