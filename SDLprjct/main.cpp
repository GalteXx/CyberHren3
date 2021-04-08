#include "All.h"

void xLine(int x, int y, int xe, SDL_Renderer* rende)
{
    for (int i = x; i < xe; i++)
    {
        SDL_RenderDrawPoint(rende, i, y);
    }
}


void rect(int x, int y, int xe, int ye, SDL_Renderer* rende)
{
    for (int i = y; i < ye; i++)
    {
        xLine(x, i, xe, rende);
    }
}

void sq(int x, int y, int l, SDL_Renderer* rende)
{
    for (int i = x; i < x + l; i++)
        SDL_RenderDrawPoint(rende, i, y);
    for (int i = x; i <= x + l; i++)
        SDL_RenderDrawPoint(rende, i, y + l);
    for (int i = y; i < y + l; i++)
        SDL_RenderDrawPoint(rende, x, i);
    for (int i = y; i < y + l; i++)
        SDL_RenderDrawPoint(rende, x + l, i);

}

void run(SDL_Renderer* rende, int x, int y, int xe, int ye)
{

    while (x != xe || y != ye)
    {
        SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);
        rect(x, y, x + 30, y + 30, rende);
        if (x < xe)
            x++;
        if (x > xe)
            x--;
        if (y < ye)
            y++;
        if (y > ye)
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

void hor(int x, int y, int l, SDL_Renderer* ren)
{
    for (int i = 0; i < l; i++)
        SDL_RenderDrawPoint(ren, i + x, y);
}

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

    int x = 200;
    int y = 200;
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
            int xdif = x - xMouse;
            int ydif = y - yMouse;
            if (abs(xMouse - x) <= 100 && abs(yMouse - y) <= 100)
            {
                sq(x + xdif, y + ydif, size, rende);
                present(rende);
                clear(rende);
            }

            /*if (xMouse - x <= 15)
            {
                x--;
                sq(x, y, size, rende);
                present(rende);
                clear(rende);
            }
            else if (x - xMouse <= 15)
            {
                x++;
                sq(x, y, size, rende);
                present(rende);
                clear(rende);
            }*/
        }
    }
    SDL_Quit();
    return 0;
}

