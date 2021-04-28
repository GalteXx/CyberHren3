#include "All.h"
#include "tower.h"
#include "hole.h"
void tower_col(Enemy& en, tower tow, bool& lose, SDL2SoundEffects& se, int& spawn)
{
    if (en.x >= tow.x - tow.size / 2 && en.x <= tow.x + tow.size / 2 && en.y >= tow.y - tow.size / 2 && en.y <= tow.y + tow.size / 2)
    {
        tower::hp--;
        if (tower::hp == 0)
            lose = 1;
        int a = 250, b = 550;
        en.x = rand() % (b - a + 1) + a;
        if (spawn == 0)
        {
            en.y = 700;
            spawn = 1;
        }
        else
        {
            en.y = 100;
            spawn = 0;
        }
        se.playSoundEffect("C:\\SDL Game Assets\\TOWER.wav");
    }
}