#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include "SFML/Graphics.hpp"

class Input
{
  private:
    sf::Sprite sprite;
    sf::Vector2f move_x;
    sf::Vector2f move_y;
    sf::Keyboard left;
    sf::Keyboard right;
    sf::Keyboard jump;


  public:
    bool isRightKeyPressed();
    bool isLeftKeyPressed();
    bool isUpKeyPressed();
    // bool isEscapeKeyPressed();
};

#endif