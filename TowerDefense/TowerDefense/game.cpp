#include "game.h"

#include <iostream>





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
    SDL_SetRenderDrawColor(m_renderer, 0x00, 0xa0, 0x00, 0x00);
    // 2. clear all
    SDL_RenderClear(m_renderer);

    // draw a rect
    // 1. set color to cyan (r, g, b, a)
    SDL_SetRenderDrawColor(m_renderer, 0xa0, 0xa0, 0xa0, 0xff);
    // specify recht
    // clear background: 1. specify rect
    SDL_Rect sdlRect = { 100, 50, 20, 20 };
    SDL_Rect sdlRect2 = { 150, 50, 30, 30 };
    SDL_RenderFillRect(m_renderer, &sdlRect);
    SDL_RenderFillRect(m_renderer, &sdlRect2);


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




void Game::loop() {

}
void Game::cleanup() {

}
