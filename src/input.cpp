#include "../include/input.h"

/**
 * Checks if the 'Up' key is pressed and returns true if it is.
 */
bool Input::isUpKeyPressed()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    return true;
  }
  return false;
}

/**
 * Checks if the 'Right' key is pressed and if it is, return true.
 */
bool Input::isRightKeyPressed()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    return true;
  }
  return false;
}

/**
 * Checks if the 'Left' key is pressed and if it is, return true.
 */
bool Input::isLeftKeyPressed()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    return true;
  }
  return false;
}
