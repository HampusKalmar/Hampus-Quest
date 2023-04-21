#ifndef COLLISION_H

#include "SFML/Graphics.hpp"

class Collision
{
  private:
    sf::Sprite sprite1;
    sf::Sprite sprite2;

  public:
    bool checkSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);  
    bool checkSpriteCollisionWithGround(sf::Sprite playerSprite, std::vector<sf::Sprite> groundSprites);  
};

#endif