#pragma once
#include "All.h"



class tower
{
public:
	int size = 80;
	int x = 400;
	int y = 400;
	static int hp;


	void updt(SDL_Renderer* rende)
	{
		drawTexture(365, 365, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\TOWER.bmp")), rende);
	}
};