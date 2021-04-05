#include <SDL.h>

int main( int argc, char* args[] )
{
    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_CreateWindow("My first sdl window", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Delay(3000);
    SDL_Quit();
    return 0;
}
