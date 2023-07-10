#include "../include/environment.h"

Environment::Environment()
{
  if (!texture.loadFromFile("assets/images/ground.png"))
  {
    std::cout << "Failed to load image" << std::endl;
  }
  
  // Creates the blocks.
  const int gapWidth = 100;
  std::vector<int> holeSequency = {12, 10, 8, 10, 5, 5, 10, 2, 6, 2, 2, 2, 6};
  std::vector<int> deltaSequence = {70, -130, 40, -150, 100, 70, -130, 30, 70, -130, 70, -130, 70};
  int currentX = 0;
  int currentY = groundHeight;
  int sequenceIndex = 0;
  int blocksSinceLastHole = 0;
  for (int i = 0; i < numBlocks; i++)
  {
    m_groundSprites[i].setTexture(texture);
    m_groundSprites[i].setScale(1.5f, 1.5f);
    const int blockWidth = m_groundSprites[i].getGlobalBounds().width;
    m_groundSprites[i].setPosition(currentX, currentY + blockWidth);
    currentX += blockWidth;
    blocksSinceLastHole++;
    if (blocksSinceLastHole >= holeSequency[sequenceIndex])
    {
      currentX += gapWidth;
      currentY -= deltaSequence[sequenceIndex];
      sequenceIndex = (sequenceIndex + 1) % deltaSequence.size();
      blocksSinceLastHole = 0;
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
