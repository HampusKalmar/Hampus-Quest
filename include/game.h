#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "../include/sound.h"
#include "../include/player.h"
#include "../include/input.h"
#include "../include/environment.h"
#include "../include/background.h"
#include "../include/enemy.h"
#include "../include/collision.h"
#include "../include/second-enemy.h"
#include "../include/main-menu.h"
#include "../include/gameOverMenu.h"
#include <iostream>

class Game
{
  private:
    sf::RenderWindow window;
    sf::Event event;
    sf::Color color;
    sf::RenderWindow gameWindow;
    Sound* sound = new Sound();
    Player player;
    Enemy enemy;
    Environment environment;
    Collision collision;
    SecondEnemy secondEnemy;
    Background background;
    sf::Texture trophyTexture;
    sf::Sprite trophySprite;
    sf::Font font;
    sf::View view;
    sf::Font gameOverFont;
    sf::Text congratulationsText;
    sf::Text gameOverText;
    MainMenu* mainMenu = new MainMenu();
    GameOverMenu* gameOverMenu = new GameOverMenu();
    bool theGameIsOver = false;
    bool gameStarted = false;
    bool menuMusicIsPlaying = false;
    bool inGameMusicIsPlaying = false;
    bool returnToMainMenu = false;
    bool restartGame = false;

  public:
    Game();
    ~Game();
    void handleEvents();
    void handleMenuEvents();
    void gameCollision();
    void setCamera();
    void drawGameObjects();
    void gameLoop();
    void gameOver();
    void start();
    void gameWon();
    void resetGame();
    sf::Sprite getTrophySprite();

};

#endif