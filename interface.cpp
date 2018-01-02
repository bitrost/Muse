#include <iostream>

#include "interface.h"
#include "player.h"

// Holds path to file selected in file chooser
std::string filename = "";

// Create Player object
Player player;

Interface::Interface()
: button_play("Play"),
  button_pause("Pause"),
  button_stop("Stop"),
  m_button_file("Choose File")
{
  // Window setup
  set_border_width(12);
  set_default_size(600,400);
  set_title("Muse Music Player");

  // Grid setup
  add(m_grid);

  m_grid.show();

  // Configure and add playback control buttons
  button_play.show();
  button_pause.show();
  button_stop.show();

  m_grid.add(button_play);
  m_grid.add(button_pause);
  m_grid.add(button_stop);

  // Configure and add file chooser button
  m_button_file.show();

  m_grid.add(m_button_file);

  // Set click events for playback buttons in grid
  button_play.signal_clicked().connect(
    sigc::bind<Glib::ustring>(sigc::mem_fun(*this,
      &Interface::on_button_pressed), "Play"));

  button_pause.signal_clicked().connect(
    sigc::bind<Glib::ustring>(sigc::mem_fun(*this,
      &Interface::on_button_pressed), "Pause"));

  button_stop.signal_clicked().connect(
    sigc::bind<Glib::ustring>(sigc::mem_fun(*this,
      &Interface::on_button_pressed), "Stop"));

  // Set click events for file chooser
  m_button_file.signal_clicked().connect(sigc::mem_fun(*this,
    &Interface::on_button_file_clicked));

  // Show all window components
  // show_all_children();

  // Initialize music player
  player.initialize();
}

Interface::~Interface()
{
}

// Event occurring when a playback control button is pressed
void Interface::on_button_pressed(const Glib::ustring& button_name)
{
  if(button_name == "Play")
  {
    player.music_play();
    std::cout << button_name << " was pressed" << std::endl;
  }
  else if(button_name == "Pause")
  {
    player.music_pause();
    std::cout << button_name << " was pressed" << std::endl;
  }
  else if(button_name == "Stop")
  {
    player.music_stop();
    std::cout << button_name << " was pressed" << std::endl;
  }
  else
  {
    std::cout << "Error: This text shouldn't appear" << std::endl;
  }
}

void Interface::on_button_file_clicked()
{
  Gtk::FileChooserDialog dialog("Please choose a file",
    Gtk::FILE_CHOOSER_ACTION_OPEN);
  dialog.set_transient_for(*this);

  // Add response buttons to the dialog
  dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
  dialog.add_button("_Open", Gtk::RESPONSE_OK);

  // Show the dialog and wait for a user response
  int result = dialog.run();

  // Handle the response
  switch(result)
  {
    case(Gtk::RESPONSE_OK):
    {
      std::cout << "Open clicked." << std::endl;

      // Get path to file
      filename = dialog.get_filename();

      // Load file
      player.load_music(filename);
      player.output_music();

      std::cout << "File selected: " << filename << std::endl;
      break;
    }
    case(Gtk::RESPONSE_CANCEL):
    {
      std::cout << "Cancel clicked." << std::endl;
      break;
    }
    default:
    {
      std::cout << "Unexpected button clicked." << std::endl;
      break;
    }
  }
}
