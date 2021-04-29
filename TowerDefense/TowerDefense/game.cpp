
#include <iostream>
#include "game.h"

#include <string>

using namespace std;

Game::Game()
{
}
int Game::init(int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return false;
    }
    height = height;
    width = height;

    m_window = SDL_CreateWindow("SDL Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width, height,
        SDL_WINDOW_SHOWN);

    if (!m_window)
    {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        return false;
    }
    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
    // 2. clear all
    SDL_RenderClear(m_renderer);

    // draw a rect
    // 1. set color to cyan (r, g, b, a)
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    // specify recht
    // clear background: 1. specify rect
    
    field[0][3] = weg;
    field[1][3] = weg;
    field[2][3] = weg;
    field[3][3] = weg;
    field[4][3] = weg;
    field[5][3] = weg;
    field[6][3] = weg;
    field[7][3] = weg;
    field[8][3] = weg;
    field[9][3] = weg;
    field[10][3] = weg;
    field[11][3] = weg;
    field[11][4] = weg;
    field[12][4] = weg;
    field[13][4] = weg;
    field[14][4] = weg;
    field[14][5] = weg;
    field[14][6] = weg;
    field[15][6] = weg;
    field[16][6] = weg;
    field[17][6] = weg;
    field[18][6] = weg;
    field[19][6] = weg;
    field[20][6] = weg;
    field[21][6] = weg;
    field[21][7] = weg;
    field[21][8] = weg;
    field[21][9] = weg;



    field[0][10] = weg;
    field[1][10] = weg;
    field[2][10] = weg;
    field[3][10] = weg;
    field[3][11] = weg;
    field[4][11] = weg;
    field[5][11] = weg;
    field[5][10] = weg;
    field[6][10] = weg;
    field[7][10] = weg;
    field[8][10] = weg;
    field[9][10] = weg;
    field[10][10] = weg;
    field[11][10] = weg;
    field[12][10] = weg;
    field[13][10] = weg;
    field[13][11] = weg;
    field[14][11] = weg;
    field[15][11] = weg;
    field[16][11] = weg;
    field[17][11] = weg;
    field[17][10] = weg;
    field[18][10] = weg;
    field[19][10] = weg;
    field[20][10] = weg;

    field[0][14] = weg;
    field[1][14] = weg;
    field[2][14] = weg;
    field[2][15] = weg;
    field[2][16] = weg;
    field[3][16] = weg;
    field[4][16] = weg;
    field[5][16] = weg;
    field[5][17] = weg;
    field[5][18] = weg;
    field[6][18] = weg;
    field[7][18] = weg;
    field[8][18] = weg;
    field[9][18] = weg;
    field[9][17] = weg;
    field[9][16] = weg;
    field[10][16] = weg;
    field[11][16] = weg;
    field[12][16] = weg;
    field[13][16] = weg;
    field[14][16] = weg;
    field[15][16] = weg;
    field[16][16] = weg;
    field[16][15] = weg;
    field[16][14] = weg;
    field[17][14] = weg;
    field[18][14] = weg;
    field[19][14] = weg;
    field[20][14] = weg;
    field[21][14] = weg;
    field[21][13] = weg;
    field[21][12] = weg;
    field[21][11] = weg;

    field[21][10] = burg;
    for(int i = 0; i< xField; i++)
    {
        for (int j = 0; j < yField; j++)
        {
            Terrain hilf = field[i][j];
            switch (hilf)
            {
            case weg: SDL_SetRenderDrawColor(m_renderer, 205, 179, 139, 255);  break;
            case gras: SDL_SetRenderDrawColor(m_renderer, 0, 153, 0, 255); break;
            case burg: SDL_SetRenderDrawColor(m_renderer, 131, 139, 139, 255);  break;
            }
            SDL_Rect sdlRect = { (i*32), (j * 32), 32, 32 };
            SDL_RenderFillRect(m_renderer, &sdlRect);
            SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 0xff);
        }
    }

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 0xff);

    towers[0][0] = small;
    towers[1][0] = medium;
    towers[2][0] = large;
    towers[0][1] = fire;
    towers[1][1] = water;
    towers[2][1] = wind;
    towers[0][2] = lightning;
    towers[1][2] = plant;
    towers[2][2] = toxic;

    int hX = 21;
    int hY = 21;
    int indexBild = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            SDL_Rect sdlRect = { ((hX+i) * 32), ((hY+j) * 32), 32, 32 };
            SDL_RenderDrawRect(m_renderer, &sdlRect);
            std::cout << towers[i][j];
            SDL_Surface* image = SDL_LoadBMP("small.bmp");
            switch (indexBild)
            {
                case 1: image = SDL_LoadBMP("small.bmp"); break;
                case 2: image = SDL_LoadBMP("medium.bmp"); break;
                case 3: image = SDL_LoadBMP("large.bmp"); break;
                case 4: image = SDL_LoadBMP("fire.bmp"); break;
                case 5: image = SDL_LoadBMP("water.bmp"); break;
                case 6: image = SDL_LoadBMP("wind.bmp"); break;
                case 7: image = SDL_LoadBMP("lightning.bmp"); break;
                case 8: image = SDL_LoadBMP("plant.bmp"); break;
                case 9: image = SDL_LoadBMP("toxic.bmp"); break;
            }

            SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, image);
            SDL_RenderCopy(m_renderer, texture, NULL,&sdlRect);
            SDL_RenderPresent(m_renderer);
            indexBild += 1;
        }
    }

    SDL_RenderPresent(m_renderer);

    bool quit = false;
    SDL_Event e;
    int xMouse, yMouse;
    int xwindow, ywindow;
    AffinityType selected = nothing;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                SDL_GetGlobalMouseState(&xMouse, &yMouse);
                SDL_GetWindowPosition(m_window, &xwindow, &ywindow);
                xMouse = xMouse - xwindow;
                yMouse = yMouse - ywindow;
                std::cout << xMouse << " " << yMouse << std::endl;
                xMouse = xMouse / 32;
                int x = (int)xMouse;
                yMouse = yMouse / 32;
                int y = (int)yMouse;



                if (x < xField && y < yField)
                {
                    if (field[x][y] == gras && selected != nothing)
                    {
                        int h = setDefense(x, y, selected);
                        SDL_SetRenderDrawColor(m_renderer, 100, 100, 100, 0xff);
                        SDL_Rect sdlRect = { (x * 32), (y * 32), 32, 32 };
                        //SDL_RenderFillRect(m_renderer, &sdlRect);

                        SDL_Surface* image = SDL_LoadBMP("small.bmp");
                        switch (selected)
                        {
                        case 1: image = SDL_LoadBMP("small.bmp"); break;
                        case 2: image = SDL_LoadBMP("medium.bmp"); break;
                        case 3: image = SDL_LoadBMP("large.bmp"); break;
                        case 4: image = SDL_LoadBMP("fire.bmp"); break;
                        case 5: image = SDL_LoadBMP("water.bmp"); break;
                        case 6: image = SDL_LoadBMP("wind.bmp"); break;
                        case 7: image = SDL_LoadBMP("lightning.bmp"); break;
                        case 8: image = SDL_LoadBMP("plant.bmp"); break;
                        case 9: image = SDL_LoadBMP("toxic.bmp"); break;
                        }

                        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, image);
                        SDL_RenderCopy(m_renderer, texture, NULL, &sdlRect);



                        SDL_RenderPresent(m_renderer);
                    }
                }
                else
                {
                    x = x - 21;
                    y = y - 21;
                    selected = towers[x][y];

                }

                
            }
            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_RIGHT)
            {
                selected = nothing;
            }
        }
    }
    
    // Testen
    // clean up
    SDL_DestroyWindow(m_window);
    // finish
    SDL_Quit();

    return 0;
}

int Game::setDefense(int xC, int yC, AffinityType type) {
    Point p; 
    p.x = xC;
    p.y = yC;
    Defense defense(type,p);

    towerArray[indexTowerArray] = defense;
    indexTowerArray += 1;


    return 0;
}


void Game::loop() {

}
void Game::cleanup() {

}
