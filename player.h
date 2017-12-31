#ifndef PLAYER_H
#define PLAYER_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

class Player
{
public:
  Player();

  void music_play();
  void music_pause();
  void music_stop();
  void initialize();
  void load_music();
  void quit();

private:
  Mix_Music *music;

};

#endif // PLAYER_H
