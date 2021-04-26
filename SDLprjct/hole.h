#pragma once
#define HOLE_H
#include "All.h"
#ifdef HOLE_H

class hole
{
public:
	int x;
	int y;
	int sizex = 100;
	int sizey = 200;

	void update(SDL_Renderer* rende)
	{
		rc1(x, y, sizex, sizey, rende);
		//rc1(x, y, sizex / 2, sizey / 3, rende);
	}
};
#endif