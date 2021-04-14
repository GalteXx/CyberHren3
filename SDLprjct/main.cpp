#include "All.h"

int main(int argc, char* args[])
{
    SDL_Window* wind;
    SDL_Renderer* rende;
    SDL_CreateWindowAndRenderer(800, 800, 0, &wind, &rende);
    SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);
    bool GameRunning = true;

    vector <Enemy> arr;
    //spawnEn(arr);
    for (int i = 0; i < 10; i++)
    {
        Enemy en;
        arr.push_back(en);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i].x = i + 2 * 2;
        arr[i].y = i;
    }

    while(GameRunning)
    {
        SDL_Delay(20);
        clear(rende);
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i].updt(rende);
        }
        present(rende);
    }


    SDL_Quit();
    return 0;
}

