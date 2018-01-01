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
  void get_music();
  void load_music();
  void output_music();
  void quit();

private:
  Mix_Music *music;
  char music_path[256];

};

#endif // PLAYER_H
