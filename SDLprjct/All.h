#pragma once//ABOBUS
#include <SDL.h>
#include "m.h"
#include <vector>
#include <cmath>

using namespace std;
#define ALL_H
#ifdef ALL_H


void clear(SDL_Renderer* rende);
void present(SDL_Renderer* rende);
void xLine(int x, int y, int xe, SDL_Renderer* rende);
void sq(int x, int y, int l, SDL_Renderer* rende);




class Enemy
{
public:
	int speed = 50;// ++ every 10 secs
	int x = 0;
	int y = 0;
    int goal[2] = {400, 400};// x, y
	int size = 20;//px
	void updt(SDL_Renderer *rende)
	{
        //clear(rende);//delete this, after making nice update func
        run(rende);
        //push(rende);
        sq(x, y, size, rende);
        //present(rende);//this as well
	}
	void run( SDL_Renderer* rende)
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
    void push(SDL_Renderer *rende)
    {
        SDL_Event event;
        bool GameRunning = true;
        SDL_PollEvent(&event);
        //while (SDL_PollEvent(&event))
        //{
            if (event.type == SDL_MOUSEMOTION)
            {
                int xe, ye;
                SDL_GetMouseState(&xe, &ye);
                m::setX(xe);
                m::setY(ye);
                
            }
            int difx = m::getX() - x;
            int dify = m::getY() - y;
            if (difx < 50 && difx > 0 && dify < 50 && dify > 0) // оба положит
            {
                x -= difx;
                y -= dify;
                // dd
                present(rende);
                clear(rende);
            }
            else if (difx > -50 && difx < 0 && dify > -50 && dify < 0) // оба отриц
            {
                x -= difx;
                y -= dify;
                // dd
                present(rende);
                clear(rende);
            }
            else if (difx > -50 && difx < 0 && dify > 0 && dify < 50) // x отриц y положит
            {
                x -= difx;
                y -= dify;
                // dd
                present(rende);
                clear(rende);
            }
            else if (difx > 0 && difx < 50 && dify > -50 && dify < 0) // x положит y отриц
            {
                x -= difx;
                y -= dify;
                //dd
                present(rende);
                clear(rende);
            }
        //}
    }
};



//void spawnEn(vector <Enemy> arr);

#endif
