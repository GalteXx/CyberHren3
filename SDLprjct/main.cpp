#include "All.h"
#include "tower.h"
#include "UI.h"
#include "hole.h"
int m::x;
int m::y;
int Enemy::speed;
int tower::hp;//why do i have to do this...


void tower_col(Enemy &en, tower tow, bool &lose, SDL2SoundEffects &se)
{
    //int xpoint = 1;
    //int ypoint = 1;
    //
    //if (en.x + en.size >= tow.x - tow.size && en.x - en.size <= tow.x + tow.size)//if lefter
    //    xpoint--;
    //else if (en.x + en.size >= tow.x - tow.size && en.x - en.size >= tow.x + tow.size)//if righter
    //    xpoint--;
    //if (en.y + en.size >= tow.y - tow.size && en.y - en.size <= tow.y + tow.size)//if above
    //    ypoint--;
    //else if (en.y - en.size <= tow.y + tow.size && en.y + en.size > tow.y - tow.size)//if under
    //if (ypoint == 0 && xpoint == 0)
            //tower::hp--;*/
    if (en.x >= tow.x - tow.size / 2 && en.x <= tow.x + tow.size / 2 && en.y >= tow.y - tow.size / 2 && en.y <= tow.y + tow.size / 2)
    {
        int a = 100, b = 700;
        tower::hp--;
        if (tower::hp == 0)
            lose = 1;
        en.x = rand() % (b - a + 1) + a;
        en.y = rand() % (b - a + 1) + a;
        se.playSoundEffect("C:\\SDL Game Assets\\TOWER.wav");
    }
}

void hole_col(hole tow, Enemy &en)
{
    if (en.x >= tow.x - tow.sizex  && en.x <= tow.x + tow.sizex  && en.y >= tow.y - tow.sizey  && en.y <= tow.y + tow.sizey )
    {
        int a = 100, b = 700;
        en.x = rand() % (b - a + 1) + a;
        en.y = rand() % (b - a + 1) + a;
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
    cout << "Враги боятся мыши, используй это, чтобы не дать нашему городу пасть. Сталкивай врагов в пропасти." << endl;
    cout << "Если три врага попадут в город, то мы будем уничтожены. Вся надежда на тебя." << endl;
    vector <Enemy> arr;
    for (int i = 0; i < 10; i++)
    {
        Enemy en;
        arr.push_back(en);
    }
    vector <hole> hol;
    for (int i = 0; i < 4; i++)
    {
        hole holel;
        int a = 100, b = 700;
        holel.x = rand() % (b - a + 1) + a;
        holel.y = rand() % (b - a + 1) + a;
        hol.push_back(holel);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        int a = 100, b = 700;
        int x = rand() % (b - a + 1) + a;
        int y = rand() % (b - a + 1) + a;
        arr[i].x = x;
        arr[i].y = y;
    }
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
                    Enemy::speed = 15;
                }
                if (x <= 600 && x >= 200 && y >= 325 && y <= 475)
                {
                    se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                    ChooseDifficulty = 0;
                    Enemy::speed = 10;
                }
                if (x <= 600 && x >= 200 && y >= 575 && y <= 725)
                {
                    se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                    ChooseDifficulty = 0;
                    Enemy::speed = 5;
                }
            }
            present(rende);
            gamePlay = 1;
        }
        
        while (gamePlay)
        {
            clear(rende);
            SDL_SetRenderDrawColor(rende, 255, 255, 255, 255);
            SDL_Delay(Enemy::speed);
            for (int i = 0; i < arr.size(); i++)
            {
                arr[i].updt(rende);
                tower_col(arr[i], tow, lose, se);
                for (int i = 0; i < hol.size(); i++)
                {
                    hol[i].update(rende);
                    hole_col(hol[i], arr[i]);
                }
            }
            tow.updt(rende);
            UI::update(rende);
            present(rende);
            if (lose == 1)
            {
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
                        if (x <= 600 && x >= 200 && y >= 75 && y <= 225) // RETRY
                        {
                            se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                            lose = 0;
                            tower::hp = 3;
                            gamePlay = 1;
                        }
                        if (x <= 600 && x >= 200 && y >= 325 && y <= 475) // CHANGE DIFFICULTY
                        {
                            se.playSoundEffect("C:\\SDL Game Assets\\MENU.wav");
                            lose = 0;
                            gamePlay = 0;
                            tower::hp = 3;
                            ChooseDifficulty = 1;
                        }
                        if (x <= 600 && x >= 200 && y >= 575 && y <= 725) // EXIT
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

 