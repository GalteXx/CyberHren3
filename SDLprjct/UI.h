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
			drawTexture(500 + 50 * i, 20, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\HEART.bmp")), rende);
		}
	}
};
#endif // UI_H
