#include "../include/player.h"

void Player::printPlayerSprite()
{
  texture.loadFromFile("assets/images/hampus.png");

  sprite.setTexture(texture);
  sprite.setPosition(0, 730);
}

sf::Sprite Player::getSprite() const
{
  return sprite;
}