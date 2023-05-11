#ifndef MAIN_MENU_H

#include <iostream>
#include "SFML/Graphics.hpp"

class MainMenu
{
  private:
    sf::Font font;
    sf::Text playText;
    sf::Text exitText;
    sf::Text headerText;
    sf::Texture spriteTexture;
    sf::Sprite sprite;
    bool playPressed = false;
    bool exitPressed = false;
    sf::Vector2i mousePos;
   
  public:
    MainMenu();
    void handleEvent(sf::Event& event);
    void displayMenu(sf::RenderWindow& window);
    bool isPlayPressed() const;
    bool isExitPressed() const;
};

#endif