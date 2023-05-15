#include "../include/environment.h"

Environment::Environment()
{
  if (!texture.loadFromFile("assets/images/ground.png"))
  {
    std::cout << "Failed to load image" << std::endl;
  }
  
  // Creates the blocks.
  const int blockWidth = texture.getSize().x;
  const int gapWidth = 20;
  const int holeFrequency = 6;
  for (int i = 0; i < numBlocks; i++)
  {
    m_groundSprites[i].setTexture(texture);
    m_groundSprites[i].setScale(1.5f, 1.5f);
    //m_groundSprites[i].setPosition(i * texture.getSize().x, 752.f);
    if (i % holeFrequency == 0)
    {
      continue;
    }
    else
    {
      m_groundSprites[i].setPosition(i * (blockWidth + gapWidth), groundHeight + blockWidth);
    }
  }
}

void Environment::drawGround(sf::RenderWindow& window)
{
  for (const auto& sprite : m_groundSprites)
  {
    window.draw(sprite);
  }
}

std::vector<sf::Sprite> Environment::getSpriteBlocks() const
{
  std::vector<sf::Sprite> sprites;
  
  for (const auto& sprite : m_groundSprites)
  {
    sprites.push_back(sprite);
  }  
  //return std::vector<sf::Sprite>(std::begin(m_groundSprites), std::end(m_groundSprites));
  return sprites;
}
