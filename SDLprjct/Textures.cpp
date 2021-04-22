#include "All.h"

Uint32 getpixel(SDL_Surface* surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;

    switch (bpp)
    {
    case 1:
        return *p;
        break;
    case 2:
        return *(Uint16*)p;
        break;
    case 3:
        if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;
    case 4:
        return *(Uint32*)p;
        break;
    default:
        return 0;
    }
}

SpriteData loadTexture(char* path)
{
    SDL_Surface* image = SDL_LoadBMP(path);
    vector <vector<SDL_Color> > texture(image->w, vector <SDL_Color>(image->h));
    for (int i = 0; i < image->w; i++)
    {
        for (int j = 0; j < image->h; j++)
        {
            SDL_Color color;
            Uint32 data = getpixel(image, i, j);
            SDL_GetRGBA(data, image->format, &color.r, &color.g, &color.b, &color.a);
            texture[i][j] = color;
        }
    }
    SpriteData data;
    data.h = image->h;
    data.w = image->w;
    data.texture = texture;
    return data;
}

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