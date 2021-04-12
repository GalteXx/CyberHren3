#include "All.h"

void xLine(int x, int y, int xe, SDL_Renderer* rende)
{
    for (int i = x; i < xe; i++)
    {
        SDL_RenderDrawPoint(rende, i, y);
    }
}