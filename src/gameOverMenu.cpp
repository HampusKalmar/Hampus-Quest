#include "../include/gameOverMenu.h"

GameOverMenu::GameOverMenu()
{
  if (!font.loadFromFile("assets/fonts/slkscre.ttf"))
  {
    std::cout << "Error" << std::endl;
  }

  if (!gameOverFont.loadFromFile("assets/fonts/slkscre.ttf"))
  {
    std::cout << "Error" << std::endl;
  }

  gameOverText.setFont(gameOverFont);
  gameOverText.setString("GAME OVER");
  gameOverText.setCharacterSize(40);
  gameOverText.setFillColor(sf::Color::Black);

  exitTheGameText.setFont(font);
  exitTheGameText.setString("Press escape to exit the game");
  exitTheGameText.setCharacterSize(25);
  exitTheGameText.setFillColor(sf::Color::Black);

  retryText.setFont(font);
  retryText.setString("Press the 'R' key to restart the game");
  retryText.setCharacterSize(25);
  retryText.setFillColor(sf::Color::Black);
}


void GameOverMenu::handleGameOverMenuEvent(sf::Event& event)
{
   if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::Escape)
    {
      exitPressed = true;
    }
    if (event.key.code == sf::Keyboard::R)
    {
      restartPressed = true;
    }
  }

   if (event.type == sf::Event::KeyReleased)
  {
    if (event.key.code == sf::Keyboard::Escape)
    {
      exitPressed = false;
    }
    if (event.key.code == sf::Keyboard::R)
    {
      restartPressed = false;
    }
  }
}

void GameOverMenu::displayMenu(sf::RenderWindow& window, const sf::Sprite& playerSprite)
{
  window.clear(sf::Color(218, 118, 0));

  sf::Vector2f playerPosition = playerSprite.getPosition();
  sf::Vector2u windowSize = window.getSize();

  sf::Vector2f menuPosition(playerPosition.x - (windowSize.x / 2), playerPosition.y - (windowSize.y / 2));

  exitTheGameText.setPosition(menuPosition.x + 208.f, menuPosition.y + 300.f);
  retryText.setPosition(menuPosition.x + 155.f, menuPosition.y + 220.f);
  gameOverText.setPosition(menuPosition.x + 348.f, menuPosition.y + 100.f);

  window.draw(gameOverText);
  window.draw(exitTheGameText);
  window.draw(retryText);
  window.display();
}


bool GameOverMenu::isExitTheGamePressed() const
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

bool GameOverMenu::isRestartGamePressed() const
{
  if (restartPressed)
  {
    return true;
  }
  else
  {
    return false;
  }
}