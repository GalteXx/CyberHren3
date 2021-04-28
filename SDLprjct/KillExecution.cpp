#include "All.h"

void kill_execute(vector <Enemy>& arr, SDL_Renderer* rende, int& p, int& spawn, int& zeroTime, int& currentTime, SDL2SoundEffects& se)
{
    currentTime = SDL_GetTicks();
    if (currentTime - zeroTime > 10000) {
        zeroTime += 10000;
        for (int i = 0; i < arr.size(); i++)
            arr[i].kill(rende, p, spawn);
        se.playSoundEffect("C:\\SDL Game Assets\\KILL.wav");
    }
}