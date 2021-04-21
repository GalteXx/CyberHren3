#include "All.h"

int m::x;
int m::y;

Uint32 getpixel(SDL_Surface* surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch (bpp)
    {
    case 1:
        return *p;
        break;
    case 2:
        return *(Uint16 *)p;
        break;
    case 3:
        if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
            break;
    case 4:
        return *(Uint32 *)p;
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
            SDL_RenderDrawPoint(rende, i + x, j + y );
        }
    }
}

int main(int argc, char* args[])
{

    SDL_Window* wind;
    SDL_Renderer* rende;
    SDL_CreateWindowAndRenderer(800, 800, 0, &wind, &rende);
    SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);
    bool GameRunning = true;
    bool menu = true;
    

    vector <Enemy> arr;
    for (int i = 0; i < 10; i++)
    {
        Enemy en;
        arr.push_back(en);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i].x = i * 50;
        arr[i].y = i * 10;
    }


    /*while(GameRunning)
    {
        rc(400, 400, 100, 100, rende);
        SDL_Delay(10);
        clear(rende);
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i].updt(rende);
        }
        present(rende);
    }*/
    int x = 100;
    int y = 150;
    //char* test1 = "C:\\button0.bmp";
    SpriteData pic = loadTexture(const_cast<char*>("C:\\Users\\georg\\Documents\\GitHub\\CyberHren3\\button1.bmp"));
    clear(rende);
    drawTexture(x, y, pic, rende);

    //rc(400, 400, 100, 50, rende);
    
    present(rende);
    SDL_Delay(500);
    SDL_Quit();
    return 0;
}

