#include "All.h"

void Enemy::push(SDL_Renderer* rende)
{
    SDL_Event event;
    bool GameRunning = true;
    SDL_PollEvent(&event);
    if (event.type == SDL_MOUSEMOTION)
    {
        int xe, ye;
        SDL_GetMouseState(&xe, &ye);
        m::setX(xe);
        m::setY(ye);
    }
    int difx = m::getX() - x;
    int dify = m::getY() - y;
    if (difx < 50 && difx > 0 && dify < 50 && dify > 0) // both pos
    {
        x -= difx;
        y -= dify;
    }
    else if (difx > -50 && difx < 0 && dify > -50 && dify < 0) // both neg
    {
        x -= difx;
        y -= dify;
    }
    else if (difx > -50 && difx < 0 && dify > 0 && dify < 50) // x neg y pos
    {
        x -= difx;
        y -= dify;
    }
    else if (difx > 0 && difx < 50 && dify > -50 && dify < 0) // x pos y neg
    {
        x -= difx;
        y -= dify;
    }
}