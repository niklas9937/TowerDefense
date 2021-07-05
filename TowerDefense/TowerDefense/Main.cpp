//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <iostream>

#include "Level.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "game.h"

#include <string>
#include <sstream>

//Screen dimension constants
const int WinWidth1 = 200;
const int WinHeight1 = 150;


const int WinWidth = 800;
const int WinHeight = 800;


int hi()
{
    // init sdl with video subsystem only and check if succeeded
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return -1;
    }
    // create window
    TTF_Init();
    SDL_Window* sdlWindow = SDL_CreateWindow("SDL Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WinWidth1, WinHeight1,
        SDL_WINDOW_SHOWN);
    // and check if succeeded
    if (!sdlWindow)
    {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        return -2;
    }

    // try some gfx, prefer renderer
    SDL_Renderer* sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, 0);

    // attention... now leaving out checks

    SDL_SetRenderDrawColor(sdlRenderer, 32, 32, 32, 255);

    SDL_RenderClear(sdlRenderer);

    // draw a rect
    // 1. set color to cyan (r, g, b, a)
    SDL_RenderPresent(sdlRenderer);


    //Überschrift
    TTF_Font* Sans3 = TTF_OpenFont("arial.ttf", 17);
    SDL_Color White3 = { 0xff, 0xff, 0xff };

    std::ostringstream oss0;
    oss0 << "Tower Defense ";
    std::string var0 = oss0.str();



    SDL_Surface* surfaceMessage0 = TTF_RenderText_Solid(Sans3, var0.c_str(), White3);
    SDL_Texture* Message0 = SDL_CreateTextureFromSurface(sdlRenderer, surfaceMessage0);
    SDL_Rect Message_rect0 = { 45,50,surfaceMessage0->w,surfaceMessage0->h }; //create a rect
    SDL_RenderCopy(sdlRenderer, Message0, NULL, &Message_rect0);





    SDL_FreeSurface(surfaceMessage0);
    SDL_DestroyTexture(Message0);


    //Level 1
    SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);

    std::ostringstream oss1;
    oss1 << "  1  ";
    std::string var1 = oss1.str();



    SDL_Surface* surfaceMessage1 = TTF_RenderText_Solid(Sans3, var1.c_str(), White3);
    SDL_Texture* Message1 = SDL_CreateTextureFromSurface(sdlRenderer, surfaceMessage1);
    SDL_Rect Message_rect1 = { 30,100,surfaceMessage1->w,surfaceMessage1->h }; //create a rect
    SDL_RenderFillRect(sdlRenderer, &Message_rect1);
    SDL_RenderCopy(sdlRenderer, Message1, NULL, &Message_rect1);

  

    SDL_RenderPresent(sdlRenderer);

    SDL_FreeSurface(surfaceMessage1);
    SDL_DestroyTexture(Message1);


    //Level 2

    std::ostringstream oss2;
    oss2 << "  2  ";
    std::string var2 = oss2.str();



    SDL_Surface* surfaceMessage2 = TTF_RenderText_Solid(Sans3, var2.c_str(), White3);
    SDL_Texture* Message2 = SDL_CreateTextureFromSurface(sdlRenderer, surfaceMessage2);
    SDL_Rect Message_rect2 = { 70,100,surfaceMessage2->w,surfaceMessage2->h }; //create a rect
    SDL_RenderFillRect(sdlRenderer, &Message_rect2);
    SDL_RenderCopy(sdlRenderer, Message2, NULL, &Message_rect2);



    SDL_RenderPresent(sdlRenderer);

    SDL_FreeSurface(surfaceMessage2);
    SDL_DestroyTexture(Message2);


    //Level 3

    std::ostringstream oss3;
    oss3 << "  3  ";
    std::string var3 = oss3.str();



    SDL_Surface* surfaceMessage3 = TTF_RenderText_Solid(Sans3, var3.c_str(), White3);
    SDL_Texture* Message3 = SDL_CreateTextureFromSurface(sdlRenderer, surfaceMessage3);
    SDL_Rect Message_rect3 = { 110,100,surfaceMessage3->w,surfaceMessage3->h }; //create a rect
    SDL_RenderFillRect(sdlRenderer, &Message_rect3);
    SDL_RenderCopy(sdlRenderer, Message3, NULL, &Message_rect3);



    SDL_RenderPresent(sdlRenderer);

    SDL_FreeSurface(surfaceMessage3);
    SDL_DestroyTexture(Message3);







    SDL_RenderPresent(sdlRenderer);

    // wait until exit
    bool quit = false;
    SDL_Event e;
    int xMouse, yMouse;
    int xwindow, ywindow;
    int auswahl = -1;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                SDL_GetGlobalMouseState(&xMouse, &yMouse);
                SDL_GetWindowPosition(sdlWindow, &xwindow, &ywindow);
                xMouse = xMouse - xwindow;
                yMouse = yMouse - ywindow;

                if ((xMouse >= Message_rect1.x and xMouse <= (Message_rect1.w + Message_rect1.x)) and yMouse >= Message_rect1.y and (yMouse <= (Message_rect1.y + Message_rect1.h)))
                {
                    auswahl = 1;
                    quit = true;
                }
                if ((xMouse >= Message_rect2.x and xMouse <= (Message_rect2.w + Message_rect2.x)) and yMouse >= Message_rect2.y and (yMouse <= (Message_rect2.y + Message_rect2.h)))
                {
                    auswahl = 2;
                    quit = true;
                }
                if ((xMouse >= Message_rect3.x and xMouse <= (Message_rect3.w + Message_rect3.x)) and yMouse >= Message_rect3.y and (yMouse <= (Message_rect3.y + Message_rect3.h)))
                {
                    auswahl = 3;
                    quit = true;
                }

            }
        }
    }
    // Testen
    // clean up
    SDL_DestroyWindow(sdlWindow);
    // finish
    TTF_CloseFont(Sans3);
    SDL_Quit();
    TTF_Quit();
    
    return auswahl;
}


int main(int argc, char* args[])
{
    bool weiter = true;
    while (weiter)
    {
        int levelauswahl = hi();
        Game game;
        std::cout << "HIHI" << std::endl;
        if (levelauswahl == 1)
        {
            Level* level1 = new Level1();
            if (!game.init(WinWidth, WinHeight, level1))
            {
                weiter = false;
                return -1;
            }
        }
        else if (levelauswahl == 2)
        {
            Level* level1 = new Level2();
            if (!game.init(WinWidth, WinHeight, level1))
            {
                weiter = false;
                return -1;
            }
        }
        else if (levelauswahl == 3)
        {
            Level* level3 = new Level3();
            if (!game.init(WinWidth, WinHeight, level3))
            {
                weiter = false;
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }
    //Level *level1= new Level1();
    /**if (!game.init(WinWidth, WinHeight,level1))
    {
        return -1;
    }**/
    //int o = hi();
    return 0;
}




