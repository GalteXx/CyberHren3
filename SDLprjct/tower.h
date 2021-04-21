#include "All.h"
class tower
{
public:
	int size = 80;
	int x = 400;
	int y = 400;
	int hp = 3;


	void updt(SDL_Renderer* rende)
	{
		sq(x, y, size, rende);
		sq(x, y, size / 2, rende);
	}
	
};