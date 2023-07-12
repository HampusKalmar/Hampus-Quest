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
  headerText.setFillColor(sf::Color::Black);
  headerText.setPosition(120.f, 50.f);

  playText.setFont(font);
  playText.setString("Press enter to play");
  playText.setCharacterSize(40);
  playText.setFillColor(sf::Color::Black);
  playText.setPosition(200.f, 200.f);

  exitText.setFont(font);
  exitText.setString("press escape to exit");
  exitText.setCharacterSize(40);
  exitText.setFillColor(sf::Color::Black);
  exitText.setPosition(200.f, 350.f);
}

void MainMenu::handleEvent(sf::Event& event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    if (event.key.code == sf::Keyboard::Enter)
    {
      playPressed = true;
    }
    else if (event.key.code == sf::Keyboard::Escape)
    {
      exitPressed = true;
    }
  }

  if (event.type == sf::Event::KeyReleased)
  {
    if (event.key.code == sf::Keyboard::Enter)
    {
      playPressed = false;
    }
    else if (event.key.code == sf::Keyboard::Escape)
    {
      exitPressed = false;
    }
  }
}

void MainMenu::displayMenu(sf::RenderWindow& window)
{
  mousePos = sf::Mouse::getPosition(window);
  window.clear(sf::Color(218, 118, 0));
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
  else
  {
    return false;
  }
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