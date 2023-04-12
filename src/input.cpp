#include "../include/input.h"

bool Input::isUpKeyPressed()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    return true;
  }
  return false;
}