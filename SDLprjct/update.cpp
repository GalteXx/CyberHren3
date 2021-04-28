#include "All.h"
#include "tower.h"
#include "UI.h"
#include "hole.h"
void kill_execute(vector <Enemy>& arr, SDL_Renderer* rende, int& p, int& spawn, int& zeroTime, int& currentTime, SDL2SoundEffects& se);
void tower_col(Enemy& en, tower tow, bool& lose, SDL2SoundEffects& se, int& spawn);
void hole_col(hole hol, Enemy& en, int& p, int& spawn, SDL2SoundEffects& se);
void Update(std::vector<Enemy>& arr, SDL_Renderer* rende, int& p, tower& tow, bool& lose, SDL2SoundEffects& se, int& spawn, std::vector<hole>& hol, int &zeroTime, int &currentTime)
{
    clear(rende);
    SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);points(p, rende);
    SDL_Delay(Enemy::speed);
    SDL_Event e; SDL_PollEvent(&e);
    if (e.type == SDL_MOUSEBUTTONDOWN)
        kill_execute(arr, rende, p, spawn, zeroTime, currentTime, se);
    for (int i = 0; i < arr.size(); i++)
    {   arr[i].updt(rende, p);
        tower_col(arr[i], tow, lose, se, spawn);
        for (int j = 0; j < hol.size(); j++)
        {   hol[j].update(rende);
            hole_col(hol[j], arr[i], p, spawn, se);}}
    tow.updt(rende);
    UI::update(rende);
    present(rende);}