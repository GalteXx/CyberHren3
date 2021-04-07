/*
#include <SDL.h>

int main( int argc, char* args[] )
{
    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_CreateWindow("My first sdl window", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Delay(3000);
    SDL_Quit();
    return 0;
}
*/
#include "SDL.h"
#include <iostream>
#include "RenderWindow.hpp"
#include "RenderWIndow.cpp"
#include <SDL.h>
using namespace std;

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        cout << "HEY... SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << endl;

    //if (!(IMG_Init(IMG_INIT_PNG)))
    //    cout << "IMG_init has failed. Error: " << SDL_GetError() << endl;

    RenderWindow("Game v1.0", 1280, 720);

    bool gameRunning = true;

    SDL_Event event;

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_Quit)
                gameRunning = false;
        }

    }

    cleanUp();
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindow("My first sdl window", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Delay(3000);
    SDL_Quit();

    return 0;
}