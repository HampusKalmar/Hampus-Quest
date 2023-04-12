#include "../include/input.h"

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

