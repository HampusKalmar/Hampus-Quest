#ifndef MAIN_MENU_H

#include <iostream>
#include "SFML/Graphics.hpp"

class MainMenu
{
  private:
    sf::Font font;
    sf::Text titleText;
    sf::Text startText;

  public:
    MainMenu();
    void show(sf::RenderWindow& window);
};

#endif