#include "All.h"
#include "hole.h"

void fillHoles(std::vector<hole>& hol)
{
    hole h;
    h.x = 75;
    h.y = 400;
    hol.push_back(h);
    h.x = 725;
    h.y = 400;
    hol.push_back(h);
}