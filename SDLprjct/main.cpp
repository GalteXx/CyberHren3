#include "All.h"

int main(int argc, char* args[])
{
    SDL_Window* wind;
    SDL_Renderer* rende;
    SDL_CreateWindowAndRenderer(800, 800, 0, &wind, &rende);
    SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);
    int xMouse = 0, yMouse = 0;
    bool GameRunning = true;
    Enemy en1;
    en1.x = 450;
    en1.y = 450;
    en1.size = 50;
    en1.spawn(en1.x, en1.y, en1.size, rende);
    present(rende);
    clear(rende);
    while (true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&xMouse, &yMouse);
            }
            int difx = xMouse - en1.x;
            int dify = yMouse - en1.y;
            if (difx < 50 && difx > 0 && dify < 50 && dify > 0) // оба положит
            {
                en1.x -= difx;
                en1.y -= dify;
                en1.spawn(en1.x, en1.y, en1.size, rende);
                present(rende);
                clear(rende);
            }
            else if (difx > -50 && difx < 0 && dify > -50 && dify < 0) // оба отриц
            {
                en1.x -= difx;
                en1.y -= dify;
                en1.spawn(en1.x, en1.y, en1.size, rende);
                present(rende);
                clear(rende);
            }
            else if (difx > -50 && difx < 0 && dify > 0 && dify < 50) // x отриц y положит
            {
                en1.x -= difx;
                en1.y -= dify;
                en1.spawn(en1.x, en1.y, en1.size, rende);
                present(rende);
                clear(rende);
            }
            else if (difx > 0 && difx < 50 && dify > -50 && dify <  0) // x положит y отриц
            {
                en1.x -= difx;
                en1.y -= dify;
                en1.spawn(en1.x, en1.y, en1.size, rende);
                present(rende);
                clear(rende);
            }
        }
    }
    SDL_Quit();
    return 0;
}

