#pragma once
#include <SDL.h>
#define ALL_H
#ifdef ALL_H


void update();
class Enemy
{
public:
	int speed;// ++ every 10 secs
	int coords[2];// x, y
	int size = 20;//px
};


#endif
