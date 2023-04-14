#include "../include/background.h"

Background::Background(sf::RenderWindow& window)
  : window(window)
{
  if (!texture.loadFromFile("assets/images/background.png"))
  {
    std::cout << "Failed to load background" << std::endl;
  }

  sprite.setTexture(texture);
  sprite.setScale(float(window.getSize().x / sprite.getLocalBounds().width), float(window.getSize().y / sprite.getLocalBounds().height));
}

void Background::draw()
{
  window.draw(sprite);
}