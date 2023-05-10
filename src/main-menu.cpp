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

void MainMenu::display(sf::RenderTarget& target, sf::RenderStates states)
{
  target.draw(playText, states);
  target.draw(exitText, states);
}

bool MainMenu::isPlayPressed() const
{
    if (playText.getGlobalBounds().contains(mousePos.x, mousePos.y))
  {
    return true;
  }

  return false;
}

bool MainMenu::isExitPressed() const
{
  if (exitText.getGlobalBounds().contains(mousePos.x, mousePos.y))
  {
    return true;
  }
  else
  {
    return false;
  }
}