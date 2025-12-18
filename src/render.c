#include "render.h"
#include <stdio.h>

bool render_init(RenderEngine *engine, const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return false;
    }

    engine->window = SDL_CreateWindow(title,
                                      SDL_WINDOWPOS_CENTERED,
                                      SDL_WINDOWPOS_CENTERED,
                                      width, height, 0);
    if (!engine->window) {
        fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
        return false;
    }

    engine->renderer = SDL_CreateRenderer(engine->window, -1, SDL_RENDERER_ACCELERATED);
    if (!engine->renderer) {
        fprintf(stderr, "Renderer creation failed: %s\n", SDL_GetError());
        return false;
    }

    engine->width = width;
    engine->height = height;
    return true;
}

void render_shutdown(RenderEngine *engine) {
    if (engine->renderer) SDL_DestroyRenderer(engine->renderer);
    if (engine->window) SDL_DestroyWindow(engine->window);
    SDL_Quit();
}

void render_clear(RenderEngine *engine, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(engine->renderer, r, g, b, a);
    SDL_RenderClear(engine->renderer);
}

void render_present(RenderEngine *engine) {
    SDL_RenderPresent(engine->renderer);
}

void render_rect(RenderEngine *engine, int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_Rect rect = {x, y, w, h};
    SDL_SetRenderDrawColor(engine->renderer, r, g, b, a);
    SDL_RenderFillRect(engine->renderer, &rect);
}

void render_line(RenderEngine *engine, int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(engine->renderer, r, g, b, a);
    SDL_RenderDrawLine(engine->renderer, x1, y1, x2, y2);
}