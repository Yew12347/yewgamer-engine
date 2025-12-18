#include "audio.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <stdbool.h>

static Mix_Music *music = NULL;

bool audio_init(Audio *audio) {
    (void)audio; // silence unused parameter warning

    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "SDL audio init failed: %s\n", SDL_GetError());
        return false;
    }

    // 32-bit float audio, stereo, 1024 samples
    if (Mix_OpenAudio(48000, AUDIO_F32SYS, 2, 1024) < 0) {
        fprintf(stderr, "SDL_mixer init failed: %s\n", Mix_GetError());
        return false;
    }

    // Load OGG music from assets
    music = Mix_LoadMUS("assets/sounds/music.ogg");
    if (!music) {
        fprintf(stderr, "Failed to load music.ogg: %s\n", Mix_GetError());
        return false;
    }

    // Play music indefinitely (-1 = loop)
    if (Mix_PlayMusic(music, -1) == -1) {
        fprintf(stderr, "Failed to play music: %s\n", Mix_GetError());
        return false;
    }

    return true;
}

void audio_shutdown(Audio *audio) {
    (void)audio; // silence unused parameter warning

    if (music) {
        Mix_HaltMusic();
        Mix_FreeMusic(music);
        music = NULL;
    }

    Mix_CloseAudio();
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
}