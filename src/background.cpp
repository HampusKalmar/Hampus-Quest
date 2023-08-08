#include "../include/background.h"

/**
 * The Background constructor. 
 */
Background::Background() 
{
  if (!texture.loadFromFile("assets/images/Background.png"))
  {
    std::cout << "Failed to load image" << std::endl;
  }

  
  backgroundSprite.setTexture(texture);
  backgroundSprite.setScale(4.1f, 4.1f);
  texture.setRepeated(true);
}

/**
 * Sets the background to the game. 
 */
void Background::setBackground(sf::RenderWindow& window, const sf::View &view)
{
  sf::Vector2f viewCenter = view.getCenter();
  sf::Vector2f viewSize = view.getSize();

  int repeats = 4; // How many times you want to repeat the sequence.

  for(int i = 0; i < repeats; i++)
  {
    backgroundSprite.setPosition(viewCenter.x - viewSize.x / 2.0f + i * viewSize.x, viewCenter.y - viewSize.y / 2.0f);
        
    backgroundSprite.setTextureRect(sf::IntRect(0, 0, viewSize.x, viewSize.y));

    window.draw(backgroundSprite);
  }
}