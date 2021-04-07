#include "All.h"

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

void run(SDL_Renderer *rende, int x, int y, int xe, int ye)
{

    while(x != xe || y != ye)
    {
        SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);
        rect(x, y, x + 30, y + 30, rende);
        if(x < xe)
            x++;
        if(x > xe)
            x--;
        if(y < ye)
            y++;
        if(y > ye)
            y--;
        SDL_SetRenderDrawColor(rende, 0, 0, 0, 255);

    }
}


//void drawArray(int x, int y, vector <vector <bool> > arr, SDL_Renderer rende)
//{
//    for(int i = 0; i < arr.size(); i)
//    {
//        for (int j = 0; j < arr[i].size())
//        {
//            if(arr[i][j])
//                SDL_RenderDrawPoint(rende, x + i; y + j);
//        }
//    }
//}

int main(int argc, char* args[])
{
    SDL_Window *wind = SDL_CreateWindow("", 20, 20, 1024, 1980, SDL_WINDOW_SHOWN);
    SDL_Renderer *rende = SDL_CreateRenderer(wind, -1, 0);
    //SDL_CreateWindowAndRenderer(200, 600, 0, &wind, &rende);
    SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);
    int xMouse = 0, yMouse = 0;


    //run(rende, 600, 800, 500, 500);
    Enemy en;
    en.x = 500;
    en.y = 500;
    en.size = 50;
    SDL_Delay(200);

    while(true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_MOUSEMOTION)
            {
                SDL_GetGlobalMouseState(&xMouse, &yMouse);
            }
            if(abs(en.x - xMouse <= 15))
            update(rende);
        }
    }
    //SDL_RenderPresent(rende);

    SDL_Quit();
    return 0;
}

