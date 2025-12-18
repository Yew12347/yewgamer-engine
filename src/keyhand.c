#include "keyhand.h"

void keyhand_poll(KeyHand *kh) {
    SDL_Event event;
    kh->quit = false; // reset transient quit

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                kh->quit = true;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_w: kh->up = true; break;
                    case SDLK_s: kh->down = true; break;
                    case SDLK_a: kh->left = true; break;
                    case SDLK_d: kh->right = true; break;
                    case SDLK_ESCAPE: kh->quit = true; break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_w: kh->up = false; break;
                    case SDLK_s: kh->down = false; break;
                    case SDLK_a: kh->left = false; break;
                    case SDLK_d: kh->right = false; break;
                }
                break;
        }
    }
}