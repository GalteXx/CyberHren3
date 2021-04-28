#include "All.h"
void difficultyButtonPress(SDL2SoundEffects& se, bool& ChooseDifficulty)
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x <= 600 && x >= 200 && y >= 75 && y <= 225)
    {
        se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
        ChooseDifficulty = 0;
        Enemy::speed = 25;
    }
    if (x <= 600 && x >= 200 && y >= 325 && y <= 475)
    {
        se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
        ChooseDifficulty = 0;
        Enemy::speed = 20;
    }
    if (x <= 600 && x >= 200 && y >= 575 && y <= 725)
    {
        se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
        ChooseDifficulty = 0;
        Enemy::speed = 10;
    }
}