//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <iostream>

#include "Level.h"
#include "Level1.h"
#include "Level2.h"
#include "game.h"

#include <string>
#include <sstream>

//Screen dimension constants
const int WinWidth = 400;
const int WinHeight = 300;


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
        WinWidth, WinHeight,
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

    SDL_RenderClear(sdlRenderer);

    // draw a rect
    // 1. set color to cyan (r, g, b, a)
    SDL_SetRenderDrawColor(sdlRenderer, 255, 0, 0, 255);


    //Überschrift
    TTF_Font* Sans3 = TTF_OpenFont("arial.ttf", 17);
    SDL_Color White3 = { 0xff, 0xff, 0xff };

    std::ostringstream oss3;
    oss3 << " Halihalo";
    std::string var3 = oss3.str();



    SDL_Surface* surfaceMessage3 = TTF_RenderText_Solid(Sans3, var3.c_str(), White3);
    SDL_Texture* Message3 = SDL_CreateTextureFromSurface(sdlRenderer, surfaceMessage3);
    SDL_Rect Message_rect3 = { 100,50,surfaceMessage3->w,surfaceMessage3->h }; //create a rect
    SDL_RenderCopy(sdlRenderer, Message3, NULL, &Message_rect3);





    SDL_FreeSurface(surfaceMessage3);
    SDL_DestroyTexture(Message3);


    //Level 1

    std::ostringstream oss1;
    oss1 << "1";
    std::string var1 = oss1.str();



    SDL_Surface* surfaceMessage1 = TTF_RenderText_Solid(Sans3, var1.c_str(), White3);
    SDL_Texture* Message1 = SDL_CreateTextureFromSurface(sdlRenderer, surfaceMessage1);
    SDL_Rect Message_rect1 = { 20,70,surfaceMessage1->w,surfaceMessage1->h }; //create a rect
    SDL_RenderCopy(sdlRenderer, Message1, NULL, &Message_rect1);





    SDL_FreeSurface(surfaceMessage1);
    SDL_DestroyTexture(Message1);



    // and show result
    SDL_RenderPresent(sdlRenderer);

    // wait until exit
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
                SDL_GetWindowPosition(sdlWindow, &xwindow, &ywindow);
                xMouse = xMouse - xwindow;
                yMouse = yMouse - ywindow;
                std::cout << xMouse << " " << yMouse << std::endl;
            }
        }
    }
    // Testen
    // clean up
    SDL_DestroyWindow(sdlWindow);
    // finish
    SDL_Quit();
    TTF_Quit();
    return 0;
}


int main(int argc, char* args[])
{
    Game game;
    Level *level1= new Level1();
    /**if (!game.init(WinWidth, WinHeight,level1))
    {
        return -1;
    }**/
    int o = hi();
    return 0;
}




