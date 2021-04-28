#include "All.h"

void Enemy::updt(SDL_Renderer* rende, int& p)
{
	run(rende);
	drawTexture(x, y, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\ENEMY.bmp")), rende);
}