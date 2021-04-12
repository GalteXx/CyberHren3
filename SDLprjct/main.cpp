#include "All.h"
#include <vector>

void sq(int x, int y, int l, SDL_Renderer* rende)
{
    /*for (int i = x; i < x + l; i++)
        SDL_RenderDrawPoint(rende, i, y);
    for (int i = x; i <= x + l; i++)
        SDL_RenderDrawPoint(rende, i, y + l);
    for (int i = y; i < y + l; i++)
        SDL_RenderDrawPoint(rende, x, i);
    for (int i = y; i < y + l; i++)
        SDL_RenderDrawPoint(rende, x + l, i);*/
    for (int i = x - l/2; i < x + l/2; i++) //top
        SDL_RenderDrawPoint(rende, i, y - l/2);
    for (int i = x - l / 2; i < x + l / 2 + 1; i++) //bottom
        SDL_RenderDrawPoint(rende, i, y + l/2);
    for (int i = y - l / 2; i < y + l/2; i++) //left
        SDL_RenderDrawPoint(rende, x - l/2, i);
    for (int i = y - l / 2; i < y + l / 2; i++) //right
        SDL_RenderDrawPoint(rende, x + l/2, i); 


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
    /*SDL_Window *wind = SDL_CreateWindow("Cursor Defender", 200, 100, 800, 800, SDL_WINDOW_SHOWN);
    SDL_Renderer *rende = SDL_CreateRenderer(wind, -1, 0);*/
    SDL_Window* wind;
    SDL_Renderer* rende;
    SDL_CreateWindowAndRenderer(800, 800, 0, &wind, &rende);
    SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);
    int xMouse = 0, yMouse = 0;
    
    //run(rende, 600, 800, 500, 500);
    /*rect(100, 100, 200, 200, rende);
    update;*/
    /*Enemy en1;
    en1.x = 250;
    en1.y = 250;
    en1.size = 50;
    en1.en_spawn(en1.x, en1.y, en1.size, rende);

    while(true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&xMouse, &yMouse);
            }
            if (xMouse - en1.x <= 15)
            {
                while (xMouse > en1.x)
                {
                    en1.x--;
                    en1.en_spawn(en1.x, en1.y, en1.size, rende);
                    update(rende);
                }
            }
            else if (en1.x - xMouse <= 15)
            {
                while (en1.x > xMouse)
                {
                    en1.x++;
                    en1.en_spawn(en1.x, en1.y, en1.size, rende);
                    update(rende);
                }
            }
        }
    }*/
    int x = 600;
    int y = 600;
    int size = 50;
    sq(x, y, size, rende);
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
            int difx = xMouse - x;
            int dify = yMouse - y;
            if (difx < 50 && difx > 0 && dify < 50 && dify > 0) // оба положит
            {
                x -= difx;
                y -= dify;
                sq(x, y, size, rende);
                present(rende);
                clear(rende);
            }
            else if (difx > -50 && difx < 0 && dify > -50 && dify < 0) // оба отриц
            {
                x -= difx;
                y -= dify;
                sq(x, y, size, rende);
                present(rende);
                clear(rende);
            }
            else if (difx > -50 && difx < 0 && dify > 0 && dify < 50) // x отриц y положит
            {
                x += difx;
                y -= dify;
                sq(x, y, size, rende);
                present(rende);
                clear(rende);
            }
            else if (difx > 0 && difx < 50 && dify > -50 && dify <  0) // x положит y отриц
            {
                x += difx;
                y -= dify;
                sq(x, y, size, rende);
                present(rende);
                clear(rende);
            }
        }
    }
    SDL_Quit();
    return 0;
}

