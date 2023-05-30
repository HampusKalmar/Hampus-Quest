#include <iostream>
#include <gtest/gtest.h>
#include "../include/player.h"

class PlayerPositionTest : public ::testing::Test
{
  public:
    virtual void setUp()
    {
      testWindow = new sf::RenderWindow(sf::VideoMode(1000, 900), "Test Window");
      texture.loadFromFile("assets/images/newSpriteOne.png");
      sprite.setTexture(texture);
      sprite.setScale(2.0f, 2.0f);
      sprite.setPosition(50, 700);
      player.getSprite() = sprite;
    }
  public:
    virtual void tearDown()
    {
      delete testWindow;
    }
  public:
    sf::Texture texture;
    sf::RenderWindow* testWindow;
    sf::Sprite sprite;
    Player player;
    
};

TEST_F(PlayerPositionTest, PlayerStartingPosition)
{
  sf::Vector2f expectedPosition(50, 700);
  EXPECT_NEAR(expectedPosition.x, player.getSprite().getPosition().x, 0);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}