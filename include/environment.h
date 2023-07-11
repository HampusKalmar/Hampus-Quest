#ifndef ENVIRONMENT_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include <cmath>

class Environment
{
  private:
    sf::Texture texture;
    sf::Texture stoneTexture;
    std::vector<sf::Sprite> stoneSprites;
    sf::Sprite m_groundSprites[80];
    const int numBlocks = 80;
    const int groundHeight = 752;

  public:
    Environment();
    void drawGround(sf::RenderWindow& window);
    void addStone(const std::vector<sf::Vector2f>& positions);
    void drawStones(sf::RenderWindow& window);
    std::vector<sf::Sprite> getSpriteBlocks() const;

};

#endif