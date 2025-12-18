#pragma once
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

typedef struct {
    Mix_Music *music;
} Audio;

bool audio_init(Audio *audio);
bool audio_play(Audio *audio, const char *filename);
void audio_shutdown(Audio *audio);