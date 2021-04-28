#include "SDL2SoundEffects.h"
#include <SDL.h>
#include <iostream>

SDL2SoundEffects::SDL2SoundEffects()
{
    // init sound
    SDL_Init(SDL_INIT_AUDIO);

    int audio_rate = 22050;
    Uint16 audio_format = AUDIO_S16SYS;
    int audio_channels = 2;
    int audio_buffers = 4096;

    if (Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't init audio: %s", Mix_GetError());
        exit(-1);
    }
}
void SDL2SoundEffects::playSoundEffect(const char* path)
{
    Mix_Chunk* tmpChunk = Mix_LoadWAV(path);
    Mix_PlayChannel(-1, tmpChunk, 0);
}