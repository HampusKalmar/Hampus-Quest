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

  // Creates the holes
  for (int i = 0; i < 3; i++)
  {
    m_holes[i].setSize(sf::Vector2f(50.f, 100.f));
    m_holes[i].setFillColor(sf::Color(0, 0, 70));
    m_holes[i].setPosition((i * texture.getSize().x) + (texture.getSize().x / 2.f) - (m_holes[i].getSize().x / 2.f), 450.f);
  }
}

void Environment::drawGround(sf::RenderWindow& window)
{
  for (int i = 0; i < 15; i++)
  {
    window.draw(m_groundSprites[i]);
  }

  for (int i = 0; i < 3; i++)
  {
    window.draw(m_holes[i]);
  }
}
