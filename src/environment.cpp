#include "../include/environment.h"

Environment::Environment()
{
  if (!texture.loadFromFile("assets/images/ground.png"))
  {
    std::cout << "Failed to load image" << std::endl;
  }
  
  // Creates the blocks.
  for (int i = 0; i < 15; i++)
  {
    m_groundSprites[i].setTexture(texture);
    m_groundSprites[i].setScale(1.5f, 1.5f);
    m_groundSprites[i].setPosition(i * texture.getSize().x, 752.f);
  }
}

void Environment::drawGround(sf::RenderWindow& window)
{
  for (int i = 0; i < 15; i++)
  {
    window.draw(m_groundSprites[i]);
  }
}

sf::Sprite Environment::getSpriteBlocks() const
{
  for (int i = 0; i < 15; i++)
  {
    i++;
  }
  return m_groundSprites[15];
}
