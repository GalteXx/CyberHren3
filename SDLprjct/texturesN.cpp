#include "All.h"
void drawTexture(int x, int y, SpriteData pic, SDL_Renderer* rende)
{
    for (int i = 0; i < pic.w; i++)
    {
        for (int j = 0; j < pic.h; j++)
        {
            SDL_SetRenderDrawColor(rende, pic.texture[i][j].r, pic.texture[i][j].g, pic.texture[i][j].b, pic.texture[i][j].a);
            SDL_RenderDrawPoint(rende, i + x, j + y);
        }
    }
}

void redrawGrass(int x, int y, int size, SDL_Renderer* rende)
{
    SpriteData pic = loadTexture(const_cast<char*>("C:\\SDL Game Assets\\GRASS.bmp"));
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            SDL_SetRenderDrawColor(rende, pic.texture[i][j].r, pic.texture[i][j].g, pic.texture[i][j].b, pic.texture[i][j].a);
            SDL_RenderDrawPoint(rende, i, j);
        }
    }
}