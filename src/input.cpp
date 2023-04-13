#include "../include/input.h"

bool Input::isUpKeyPressed()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    return true;
  }
  return false;
}

bool Input::isRightKeyPressed()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    return true;
  }
  return false;
}

bool Input::isLeftKeyPressed()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    return true;
  }
  return false;
}
