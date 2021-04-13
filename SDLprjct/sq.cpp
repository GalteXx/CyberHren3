#include "All.h"


void sq(int x, int y, int l, SDL_Renderer* rende)
{
    for (int i = x - l / 2; i < x + l / 2; i++) //top
        SDL_RenderDrawPoint(rende, i, y - l / 2);
    for (int i = x - l / 2; i < x + l / 2 + 1; i++) //bottom
        SDL_RenderDrawPoint(rende, i, y + l / 2);
    for (int i = y - l / 2; i < y + l / 2; i++) //left
        SDL_RenderDrawPoint(rende, x - l / 2, i);
    for (int i = y - l / 2; i < y + l / 2; i++) //right
        SDL_RenderDrawPoint(rende, x + l / 2, i);
}