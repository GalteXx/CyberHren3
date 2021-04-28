#include "All.h"

void points(int p_int, SDL_Renderer* rende)
{
	int len = num_len(p_int);
	/*int x = 500, x2 = 550, x3 = 600, x4 = 650;
	int y = 500, y2 = 550, y3 = 600, y4 = 650;*/
	int x = 500;
	int y = 500;
	int j = 0;
	string p_str = int_to_str(p_int);
	for (int i = 0; i < len; i++)
	{
		if (p_str[i] == '0')
			drawTexture(200 + j, 25, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\0.bmp")), rende);
		if (p_str[i] == '1')
			drawTexture(200 + j, 25, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\1.bmp")), rende);
		if (p_str[i] == '2')
			drawTexture(200 + j, 25, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\2.bmp")), rende);
		if (p_str[i] == '3')
			drawTexture(200 + j, 25, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\3.bmp")), rende);
		if (p_str[i] == '4')
			drawTexture(200 + j, 25, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\4.bmp")), rende);
		if (p_str[i] == '5')
			drawTexture(200 + j, 25, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\5.bmp")), rende);
		if (p_str[i] == '6')
			drawTexture(200 + j, 25, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\6.bmp")), rende);
		if (p_str[i] == '7')
			drawTexture(200 + j, 25, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\7.bmp")), rende);
		if (p_str[i] == '8')
			drawTexture(200 + j, 25, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\8.bmp")), rende);
		if (p_str[i] == '9')
			drawTexture(200 + j, 25, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\9.bmp")), rende);
		j +=50;
	}
}