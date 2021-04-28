#include "All.h"
void difficultyButtonPress(SDL2SoundEffects& se, bool& ChooseDifficulty);
void ChoosingDifficulty(SDL_Renderer* rende, SDL2SoundEffects& se, bool& ChooseDifficulty, bool& gamePlay)
{
    clear(rende);
    drawTexture(200, 75, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\EASY.bmp")), rende);
    drawTexture(200, 325, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\MEDIUM.bmp")), rende);
    drawTexture(200, 575, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\HARD.bmp")), rende);
    SDL_Event e;
    SDL_PollEvent(&e);
    if (e.type == SDL_MOUSEBUTTONDOWN)
    {
        difficultyButtonPress(se, ChooseDifficulty);
    }
    present(rende);
    gamePlay = 1;
}

