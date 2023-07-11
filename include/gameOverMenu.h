#ifndef GAMEOVERMENU_H

#include <iostream>
#include "SFML/Graphics.hpp"

class GameOverMenu
{
  private:
    sf::Font font;
    sf::Font gameOverFont;
    sf::Font fontTwo;
    sf::Text retryText;
    sf::Text exitTheGameText;
    sf::Text gameOverText;
    sf::Text headerText;
    bool exitPressed = false;
    bool restartPressed = false;
    sf::Vector2i mousePos;
    sf::Vector2f textOffset;
    sf::Vector2f menuPos;
   
  public:
    GameOverMenu();
    void handleGameOverMenuEvent(sf::Event& event);
    void displayMenu(sf::RenderWindow& window, const sf::Sprite& playerSprite);
    bool isExitTheGamePressed() const;
    bool isRestartGamePressed() const;
};

#endif