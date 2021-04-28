#include "All.h"

void doMenuThings(SDL_Renderer* rende, SDL2SoundEffects& se, bool& Menu)
{
    clear(rende);
    drawTexture(100, 70, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\LOGO.bmp")), rende);
    drawTexture(200, 300, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\START.bmp")), rende);
    drawTexture(200, 550, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\EXIT.bmp")), rende);
    SDL_Event e;
    SDL_PollEvent(&e);
    if (e.type == SDL_MOUSEBUTTONDOWN)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (x <= 600 && x >= 200 && y >= 300 && y <= 450)
        {
            se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
            Menu = 0;
        }
        if (x <= 600 && x >= 200 && y >= 550 && y <= 700)
        {
            se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
            SDL_Delay(300);
            SDL_Quit();
        }
    }
    present(rende);
}