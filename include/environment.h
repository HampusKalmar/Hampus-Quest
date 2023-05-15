#ifndef ENVIRONMENT_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include <cmath>

class Environment
{
  private:
    sf::Texture texture;
    sf::Sprite m_groundSprites[30];
    const int numBlocks = 30;
    const int groundHeight = 752;

  public:
    Environment();
    void drawGround(sf::RenderWindow& window);
    std::vector<sf::Sprite> getSpriteBlocks() const;

};

#endif