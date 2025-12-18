#include "logic.h"
#include <SDL2/SDL.h>
#include <stdio.h>

bool game_init(Game *game) {
    if (!render_init(&game->render, "main", 800, 600)) return false;
    if (!audio_init(NULL)) return false;
    game->running = true;
    return true;
}

void game_run(Game *game) {
    SDL_Event event;

    while (game->running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) game->running = false;
        }

        // Update game logic here (placeholder)
        // logic_update(&game->state);

        // Draw stuff
        render_clear(&game->render, 20, 20, 30, 255);
        render_rect(&game->render, 100, 100, 200, 150, 255, 0, 0, 255);
        render_line(&game->render, 0, 0, 800, 600, 0, 255, 0, 255);
        render_present(&game->render);

        SDL_Delay(16); // limit CPU usage
    }
}

void game_shutdown(Game *game) {
    audio_shutdown(NULL);
    render_shutdown(&game->render);
}