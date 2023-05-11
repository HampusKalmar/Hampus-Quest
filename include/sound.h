#ifndef SOUND_H
#define SOUND_H

#include <iostream>
#include "SFML/Audio.hpp"

class Sound
{
  private:
    sf::Music music;
    sf::Music inGameMusic;

  public:
    int menuMusic();
    void stopMenuMusic();
    int gameMusic();
    void stopGameMusic();
};

#endif