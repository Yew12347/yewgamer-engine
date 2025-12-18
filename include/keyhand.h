#ifndef KEYHAND_H
#define KEYHAND_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct KeyHand {
    bool up;
    bool down;
    bool left;
    bool right;
    bool quit;
} KeyHand;

// Poll events and update key states
void keyhand_poll(KeyHand *kh);

#endif