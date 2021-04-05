#include <SDL.h>

void xLine(int x, int y, int xe, SDL_Renderer *rende)
{
    for(int i = x; i < xe; i++)
    {
        SDL_RenderDrawPoint(rende, i, y);
    }
}

void rect(int x, int y, int xe, int ye, SDL_Renderer *rende)
{
    for(int i = y; i < ye; i++)
    {
        xLine(x, i, xe, rende);
    }
}

void drawArray(int x, int y, bool* arr[])

int main(int argc, char* args[])
{
    //SDL_Init( SDL_INIT_EVERYTHING );
    SDL_Window *wind = SDL_CreateWindow("", 20, 20, 400, 400, SDL_WINDOW_SHOWN);
    SDL_Renderer *rende = SDL_CreateRenderer(wind, -1, 0);
    //SDL_CreateWindowAndRenderer(200, 600, 0, &wind, &rende);
    SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);


    rect(20, 20, 30, 30, rende);



    SDL_RenderPresent(rende);
    SDL_Delay(3000);
    SDL_Quit();
    return 0;
}

