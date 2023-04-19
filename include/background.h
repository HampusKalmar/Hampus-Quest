#ifndef BACKGROUND_H

#include "SFML/Graphics.hpp"
#include <iostream>

class Background
{
  private:
    sf::Texture texture;
    sf::Sprite sprite;

  public:
    Background(const std::string& filename, int windowWidth, int windowHeight);
    void drawBackground(sf::RenderWindow& window);
};

#endif