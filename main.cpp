//#include <gtkmm.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include <iostream>

// To compile:
// g++ main.cpp -o Muse `pkg-config --cflags --libs gtkmm-3.0`
// g++ main.cpp -lSDL2 -lSDL2_mixer

// MP3 file

// Points to track to be played
Mix_Music *music = NULL;

// Playback controls
// Plays selected song
void play()
{
  Mix_ResumeMusic();
}

// Pauses currently playing song
void pause()
{
  Mix_PauseMusic();
}

// Stops currently playing song
void stop()
{
  Mix_HaltMusic();
}

// Possibly change to bool (& change similar functions)
void initialize()
{
  if(SDL_Init(SDL_INIT_AUDIO) == -1)
  {
    std::cout << "SDL_Init: %s\n" << SDL_GetError() << "\n";
  }

  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
}

// Loads the current track to be played
void load_music()
{
  music = Mix_LoadMUS("/home/lauren/Music/Guilty_Kiss_-_Shadow_gate_to_love.oga");
}

// Shutdown processes
void quit()
{
  Mix_FreeMusic(music);
  Mix_CloseAudio();
  SDL_Quit();

  /*while(Mix_Init(0))
  {
    Mix_Quit();
  }*/
}

int main(int argc, char **argv)
{
  initialize();
  load_music();
  Mix_PlayMusic(music, 1);

  SDL_Delay(100000000);


  return 0;
}
