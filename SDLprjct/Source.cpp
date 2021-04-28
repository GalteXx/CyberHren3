#include "All.h"

void Enemy::kill(SDL_Renderer* rende, int& p, int& spawn)
{
    int a = 250, b = 550;
    x = rand() % (b - a + 1) + a;
    if (spawn == 0)
    {
        y = 700;
        spawn = 1;
    }
    else
    {
        y = 100;
        spawn = 0;
    }
}