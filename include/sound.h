#ifndef SOUND_H
#define SOUND_H

#include <iostream>
#include "SFML/Audio.hpp"

class Sound
{
  private:
    sf::Music music;

  public:
    int menuMusic(); 
};

#endif