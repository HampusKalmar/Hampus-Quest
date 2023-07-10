#include "../include/background.h"

Background::Background() 
{
  if (!texture.loadFromFile("assets/images/gameBackground.png"))
  {
    std::cout << "Failed to load image" << std::endl;
  }
  
  backgroundSprite.setTexture(texture);
  backgroundSprite.setScale(8.0f, 8.0f);
  texture.setRepeated(true);
}

void Background::setBackground(sf::RenderWindow& window, const sf::View &view)
{
  sf::Vector2f viewCenter = view.getCenter();
  sf::Vector2f viewSize = view.getSize();
  backgroundSprite.setPosition(viewCenter.x - viewSize.x / 2.0f, viewCenter.y - viewSize.y / 2.0f);

  backgroundSprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));
  window.draw(backgroundSprite);
}