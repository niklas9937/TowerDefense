
#include <iostream>
#include "game.h"





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
    field[24][19] = weg;

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

    /*
    SDL_Rect sdlRect = { 0, 0, 32, 32 };
    SDL_Rect sdlRect2 = { 150, 50, 35, 35 };
    SDL_RenderFillRect(m_renderer, &sdlRect);
    SDL_RenderFillRect(m_renderer, &sdlRect2);
    */

    // and show result
    SDL_RenderPresent(m_renderer);

    bool quit = false;
    SDL_Event e;
    int xMouse, yMouse;
    int xwindow, ywindow;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            if (SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                SDL_GetGlobalMouseState(&xMouse, &yMouse);
                SDL_GetWindowPosition(m_window, &xwindow, &ywindow);
                xMouse = xMouse - xwindow;
                yMouse = yMouse - ywindow;
                std::cout << xMouse << " " << yMouse << std::endl;
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

    towerArray[0] = defense;
    return 0;
}


void Game::loop() {

}
void Game::cleanup() {

}
