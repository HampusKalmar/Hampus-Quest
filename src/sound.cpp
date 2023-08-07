#include "../include/sound.h"

/**
 * Loads and plays the main menu song.
 */
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

/**
 * Stops the song that is playing in the main menu.
 */
void Sound::stopMenuMusic()
{
  music.stop();
}

/**
 * Loads and plays the in-game music.
 */
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

/**
 * Stops the music that is playing in-game.
 */
void Sound::stopGameMusic()
{
  inGameMusic.stop();
}