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
		//drawTexture(x, y, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\HOLE.bmp")), rende);
		SDL_SetRenderDrawColor(rende, 255, 148, 0, 255);
		rc1(x, y, sizex, sizey, rende);
		rc1(x, y, sizex - 1, sizey - 1, rende);
		rc1(x, y, sizex - 2, sizey - 2, rende);
		//rc1(x, y, sizex / 2, sizey / 3, rende);
	}
};
#endif