#pragma once
#include <SDL.h>
#include <vector>
#include <cmath>
#define ALL_H
#ifdef ALL_H


void clear(SDL_Renderer* rende);
void present(SDL_Renderer* rende);
void rect(int x, int y, int xe, int ye, SDL_Renderer* rende);


class Enemy
{
public:
	int speed;// ++ every 10 secs
	//int coords[2];// x, y
	int x;
	int y;
	int size;//px
	void en_spawn(int x, int y, int size, SDL_Renderer* rende)
	{
		rect(x, y, size, size, rende);
		//update(rende);
	}
};



#endif
