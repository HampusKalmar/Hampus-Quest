#ifndef GAMEOVERMENU_H

#include <iostream>
#include "SFML/Graphics.hpp"

class GameOverMenu
{
  private:
    sf::Font font;
    sf::Text retryText;
    sf::Text exitText;
    sf::Text gameOverText;
    sf::Text headerText;
    bool retryPressed = false;
    bool exitPressed = false;
    sf::Vector2i mousePos;
   
  public:
    GameOverMenu();
    void handleEvent(sf::Event& event);
    void displayMenu(sf::RenderWindow& window);
    bool isRetryPressed() const;
    bool isExitPressed() const;
};

#endif