#include "All.h"
#include "tower.h"
void FigItOut2(SDL2SoundEffects& se, bool& lose, bool& gamePlay, bool& ChooseDifficulty, std::vector<Enemy>& arr, int& spawn)
{
    se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
    lose = 0;
    gamePlay = 0;
    tower::hp = 3;
    ChooseDifficulty = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        tower::hp = 3;
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
        }}}