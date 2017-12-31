#include <iostream>

#include "interface.h"

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

  m_grid.show();

  button_play.show();
  button_pause.show();
  button_stop.show();

  m_grid.add(button_play);
  m_grid.add(button_pause);
  m_grid.add(button_stop);

  button_play.signal_clicked().connect(
    sigc::bind<Glib::ustring>(sigc::mem_fun(*this,
      &Interface::on_button_pressed), "Play"));

  button_pause.signal_clicked().connect(
    sigc::bind<Glib::ustring>(sigc::mem_fun(*this,
      &Interface::on_button_pressed), "Pause"));

  button_stop.signal_clicked().connect(
    sigc::bind<Glib::ustring>(sigc::mem_fun(*this,
      &Interface::on_button_pressed), "Stop"));
}

Interface::~Interface()
{
}

void Interface::on_button_pressed(const Glib::ustring& button_name)
{
  std::cout << button_name << " was pressed" << std::endl;
}
