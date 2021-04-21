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

void rc1(int x, int y, int w, int h, SDL_Renderer* rende) // строит из центра
{
    for (int i = x - w / 2; i < x + w / 2; i++) //top
        SDL_RenderDrawPoint(rende, i, y - h / 2);
    for (int i = x - w / 2; i < x + w / 2 + 1; i++) //bottom
        SDL_RenderDrawPoint(rende, i, y + h / 2);
    for (int i = y - h / 2; i < y + h / 2; i++) //left
        SDL_RenderDrawPoint(rende, x - w / 2, i);
    for (int i = y - h / 2; i < y + h / 2; i++) //right
        SDL_RenderDrawPoint(rende, x + w / 2, i);
}

void rc2(int x, int y, int w, int h, SDL_Renderer* rende) // из верхнего левого угла
{
    for (int i = x; i < x + w; i++) //top
        SDL_RenderDrawPoint(rende, i, y);
    for (int i = x; i < x + w + 1; i++) //bottom
        SDL_RenderDrawPoint(rende, i, y + h);
    for (int i = y; i < y + h; i++) //left
        SDL_RenderDrawPoint(rende, x, i);
    for (int i = y; i < y + h; i++) //right
        SDL_RenderDrawPoint(rende, x + w, i);
}