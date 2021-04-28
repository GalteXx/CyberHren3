#include "All.h"
#include "tower.h"
#include "hole.h"



void hole_col(hole hol, Enemy& en, int& p, int& spawn, SDL2SoundEffects& se)
{
    if (en.x >= hol.x - hol.sizex / 2 && en.x <= hol.x + hol.sizex / 2 && en.y >= hol.y - hol.sizey && en.y <= hol.y + hol.sizey)
    {
        int a = 250, b = 550;
        en.x = rand() % (b - a + 1) + a;
        if (spawn == 0)
        {en.y = 700;
            spawn = 1;  }
        else
        {   en.y = 100;
            spawn = 0; }
        p += 50;
        se.playSoundEffect("C:\\SDL Game Assets\\HOLE.wav");
    }
}