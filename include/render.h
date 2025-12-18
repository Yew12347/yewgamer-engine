#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct RenderEngine {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int width;
    int height;
} RenderEngine;

// Initialize render engine
bool render_init(RenderEngine *engine, const char *title, int width, int height);

// Shutdown engine
void render_shutdown(RenderEngine *engine);

// Clear frame with color
void render_clear(RenderEngine *engine, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

// Present frame
void render_present(RenderEngine *engine);

// Draw functions
void render_rect(RenderEngine *engine, int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void render_line(RenderEngine *engine, int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

#endif