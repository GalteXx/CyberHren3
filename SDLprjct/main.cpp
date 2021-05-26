#include "All.h"
#include "tower.h"
#include "UI.h"
#include "hole.h"
#include "main.h"
void Update(std::vector<Enemy>& arr, SDL_Renderer* rende, int& p, tower& tow, bool& lose, SDL2SoundEffects& se, int& spawn, std::vector<hole>& hol, int& zeroTime, int& currentTime); int m::x;
int m::y; int Enemy::speed; int tower::hp;
void tower_col(Enemy& en, tower tow, bool& lose, SDL2SoundEffects& se, int& spawn);
void hole_col(hole hol, Enemy& en, int& p, int& spawn, SDL2SoundEffects& se);
int main(int argc, char* args[]){
    SDL_Window* wind; SDL_Renderer* rende; tower tow;
    tower::hp = 3;
    SDL_CreateWindowAndRenderer(800, 800, 0, &wind, &rende); SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);
    bool GameRunning = true, Menu = true, ChooseDifficulty = true, lose = false, check_texture = 1, gamePlay = 1; setlocale(LC_ALL, "Russian");
    cout << "Враги боятся курсора. Используй его, чтобы не дать им добраться до центра.\nБольшие прямоугольники это пропасти, в них можно сталкивать врагов.\nЕсли враги доберутся до центра 3 раза, то игра окончится. \nНажми лкм, чтобы оттолкнуть врагов до края карты. \nЭтой способностью ты можешь пользоваться раз в 10 секунд." << endl;
    vector <Enemy> arr; fillEnemyArr(arr);
    vector <hole> hol; fillHoles(hol);
    int zeroTime = 0, currentTime = 0, spawn = 0, p = 0;
    smoothDeploy(arr, spawn);
    SDL2SoundEffects se;
    while(GameRunning){
        while (Menu)
            doMenuThings(rende, se, Menu);
        while (ChooseDifficulty)
            ChoosingDifficulty(rende, se, ChooseDifficulty, gamePlay);
        while (gamePlay){
            Update(arr, rende, p, tow, lose, se, spawn, hol, zeroTime, currentTime);
            if (lose == 1){p = 0; lose = 1;
                while (lose) doLosingStuff(rende, se, lose, gamePlay, arr, spawn, ChooseDifficulty); }}}
    SDL_Quit();
    return 0;}