#include "All.h"

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