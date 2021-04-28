#include "All.h"
#include "tower.h"
#include "hole.h"

void FigItOut2(SDL2SoundEffects& se, bool& lose, bool& gamePlay, bool& ChooseDifficulty, std::vector<Enemy>& arr, int& spawn);
//void Updatet(std::vector<Enemy>& arr, SDL_Renderer* rende, int& p, const tower& tow, bool& lose, SDL2SoundEffects& se, int& spawn, std::vector<hole>& hol, int &zeroTime, int &currentTime);
void kill_execute(vector <Enemy>& arr, SDL_Renderer* rende, int& p, int& spawn, int& zeroTime, int& currentTime, SDL2SoundEffects& se);
void smoothDeploy(std::vector<Enemy>& arr, int& spawn);
void fillEnemyArr(std::vector<Enemy>& arr);
void doMenuThings(SDL_Renderer* rende, SDL2SoundEffects& se, bool& Menu);
void ChoosingDifficulty(SDL_Renderer* rende, SDL2SoundEffects& se, bool& ChooseDifficulty, bool& gamePlay);
void difficultyButtonPress(SDL2SoundEffects& se, bool& ChooseDifficulty);
void EXIT(SDL2SoundEffects& se);

void FigItOut1(SDL2SoundEffects& se, bool& lose, bool& gamePlay, std::vector<Enemy>& arr, int& spawn);

void doLosingStuff(SDL_Renderer* rende, SDL2SoundEffects& se, bool& lose, bool& gamePlay, std::vector<Enemy>& arr, int& spawn, bool& ChooseDifficulty);
