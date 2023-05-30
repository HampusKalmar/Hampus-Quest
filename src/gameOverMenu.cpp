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
  gameOverText.setFillColor(sf::Color::White);

  exitTheGameText.setFont(font);
  exitTheGameText.setString("Press escape to exit the game and then retry");
  exitTheGameText.setCharacterSize(25);
  exitTheGameText.setFillColor(sf::Color::White);
}


void GameOverMenu::handleGameOverMenuEvent(sf::Event& event)
{
   if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::Escape)
    {
      exitPressed = true;
    }
  }

   if (event.type == sf::Event::KeyReleased)
  {
    if (event.key.code == sf::Keyboard::Escape)
    {
      exitPressed = false;
    }
  }
}

void GameOverMenu::displayMenu(sf::RenderWindow& window, const sf::Sprite& playerSprite)
{
  window.clear(sf::Color(0, 0, 70));

  sf::Vector2f playerPosition = playerSprite.getPosition();
  sf::Vector2u windowSize = window.getSize();

  sf::Vector2f menuPosition(playerPosition.x - (windowSize.x / 2), playerPosition.y - (windowSize.y / 2));

  exitTheGameText.setPosition(menuPosition.x + 90.f, menuPosition.y + 350.f);
  gameOverText.setPosition(menuPosition.x + 360.f, menuPosition.y + 250.f);

  window.draw(gameOverText);
  window.draw(exitTheGameText);
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