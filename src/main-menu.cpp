#include "../include/main-menu.h"

MainMenu::MainMenu()
{

}

void MainMenu::show(sf::RenderWindow& window)
{
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
      else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
      {
        return;
      }
    }
  }
}