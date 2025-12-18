#include "logic.h"
#include "keyhand.h"
#include "render.h"
#include <SDL2/SDL.h>

bool game_init(Game *game) {
    if (!render_init(&game->render, "main", 800, 600)) return false;
    if (!audio_init(NULL)) return false;

    game->running = true;

    // Initialize KeyHand and rectangle position
    game->kh = (KeyHand){0};
    game->rect_x = 100;
    game->rect_y = 100;
    game->rect_w = 200;
    game->rect_h = 150;

    return true;
}

void game_run(Game *game) {
    while (game->running) {
        // Update input
        keyhand_poll(&game->kh);
        if (game->kh.quit) game->running = false;

        // Move rectangle
        int speed = 5;
        if (game->kh.up) game->rect_y -= speed;
        if (game->kh.down) game->rect_y += speed;
        if (game->kh.left) game->rect_x -= speed;
        if (game->kh.right) game->rect_x += speed;

        // Render
        render_clear(&game->render, 20, 20, 30, 255);
        render_rect(&game->render, game->rect_x, game->rect_y,
                    game->rect_w, game->rect_h, 255, 0, 0, 255);
        render_line(&game->render, 0, 0, 800, 600, 0, 255, 0, 255);
        render_present(&game->render);

        SDL_Delay(16); // ~60fps
    }
}

void game_shutdown(Game *game) {
    audio_shutdown(NULL);
    render_shutdown(&game->render);
}