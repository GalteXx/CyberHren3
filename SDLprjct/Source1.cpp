#include "All.h"

void Enemy::run(SDL_Renderer* rende)
{
    push(rende);
    int deltaX = abs(goal[0] - x);
    int deltaY = abs(goal[1] - y);
    int signX = x < goal[0] ? 1 : -1;
    int signY = y < goal[1] ? 1 : -1;
    int error = deltaX - deltaY;
    int error2 = error * 2;
    if (error2 > -deltaY)
    {
        error -= deltaY;
        x += signX;
    }
    if (error2 < deltaX)
    {
        error += deltaX;
        y += signY;
    }
}