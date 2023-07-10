#include "../include/background.h"

Background::Background() 
{
  if (!textureOne.loadFromFile("assets/images/gameBackground.png"))
  {
    std::cout << "Failed to load image" << std::endl;
  }

  if (!textureTwo.loadFromFile("assets/images/gameBackgroundTwo.png"))
  {
    std::cout << "Failed to load image" << std::endl;
  }

  if (!texturePlain.loadFromFile("assets/images/gameBackgroundPlain.png"))
  {
    std::cout << "Failed to load image" << std::endl;
  }
  
  backgroundSpriteOne.setTexture(textureOne);
  backgroundSpriteOne.setScale(8.0f, 8.0f);
  textureOne.setRepeated(true);

  backgroundSpriteTwo.setTexture(textureTwo);
  backgroundSpriteTwo.setScale(8.0f, 8.0f);
  textureTwo.setRepeated(true);

  backgroundSpritePlain.setTexture(texturePlain);
  backgroundSpritePlain.setScale(8.0f, 8.0f);
  texturePlain.setRepeated(true);

  std::srand(std::time(0));
}

void Background::setBackground(sf::RenderWindow& window, const sf::View &view)
{
  sf::Vector2f viewCenter = view.getCenter();
  sf::Vector2f viewSize = view.getSize();

  int repeats = 4; // How many times you want to repeat the sequence.

  for(int i = 0; i < repeats; i++)
  {
    backgroundSpriteOne.setPosition(viewCenter.x - viewSize.x / 2.0f + i * viewSize.x, viewCenter.y - viewSize.y / 2.0f);
    backgroundSpriteTwo.setPosition(viewCenter.x - viewSize.x / 2.0f + i * viewSize.x + viewSize.x/2, viewCenter.y - viewSize.y / 2.0f);
        
    backgroundSpriteOne.setTextureRect(sf::IntRect(0, 0, viewSize.x, viewSize.y));
    backgroundSpriteTwo.setTextureRect(sf::IntRect(0, 0, viewSize.x, viewSize.y));

    window.draw(backgroundSpriteOne);
    window.draw(backgroundSpriteTwo);
  }

  for (int i = 0; i < 4; i++)
  {
    backgroundSpritePlain.setPosition(viewCenter.x + viewSize.x / 2.0f, viewCenter.y - viewSize.y / 4.0f);
    backgroundSpritePlain.setTextureRect(sf::IntRect(0, 0, viewSize.x, viewSize.y));
    window.draw(backgroundSpritePlain);
  }
}