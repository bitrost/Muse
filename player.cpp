#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

#include "player.h"

Player::Player()
{
  // Points to track to be played
  Mix_Music *music = NULL;

  // Holds path to music track
  char music_path[256];
}

// Plays selected song
void Player::music_play()
{
  Mix_ResumeMusic();
}

// Pauses currently playing song
void Player::music_pause()
{
  Mix_PauseMusic();
}

// Stops currently playing song
void Player::music_stop()
{
  Mix_HaltMusic();
}

// Initializes SDL
void Player::initialize()
{
  if(SDL_Init(SDL_INIT_AUDIO) == -1)
  {
    std::cout << "SDL_Init: %s\n" << SDL_GetError() << "\n";
  }

  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
}

// Gets path to music entered by user
/*void Player::get_music()
{
  std::cin.getline(music_path, 256, '\n');
}*/

// Loads the current track to be played
void Player::load_music(std::string filename)
{
  // Converts path in std::string to C-style string
  strcpy(music_path, filename.c_str());

  music = Mix_LoadMUS(music_path);
}

void Player::output_music()
{
  Mix_PlayMusic(music, 1);
}

// Shutdown processes
void Player::quit()
{
  Mix_FreeMusic(music);
  Mix_CloseAudio();
  SDL_Quit();

  /*while(Mix_Init(0))
  {
    Mix_Quit();
  }*/
}
