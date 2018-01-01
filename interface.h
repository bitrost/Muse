#ifndef GTKMM_INTERFACE_H
#define GTKMM_INTERFACE_H

#include <gtkmm.h>

class Interface : public Gtk::Window
{
public:
  Interface();
  virtual ~Interface();

private:
  // Signal handlers for playback controls
  void on_button_pressed(const Glib::ustring& button_name);

  // Signal handlers for file chooser
  void on_button_file_clicked();

  // Child widgets
  Gtk::Grid m_grid;
  Gtk::Button button_play, button_pause, button_stop;
  Gtk::Button m_button_file;
};

#endif // GTKMM_INTERFACE_H
