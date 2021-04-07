#include "All.h"

void update(SDL_Renderer * rende)
{
	SDL_RenderPresent(rende);
	SDL_RenderClear(rende);
	SDL_Delay(10);
}