#include "../include/environment.h"

Environment::Environment()
{
  if (!texture.loadFromFile("assets/images/ground.png"))
  {
    std::cout << "Failed to load image" << std::endl;
  }
  
  // Creates the blocks.
  const int gapWidth = 60;
  const int holeFrequency = 12;
  const int negativeDeltaY = 100;
  const int positiveDeltaY = -70;
  int currentX = 0;
  int currentY = groundHeight;
  bool increaseY = true;
  for (int i = 0; i < numBlocks; i++)
  {
    m_groundSprites[i].setTexture(texture);
    m_groundSprites[i].setScale(1.5f, 1.5f);
    const int blockWidth = m_groundSprites[i].getGlobalBounds().width;
    m_groundSprites[i].setPosition(currentX, currentY + blockWidth);
    currentX += blockWidth;
    if ((i + 1) % holeFrequency == 0)
    {
      currentX += gapWidth;
      if (increaseY) {
        currentY -= negativeDeltaY;
      } else {
        increaseY += positiveDeltaY;
      }
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
  return sprites;
}
