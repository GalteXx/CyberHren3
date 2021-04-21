#include "All.h"
#include "tower.h"
#include "UI.h"

int m::x;
int m::y;
int Enemy::speed;
int tower::hp;//why do i have to do this...


void collide(Enemy &en, tower tow)
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
        tower::hp--;
        en.x = 100;
        en.y = 200;//random values here :)
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
    bool GameRunning = true, Menu = true, ChooseDifficulty = true;
    bool Easy = false, Medium = false, Hard = false;
    setlocale(LC_ALL, "Russian");
    cout << "Враги боятся мыши, используй это, чтобы не дать нашему городу пасть. Сталкивай врагов в пропасти." << endl;
    cout << "Если три врага попадут в город, то мы будем уничтожены. Вся надежда на тебя." << endl;
    
    vector <Enemy> arr;
    for (int i = 0; i < 10; i++)
    {
        Enemy en;
        arr.push_back(en);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i].x = i * 50;
        arr[i].y = i * 10;
    }

    while(GameRunning)
    {
        while (Menu)
        {
            clear(rende);
            rc2(200, 200, 400, 150, rende);
            rc2(200, 450, 400, 150, rende);
            SDL_Event e;
            SDL_PollEvent (&e);
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x <= 600 && x >= 200 && y >= 200 && y <= 350)
                    Menu = 0;
                if (x <= 600 && x >= 200 && y >= 450 && y <= 600)
                    SDL_Quit();
            }
            present(rende);
        }
        while (ChooseDifficulty)
        {
            clear(rende);
            rc2(200, 75, 400, 150, rende);
            rc2(200, 325, 400, 150, rende);
            rc2(200, 575, 400, 150, rende);
            SDL_Event e;
            SDL_PollEvent(&e);
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x <= 600 && x >= 200 && y >= 75 && y <= 225)
                {
                    ChooseDifficulty = 0;
                    Enemy::speed = 15;
                }
                if (x <= 600 && x >= 200 && y >= 325 && y <= 475)
                {
                    ChooseDifficulty = 0;
                    Enemy::speed = 10;
                }
                if (x <= 600 && x >= 200 && y >= 575 && y <= 725)
                {
                    ChooseDifficulty = 0;
                    Enemy::speed = 5;
                }
            }
            present(rende);
        }
        rc1(400, 400, 100, 100, rende);
        SDL_Delay(Enemy::speed);
        clear(rende);
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i].updt(rende);
            collide(arr[i], tow);
            
        }
        tow.updt(rende);
        UI::update(rende);
        present(rende);
    }
    //int x = 100;
    //int y = 150;
    ////char* test1 = "C:\\button0.bmp";
    //SpriteData pic = loadTexture(const_cast<char*>("C:\\Users\\georg\\Documents\\GitHub\\CyberHren3\\button1.bmp"));
    //clear(rende);
    //drawTexture(x, y, pic, rende);

    ////rc(400, 400, 100, 50, rende);
    //
    //present(rende);
    //SDL_Delay(500);
    SDL_Quit();
    return 0;
}

