#include "interface.h"
#include <iostream>

Interface::Interface()
: button_play("Play"),
  button_pause("Pause"),
  button_stop("Stop")
{
  set_title("Gtk::Grid");
  set_border_width(12);
  set_default_size(600,400);
  set_title("Muse Music Player");

  add(m_grid);

  button_play.show();
  button_pause.show();
  button_stop.show();

  m_grid.add(button_play);
  m_grid.add(button_pause);
  m_grid.add(button_stop);
}

Interface::~Interface()
{
}

void Interface::button_play_pressed()
{
  std::cout << "Play pressed" << std::endl;
}
