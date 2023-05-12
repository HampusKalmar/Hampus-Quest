#include "../include/sound.h"

int Sound::menuMusic()
{
  if (!music.openFromFile("assets/sounds/songTwo.wav"))
  {
    std::cout << "Music cannot play right now" << std::endl;
    return 1;
  }

  music.play();
  music.setLoop(true);
  music.setVolume(30);
  return 0;
}

void Sound::stopMenuMusic()
{
  music.stop();
}

int Sound::gameMusic()
{
  if (!inGameMusic.openFromFile("assets/sounds/songOne.wav"))
  {
    std::cout << "The game music cant play right now" << std::endl;
    return 1;
  }
  inGameMusic.play();
  inGameMusic.setLoop(true);
  inGameMusic.setVolume(30);
  return 0;
}

void Sound::stopGameMusic()
{
  inGameMusic.stop();
}