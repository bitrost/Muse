//#include <gtkmm.h>
#include <iostream>
#include <gtkmm/application.h>

//#include "SDL2/SDL.h"
//#include "SDL2/SDL_mixer.h"
#include "interface.h"
#include "player.h"

// To compile:
// g++ main.cpp -o Muse -lSDL2 -lSDL2_mixer `pkg-config --cflags --libs gtkmm-3.0`

int main(int argc, char **argv)
{

  auto app = Gtk::Application::create(argc, argv);

  Interface window;

  Player player;

  player.initialize();
  player.load_music();
  // Mix_PlayMusic(music, 1);

  // Shows the window and returns when it is closed.
  return app->run(window);
}
