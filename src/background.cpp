#include "../include/background.h"

Background::Background(const std::string& filename, int windowWidth,int windowHeight)
{
  if (!texture.loadFromFile("assets/images/theBackground.png"))
  {
    std::cout << "Failed to load background" << std::endl;
  }

  sprite.setTexture(texture);
   sprite.setScale((float)windowWidth / texture.getSize().x, (float)windowHeight / texture.getSize().y);
}

void Background::drawBackground(sf::RenderWindow& window)
{
  window.draw(sprite);
}