#ifndef MAIN_MENU_H

#include <iostream>
#include "SFML/Graphics.hpp"

class MainMenu
{
  private:
    sf::Font font;
    sf::Text playText;
    sf::Text exitText;
    bool playPressed = false;
    bool exitPressed = false;
   
  public:
    MainMenu();
    void draw(sf::RenderWindow& window);
    void handleEvent(sf::Event& event);
    bool isPlayPressed() const;
    bool isExitPressed() const;
};

#endif