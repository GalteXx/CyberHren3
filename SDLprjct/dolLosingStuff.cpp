#include "All.h"
#include "main.h"
void doLosingStuff(SDL_Renderer* rende, SDL2SoundEffects& se, bool& lose, bool& gamePlay, std::vector<Enemy>& arr, int& spawn, bool& ChooseDifficulty)
{
    clear(rende);
    drawTexture(200, 70, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\GAMEOVER.bmp")), rende);
    drawTexture(200, 250, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\RETRY.bmp")), rende);
    drawTexture(200, 425, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\CHANGEDIFFICULTY.bmp")), rende);
    drawTexture(200, 600, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\EXIT.bmp")), rende);
    SDL_Event e;
    SDL_PollEvent(&e);
    if (e.type == SDL_MOUSEBUTTONDOWN)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (x <= 600 && x >= 200 && y >= 250 && y <= 400) // RETRY
            FigItOut1(se, lose, gamePlay, arr, spawn);
        if (x <= 600 && x >= 200 && y >= 425 && y <= 575) // CHANGE DIFFICULTY
            FigItOut2(se, lose, gamePlay, ChooseDifficulty, arr, spawn);
        if (x <= 600 && x >= 200 && y >= 600 && y <= 750) // EXIT
            EXIT(se);
    }
    present(rende);
}
