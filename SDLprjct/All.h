#pragma once
#include <SDL.h>
#include <vector>
#include <cmath>
#define ALL_H
#ifdef ALL_H


void update(SDL_Renderer* rende);


class Enemy
{
public:
	int speed;// ++ every 10 secs
	//int coords[2];// x, y
	int x;
	int y;
	int size = 20;//px
};



#endif
