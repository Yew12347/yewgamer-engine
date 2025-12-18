#ifndef LOGIC_H
#define LOGIC_H

#include "render.h"
#include "audio.h"
#include "keyhand.h"
#include <stdbool.h>

typedef struct Game {
    RenderEngine render;
    bool running;

    // Input handling
    KeyHand kh;

    // Movable rectangle
    int rect_x;
    int rect_y;
    int rect_w;
    int rect_h;
} Game;

// Initialize game
bool game_init(Game *game);

// Run game loop
void game_run(Game *game);

// Shutdown game
void game_shutdown(Game *game);

#endif