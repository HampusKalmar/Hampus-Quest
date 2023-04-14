#include "../include/environment.h"

Environment::Environment()
{
  if (!texture.loadFromFile("assets/images/ground.png"))
  {
    std::cout << "Failed to load image" << std::endl;
  }
  topGround.setTexture(texture);
  topGround.setPosition(0, 763);
}

void Environment::drawGround(float windowWidth)
{
  int numCopies = std::ceil(windowWidth / topGround.getGlobalBounds().width);
  
  for (int i = 0; i < numCopies; i++)
  {
    sf::Sprite topCopy = topGround;
    topCopy.setPosition(i * topGround.getGlobalBounds().width, 763);
    topGroundSprites.push_back(topCopy);
  }
}

std::vector<sf::Sprite> Environment::getTopGround() const
{
  return topGroundSprites;
} 