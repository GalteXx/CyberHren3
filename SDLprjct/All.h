#pragma once
#include <SDL.h>
#include "m.h"
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
#define ALL_H
#ifdef ALL_H

class SpriteData
{
public:
    int w = 0;
    int h = 0;
    vector <vector<SDL_Color> > texture;
};

void clear(SDL_Renderer* rende);
void present(SDL_Renderer* rende);
void xLine(int x, int y, int xe, SDL_Renderer* rende);
void sq(int x, int y, int l, SDL_Renderer* rende);
void rc1(int x, int y, int w, int h, SDL_Renderer* rende);
void rc2(int x, int y, int w, int h, SDL_Renderer* rende);
Uint32 getpixel(SDL_Surface* surface, int x, int y);
SpriteData loadTexture(char* path);
void drawTexture(int x, int y, SpriteData pic, SDL_Renderer* rende);
void points(int p, SDL_Renderer* rende);
int num_len(int a);
string int_to_str(int a);
void redrawGrass(int x, int y, int size, SDL_Renderer* rende);
//void tower_col(Enemy& en, tower tow);




class Enemy
{
public:
	static int speed;// ++ every 10 secs
	int x = 0;
	int y = 0;
    int goal[2] = {400, 400};// x, y
	int size = 20;//px
	void updt(SDL_Renderer *rende)
	{
        run(rende);
        drawTexture(x, y, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\ENEMY.bmp")), rende);
        //(x, y, size, rende);
	}
	void run(SDL_Renderer* rende)
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

};

#endif
