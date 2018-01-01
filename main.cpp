#include <iostream>
#include <gtkmm/application.h>

#include "interface.h"
#include "player.h"

int main(int argc, char **argv)
{
  auto app = Gtk::Application::create(argc, argv);

  Interface window;
  Player player;

  player.initialize();
  //player.load_music("/home/lauren/Music/TESTAMENT.oga");
  //player.output_music();

  // Shows the window and returns when it is closed.
  return app->run(window);
}
