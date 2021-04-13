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
	int x;
	int y;
    int goal[2];// x, y
	int size = 20;//px
	void spawn(int x, int y, int size, SDL_Renderer* rende)
	{
		sq(x, y, size, rende);
	}
	void updt(SDL_Renderer *rende)
	{
        clear(rende);//delete this, after making nice update func
        run(goal[0], goal[1], rende);
        present(rende);//this as well
        
	}
	void run(int xe, int ye, SDL_Renderer* rende)
	{
        
            const int deltaX = abs(xe - x);
            const int deltaY = abs(ye - y);
            const int signX = x < xe ? 1 : -1;
            const int signY = y < ye ? 1 : -1;
            int error = deltaX - deltaY;
            while (x != xe || y != ye)
            {
                
                clear(rende);
                sq(x, y, size, rende);
                present(rende);
                SDL_Delay(speed);
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
	}
};



#endif
