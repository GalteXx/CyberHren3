#include "All.h"

void rect(int x, int y, int xe, int ye, SDL_Renderer* rende)
{
    for (int i = y; i < ye; i++)
    {
        xLine(x, i, xe, rende);
    }
}