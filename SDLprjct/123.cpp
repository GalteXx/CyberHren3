#include "SDL.h"
#include <iostream>
using namespace std;
#include "RenderWindow.hpp"
#include "RenderWIndow.cpp"

int main(int argc, char* args[])
{
    if(SDL_Init(SDL_INIT_VIDEO) > 0)
        cout << "HEY... SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << endl;

    //if (!(IMG_Init(IMG_INIT_PNG)))
    //    cout << "IMG_init has failed. Error: " << SDL_GetError() << endl;

    RenderWindow("Game v1.0", 1280, 720);

    bool gameRunning = true;

    SDL_Event event;

    while(gameRunning)
    {
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_Quit)
                gameRunning = false;
        }

    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}
