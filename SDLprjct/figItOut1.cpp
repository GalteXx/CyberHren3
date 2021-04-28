#include "All.h"
#include "tower.h"
void FigItOut1(SDL2SoundEffects& se, bool& lose, bool& gamePlay, std::vector<Enemy>& arr, int& spawn)
{
    se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
    lose = 0;
    tower::hp = 3;
    gamePlay = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        int a = 250, b = 550;
        arr[i].x = rand() % (b - a + 1) + a;
        if (spawn == 0)
        {
            arr[i].y = 700;
            spawn = 1;
        }
        else
        {
            arr[i].y = 100;
            spawn = 0;
        }
    }
}