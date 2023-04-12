#include "../include/sound.h"

int Sound::menuMusic()
{
  if (!music.openFromFile("assets/sounds/mainMenuSong.wav"))
  {
    std::cout << "Music cannot play right now" << std::endl;
    return 1;
  }

  music.play();
  music.setLoop(true);
  music.setVolume(30);
  return 0;
}