#include "All.h"

void smoothDeploy(std::vector<Enemy>& arr, int& spawn)
{
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
    spawn = 0;
}