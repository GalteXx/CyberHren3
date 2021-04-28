#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include "m.h"
#include "SDL2SoundEffects.h"
#include <vector>
#include <iostream>
using namespace std;
#define ALL_H
#ifdef ALL_H
class SpriteData
{public:
    int w = 0;
    int h = 0;
    vector <vector<SDL_Color> > texture;};
void clear(SDL_Renderer* rende);
void present(SDL_Renderer* rende);
void xLine(int x, int y, int xe, SDL_Renderer* rende);
void sq(int x, int y, int l, SDL_Renderer* rende);
void rc1(int x, int y, int w, int h, SDL_Renderer* rende);
void rc2(int x, int y, int w, int h, SDL_Renderer* rende);
Uint32 getpixel(SDL_Surface* surface, int x, int y);
SpriteData loadTexture(char* path);
void drawTexture(int x, int y, SpriteData pic, SDL_Renderer* rende);
void points(int p, SDL_Renderer* rende);
int num_len(int a);
string int_to_str(int a);
void redrawGrass(int x, int y, int size, SDL_Renderer* rende);
class Enemy
{public:
	static int speed;// ++ every 10 secs
	int x = 0;
	int y = 0;
    int goal[2] = {400, 400};// x, y
	int size = 20;//px
    void updt(SDL_Renderer* rende, int& p);
    void run(SDL_Renderer* rende);
    void push(SDL_Renderer* rende);
    void kill(SDL_Renderer* rende, int& p, int& spawn);};
#endif
