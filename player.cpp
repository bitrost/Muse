#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

#include "player.h"

Player::Player()
{
  // Points to track to be played
  Mix_Music *music = NULL;
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

// Possibly change to bool (& change similar functions)
void Player::initialize()
{
  if(SDL_Init(SDL_INIT_AUDIO) == -1)
  {
    std::cout << "SDL_Init: %s\n" << SDL_GetError() << "\n";
  }

  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
}

// Loads the current track to be played
void Player::load_music()
{
  music = Mix_LoadMUS("/home/lauren/Music/Guilty_Kiss_-_Shadow_gate_to_love.oga");
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
