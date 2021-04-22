#pragma once
#define UI_H
#include "All.h"
#ifdef UI_H

static class UI
{
public:


	static void update(SDL_Renderer* rende)
	{
		for (int i = 0; i < tower::hp; i++)
		{
			SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);
			sq(695 + 15 * i, 25, 15, rende);
		}
	}




};


#endif // UI_H
