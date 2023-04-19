#include "../include/background.h"

void Background::backgroundColor(sf::RenderTarget& target, const sf::Color& topColor, const sf::Color& bottomColor)
{
    sf::RectangleShape topHalf(sf::Vector2f(target.getSize().x, target.getSize().y / 2));
    topHalf.setPosition(0, 0);
    topHalf.setFillColor(topColor);

    sf::RectangleShape bottomHalf(sf::Vector2f(target.getSize().x, target.getSize().y / 2));
    bottomHalf.setPosition(0, target.getSize().y / 2);
    bottomHalf.setFillColor(bottomColor);

    target.draw(topHalf);
    target.draw(bottomHalf);
}