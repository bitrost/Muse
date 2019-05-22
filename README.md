# Muse Music Player

A simple music player

Playback is compatible with WAVE, MOD, MIDI, OGG, MP3, and FLAC

## Manual Compilation

g++ -c main.cpp -o Build/Main.o -lSDL2 -lSDL2_mixer `pkg-config --cflags --libs gtkmm-3.0`

g++ -c player.cpp -o Build/Player.o `pkg-config --cflags --libs gtkmm-3.0`

g++ -c interface.cpp -o Build/Interface.o `pkg-config --cflags --libs gtkmm-3.0`

To link:

g++ Main.o Interface.o Player.o -o Muse -lSDL2 -lSDL2_mixer `pkg-config --cflags --libs gtkmm-3.0`

To execute:

./Muse
