#include <iostream>
#include <gtkmm/application.h>

#include "interface.h"
#include "player.h"

int main(int argc, char **argv)
{
  auto app = Gtk::Application::create(argc, argv);

  Interface window;

  // Shows the window and returns when it is closed.
  return app->run(window);
}
