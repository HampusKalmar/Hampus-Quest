#include "../include/main-menu.h"

MainMenu::MainMenu()
{
  playText.setString("Play");
  playText.setCharacterSize(50);
  playText.setFillColor(sf::Color::White);
  playText.setPosition(400.f, 200.f);

  exitText.setString("Exit");
  exitText.setCharacterSize(50);
  exitText.setFillColor(sf::Color::White);
  exitText.setPosition(400.f, 350.f);
}

void MainMenu::draw(sf::RenderWindow& window)
{
  window.clear(sf::Color::Black);

  window.draw(playText);
  window.draw(exitText);

  window.display();

}

void MainMenu::handleEvent(sf::Event& event)
{
  if (event.type == sf::Event::MouseButtonPressed)
  {
    if (playText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
      playPressed = true;
    }
    else if (exitText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
      exitPressed = true;
    }
  }
}

bool MainMenu::isPlayPressed() const
{
  return playPressed;
}

bool MainMenu::isExitPressed() const
{
  return exitPressed;
}