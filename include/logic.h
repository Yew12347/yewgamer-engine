#ifndef LOGIC_H
#define LOGIC_H

#include "render.h"
#include "audio.h"
#include <stdbool.h>

typedef struct Game {
    RenderEngine render;
    bool running;
} Game;

// Initialize the game state, render/audio engines
bool game_init(Game *game);

// Run the main loop
void game_run(Game *game);

// Clean up
void game_shutdown(Game *game);

#endif