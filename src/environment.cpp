#include "../include/environment.h"

Environment::Environment()
{
  if (!texture.loadFromFile("assets/images/ground.png"))
  {
    std::cout << "Failed to load image" << std::endl;
  }

   if (!stoneTexture.loadFromFile("assets/images/stone.png"))
  {
    std::cout << "Failed to load image" << std::endl;
  }

  addStone({sf::Vector2f(440, 706), sf::Vector2f(1400, 766), sf::Vector2f(2850, 775), sf::Vector2f(4050, 805)});
  
  // Creates the blocks.
  const int gapWidth = 120;
  std::vector<int> holeSequency = {12, 10, 8, 10, 5, 7, 10, 2, 6, 2, 2, 2, 6};
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

void Environment::addStone(const std::vector<sf::Vector2f>& positions)
{
 for (const auto& pos : positions)
  {
    sf::Sprite sprite;
    sprite.setTexture(stoneTexture);
    sprite.setPosition(pos);
    stoneSprites.push_back(sprite);
  }
}

void Environment::drawStones(sf::RenderWindow& window)
{
  for (const auto& sprite : stoneSprites)
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
