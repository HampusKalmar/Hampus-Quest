#ifndef ENVIRONMENT_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include <cmath>

class Environment
{
  private:
    sf::Texture texture;
    sf::Sprite m_groundSprites[15];
    sf::RectangleShape m_holes[3];

  public:
    Environment();
    void drawGround(sf::RenderWindow& window);
    void update(float deltaTime);
};

#endif