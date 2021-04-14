#pragma once
#include <SDL.h>
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
        run(goal[0], goal[1], rende);
        push(rende);
        sq(x, y, size, rende);
        //present(rende);//this as well
	}
	void run(int xe, int ye, SDL_Renderer* rende)
	{
        
            /*int deltaX = abs(xe - x);
            int deltaY = abs(ye - y);
            int signX = x < xe ? 1 : -1;
            int signY = y < ye ? 1 : -1;
            int error = deltaX - deltaY;
            while (x != xe || y != ye)
            {*/
             
                //push(rende);
                //SDL_Event event_stop;
                //int xMouse = 0, yMouse = 0;
                //SDL_PollEvent(&event_stop);
                //if (event_stop.type == SDL_MOUSEMOTION)
                //{
                //    SDL_GetMouseState(&xMouse, &yMouse);
                //    if (abs(xMouse - x) < 50 && abs(yMouse - x) < 50)
                //        push(rende);7
                //}
                int deltaX = abs(xe - x);
                int deltaY = abs(ye - y);
                int signX = x < xe ? 1 : -1;
                int signY = y < ye ? 1 : -1;
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
        int xMouse = 0, yMouse = 0;
        bool GameRunning = true;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&xMouse, &yMouse);
            }
            int difx = xMouse - x;
            int dify = yMouse - y;
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
        }
    }
};


//void spawnEn(vector <Enemy> arr);

#endif
