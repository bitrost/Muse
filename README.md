# Muse Music Player

A simple music player.

## Manual Compilation

g++ -c main.cpp -o Main.o -lSDL2 -lSDL2_mixer `pkg-config --cflags --libs gtkmm-3.0`
g++ -c player.cpp -o Player.o `pkg-config --cflags --libs gtkmm-3.0`
g++ -c interface.cpp -o Interface.o `pkg-config --cflags --libs gtkmm-3.0`

g++ Main.o Interface.o Player.o -o Muse -lSDL2 -lSDL2_mixer `pkg-config --cflags --libs gtkmm-3.0`

## To Do

- Connect buttons to functionality
- Finding/loading music while program running


## Extras
- Album art
