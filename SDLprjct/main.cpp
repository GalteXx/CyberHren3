#include "All.h"
#include "tower.h"
#include "UI.h"
#include "hole.h"
int m::x;
int m::y;
int Enemy::speed;
int tower::hp;//why do i have to do this...


void tower_col(Enemy &en, tower tow, bool &lose, SDL2SoundEffects &se, int &spawn)
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

void hole_col(hole hol, Enemy &en, int &p, int &spawn, SDL2SoundEffects &se)
{
    if (en.x >= hol.x - hol.sizex/2  && en.x <= hol.x + hol.sizex/2  && en.y >= hol.y - hol.sizey  && en.y <= hol.y + hol.sizey )
    {
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
        p += 50;
        se.playSoundEffect("C:\\SDL Game Assets\\HOLE.wav");
    }
}

void kill_execute(vector <Enemy>& arr, SDL_Renderer* rende, int &p, int &spawn, int &zeroTime, int &currentTime, SDL2SoundEffects& se)
{
    currentTime = SDL_GetTicks();
    if (currentTime - zeroTime > 10000) {
        zeroTime += 10000;
        for (int i = 0; i < arr.size(); i++)
            arr[i].kill(rende, p, spawn);
        se.playSoundEffect("C:\\SDL Game Assets\\KILL.wav");
    }
}

int main(int argc, char* args[])
{
    SDL_Window* wind;
    SDL_Renderer* rende;
    tower tow;
    tower::hp = 3;
    SDL_CreateWindowAndRenderer(800, 800, 0, &wind, &rende);
    SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);
    bool GameRunning = true, Menu = true, ChooseDifficulty = true, lose = false, check_texture = 1, gamePlay = 1;
    setlocale(LC_ALL, "Russian");
    cout << "Враги боятся курсора. Используй его, чтобы не дать им добраться до центра." << endl;
    cout << "Большие прямоугольники это пропасти, в них можно сталкивать врагов." << endl;
    cout << "Если враги доберутся до центра 3 раза, то игра окончится." << endl;

    int p = 0; // points
    vector <Enemy> arr;
    for (int i = 0; i < 7; i++)
    {
        Enemy en;
        arr.push_back(en);
    }
    vector <hole> hol;
    hole h;
    h.x = 75;
    h.y = 400;
    hol.push_back(h);
    h.x = 725;
    h.y = 400;
    hol.push_back(h);
    /*a = 100, b = 200;
    h.x = rand() % (200 - 100 + 1) + 100;
    h.y = rand() % (600 - 200 + 1) + 200;
    hol.push_back(h);*/
    int zeroTime = 0, currentTime = 0;
    int spawn = 0;
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
    SDL2SoundEffects se;
    while(GameRunning)
    {
        while (Menu)
        {
            clear(rende);
            drawTexture(100, 70, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\LOGO.bmp")), rende);
            drawTexture(200, 300, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\START.bmp")), rende);
            drawTexture(200, 550, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\EXIT.bmp")), rende);
            SDL_Event e;
            SDL_PollEvent (&e);
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x <= 600 && x >= 200 && y >= 300 && y <= 450)
                {
                    se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                    Menu = 0;
                }
                if (x <= 600 && x >= 200 && y >= 550 && y <= 700)
                {
                    se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                    SDL_Delay(300);
                    SDL_Quit();
                }
            }
            present(rende);
        }
        while (ChooseDifficulty)
        {
            clear(rende);
            drawTexture(200, 75, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\EASY.bmp")), rende);
            drawTexture(200, 325, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\MEDIUM.bmp")), rende);
            drawTexture(200, 575, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\HARD.bmp")), rende);
            SDL_Event e;
            SDL_PollEvent(&e);
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x <= 600 && x >= 200 && y >= 75 && y <= 225)
                {
                    se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                    ChooseDifficulty = 0;
                    Enemy::speed = 25;
                }
                if (x <= 600 && x >= 200 && y >= 325 && y <= 475)
                {
                    se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                    ChooseDifficulty = 0;
                    Enemy::speed = 20;
                }
                if (x <= 600 && x >= 200 && y >= 575 && y <= 725)
                {
                    se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                    ChooseDifficulty = 0;
                    Enemy::speed = 10;
                }
            }
            present(rende);
            gamePlay = 1;
        }

        while (gamePlay)
        {
            clear(rende);
            SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);
            points(p, rende);
            SDL_Delay(Enemy::speed); 
            SDL_Event e;
            SDL_PollEvent(&e);
            if (e.type == SDL_MOUSEBUTTONDOWN)
                kill_execute(arr, rende, p, spawn, zeroTime, currentTime, se);
            for (int i = 0; i < arr.size(); i++)
            {
                arr[i].updt(rende, p);
                tower_col(arr[i], tow, lose, se, spawn);
                for (int j = 0; j < hol.size(); j++)
                {
                    hol[j].update(rende);
                    hole_col(hol[j], arr[i], p, spawn, se);
                }
            }
            tow.updt(rende);
            UI::update(rende);
            present(rende);
            if (lose == 1)
            {
                p = 0;
                lose = 1;
                while (lose)
                {
                    clear(rende);
                    drawTexture(200, 70, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\GAMEOVER.bmp")), rende);
                    drawTexture(200, 250, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\RETRY.bmp")), rende);
                    drawTexture(200, 425, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\CHANGEDIFFICULTY.bmp")), rende);
                    drawTexture(200, 600, loadTexture(const_cast<char*>("C:\\SDL Game Assets\\EXIT.bmp")), rende);
                    SDL_Event e;
                    SDL_PollEvent(&e);
                    if (e.type == SDL_MOUSEBUTTONDOWN)
                    {
                        int x, y;
                        SDL_GetMouseState(&x, &y);
                        if (x <= 600 && x >= 200 && y >= 250 && y <= 400) // RETRY
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
                        if (x <= 600 && x >= 200 && y >= 425 && y <= 575) // CHANGE DIFFICULTY
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
                                }
                            }
                        }
                        if (x <= 600 && x >= 200 && y >= 600 && y <= 750) // EXIT
                        {
                            se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                            SDL_Delay(300);
                            SDL_Quit();
                        }
                    }
                    present(rende);
                }
            }
        }

    }
    SDL_Quit();
    return 0;
}
