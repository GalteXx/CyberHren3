#include "All.h"

void clear(SDL_Renderer * rende)
{
	SDL_SetRenderDrawColor(rende, 0, 0, 0, 0);
	SDL_RenderClear(rende);
	SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);
}