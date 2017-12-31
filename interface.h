#ifndef GTKMM_INTERFACE_H
#define GTKMM_INTERFACE_H

#include <gtkmm.h>

class Interface : public Gtk::Window
{
public:
  Interface();
  virtual ~Interface();

private:
  // Signal handlers:
  void button_play_pressed();

  // Child widgets
  Gtk::Grid m_grid;
  Gtk::Button button_play, button_pause, button_stop;
};

#endif // GTKMM_INTERFACE_H
