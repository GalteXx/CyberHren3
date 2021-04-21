#pragma once
#define UI_H
#include "All.h"
#ifdef UI_H

static class UI
{
public:
		
	int hp = 3;


	void update(SDL_Renderer* rende)
	{
		for (int i = 0; i < hp, i++)
		{
			sq(295 + 15 * i, 25, 30, rende);
		}
	}




};


#endif // UI_H
