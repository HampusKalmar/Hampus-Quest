#include "../include/main-menu.h"

MainMenu::MainMenu()
{
  if (!font.loadFromFile("assets/fonts/slkscre.ttf"))
  {
    std::cout << "Error" << std::endl;
  }

  if (!spriteTexture.loadFromFile("assets/images/newSpriteOne.png"))
  {
    std::cout << "Failed" << std::endl;
  }

  sprite.setTexture(spriteTexture);
  sprite.setScale(6.0f, 6.0f);
  sprite.setPosition(429, 550);

  headerText.setFont(font);
  headerText.setString("Hampus Quest");
  headerText.setCharacterSize(80);
  headerText.setFillColor(sf::Color::White);
  headerText.setPosition(120.f, 50.f);

  playText.setFont(font);
  playText.setString("Play");
  playText.setCharacterSize(50);
  playText.setFillColor(sf::Color::White);
  playText.setPosition(420.f, 200.f);

  exitText.setFont(font);
  exitText.setString("Exit");
  exitText.setCharacterSize(50);
  exitText.setFillColor(sf::Color::White);
  exitText.setPosition(425.f, 350.f);
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

  if (event.type == sf::Event::MouseButtonReleased)
  {
    if (playText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
      playPressed = false;
    }
    else if (exitText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
      exitPressed = false;
    }
  }
}

void MainMenu::displayMenu(sf::RenderWindow& window)
{
  mousePos = sf::Mouse::getPosition(window);
  window.clear(sf::Color(0, 0, 70));
  window.draw(headerText);
  window.draw(playText);
  window.draw(exitText);
  window.draw(sprite);
  window.display();
}

bool MainMenu::isPlayPressed() const
{
    if (playPressed)
  {
    return true;
  }

  return false;
}

bool MainMenu::isExitPressed() const
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