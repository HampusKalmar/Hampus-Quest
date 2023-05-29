#include "../include/gameOverMenu.h"

GameOverMenu::GameOverMenu()
{
  if (!font.loadFromFile("assets/fonts/slkscre.ttf"))
  {
    std::cout << "Error" << std::endl;
  }

  retryText.setFont(font);
  retryText.setString("Try again");
  retryText.setCharacterSize(35);
  retryText.setFillColor(sf::Color::White);

  exitText.setFont(font);
  exitText.setString("Exit to main menu");
  exitText.setCharacterSize(35);
  exitText.setFillColor(sf::Color::White);
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

void GameOverMenu::displayMenu(sf::RenderWindow& window, const sf::Sprite& playerSprite)
{
  mousePos = sf::Mouse::getPosition(window);
  window.clear(sf::Color(0, 0, 70));
 
  retryText.setPosition(450.f + textOffset.x, 200.f + textOffset.y);
  exitText.setPosition(425.f + textOffset.x, 350.f + textOffset.y);

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