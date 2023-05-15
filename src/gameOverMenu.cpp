#include "../include/gameOverMenu.h"

GameOverMenu::GameOverMenu()
{
  if (!font.loadFromFile("assets/fonts/slkscre.ttf"))
  {
    std::cout << "Error" << std::endl;
  }

  retryText.setFont(font);
  retryText.setString("try again");
  retryText.setCharacterSize(50);
  retryText.setFillColor(sf::Color::White);
  retryText.setPosition(420.f, 200.f);

  exitText.setFont(font);
  exitText.setString("Exit to main menu");
  exitText.setCharacterSize(50);
  exitText.setFillColor(sf::Color::White);
  exitText.setPosition(425.f, 350.f);
}


void GameOverMenu::handleEvent(sf::Event& event)
{
  if (event.type == sf::Event::MouseButtonPressed)
  {
    if (retryText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
      retryPressed = true;
    }
    else if (exitText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
      exitPressed = true;
    }
  }

  if (event.type == sf::Event::MouseButtonReleased)
  {
    if (retryText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
      retryPressed = false;
    }
    else if (exitText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
      exitPressed = false;
    }
  }
}

void GameOverMenu::displayMenu(sf::RenderWindow& window)
{
  mousePos = sf::Mouse::getPosition(window);
  window.clear(sf::Color::Black);
  window.draw(headerText);
  window.draw(retryText);
  window.draw(exitText);
  window.display();
}

bool GameOverMenu::isRetryPressed() const
{
    if (retryPressed)
  {
    return true;
  }

  return false;
}

bool GameOverMenu::isExitPressed() const
{
  if (exitPressed)
  {
    return true;
  }
  else
  {
    return false;
  }
}