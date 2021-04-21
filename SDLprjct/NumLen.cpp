#include "All.h"

int num_len(int a)
{

    if (a == 0)
    {
        return (1);
    }
    int amount = 0;
    while (a > 0)
    {
        a = a / 10;
        amount += 1;
    }
    return (amount);

}