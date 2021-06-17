
#include <iostream>
#include "game.h"
#include <string>
#include <sstream>

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
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);

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
    m_renderer2 = SDL_CreateRenderer(m_window, 0, 0);
    m_background = NULL;
    m_background = loadTexture("Hintergrund.bmp");

    if (m_background == NULL )
    {
        printf("Failed to load background texture image!\n");
    }

    loadField();
    //loadLevel();
    //int k = setEnemy(0, 96, goblin);
    //k = setEnemy(0, 96, goblin);
    //k = setEnemy(0, 320, goblin);
    //k = setEnemy(0, 448, goblin);
    //render();
    

    

    bool quit = false;
    SDL_Event e;
    int xMouse, yMouse;
    int xwindow, ywindow;
    AffinityType selected = AffinityType::nothing;
    while (!quit) {
        unsigned int startTime = SDL_GetTicks();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            if (e.type == SDL_MOUSEMOTION) {
            
                SDL_GetGlobalMouseState(&xMouse, &yMouse);
                SDL_GetWindowPosition(m_window, &xwindow, &ywindow);
                xMouse = xMouse - xwindow;
                yMouse = yMouse - ywindow;
                std::cout << xMouse << " " << yMouse << std::endl;
                xMouse = xMouse / 32;
                int x = (int)xMouse;
                yMouse = yMouse / 32;
                int y = (int)yMouse;

                

                //tower[x][y]
                if (x >= 21 && y >= 21)
                {
                    x = x - 21;
                    y = y - 21;
                    std::cout << towers[x][y];
                    SDL_SetRenderDrawColor(m_renderer, 205, 179, 139, 255);
                    

                    TTF_Font* Sans = TTF_OpenFont("arial.ttf", 20);
                    SDL_Color Red = { 139, 0, 0 };

                    std::ostringstream oss;
                    oss << "Damage "<<towers[x][y];
                    std::string var = oss.str();



                    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, var.c_str(), Red);
                    SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
                    SDL_Rect Message_rect = { 550,550,surfaceMessage->w,surfaceMessage->h }; //create a rect
                    SDL_RenderFillRect(m_renderer, &Message_rect);
                    SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);

                    SDL_UpdateWindowSurface(m_window);

                    SDL_FreeSurface(surfaceMessage);
                    SDL_DestroyTexture(Message);
                    TTF_CloseFont(Sans);

                    SDL_RenderPresent(m_renderer);
                }
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
                    if (field[x][y] == gras && selected != AffinityType::nothing)
                    {

                        int price = selected * 10;
                        if (gold - price > 0)
                        {
                            int h = setDefense(x, y, selected, price);
                            gold = gold - price;
                            //SDL_RenderClear(m_renderer);
                            //loadLevel();
                            //SDL_RenderPresent(m_renderer);
                        }
                        
                        //render();
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
                selected = AffinityType::nothing;
            }
        }
        if (verloren == false)
        {
            SDL_RenderClear(m_renderer);
            //loadLevel();
            //m_background = loadTexture("Hintergrund.bmp");
            render();
            SDL_RenderPresent(m_renderer);
        }
        else
        {
            TTF_Font* Sans = TTF_OpenFont("arial.ttf", 60);
            SDL_Color Red = { 139, 0, 0 };

            std::ostringstream oss;
            oss << "You Lost " ;
            std::string var = oss.str();



            SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, var.c_str(), Red);
            SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
            SDL_Rect Message_rect = { 250,350,surfaceMessage->w,surfaceMessage->h }; //create a rect
            SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);

            SDL_UpdateWindowSurface(m_window);

            SDL_FreeSurface(surfaceMessage);
            SDL_DestroyTexture(Message);
            TTF_CloseFont(Sans);

            SDL_RenderPresent(m_renderer);
        }
        unsigned int endTime = SDL_GetTicks();
        unsigned int deltaTime = endTime - startTime;
        if (deltaTime < 16)
        {
            SDL_Delay(16 - deltaTime);
        }
    }
    
    cleanup();
    return 0;
}

void Game::cleanup()
{

    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    
    // finish
    SDL_Quit();
    TTF_Quit();
    IMG_Quit();


}

void Game::loadField()
{
    startWeg1.x = 0;
    startWeg1.y = 96;

    startWeg2.x = 0;
    startWeg2.y = 320;

    startWeg3.x = 0;
    startWeg3.y = 448 ; 

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
}


void Game::loadLevel()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
    SDL_RenderClear(m_renderer);
    
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

    for (int i = 0; i < xField; i++)
    {
        for (int j = 0; j < yField; j++)
        {
            Terrain hilf = field[i][j];
            switch (hilf)
            {
            default:
            case weg: SDL_SetRenderDrawColor(m_renderer, 205, 179, 139, 255);  break;
            case gras: SDL_SetRenderDrawColor(m_renderer, 0, 153, 0, 255); break;
            case burg: SDL_SetRenderDrawColor(m_renderer, 131, 139, 139, 255);  break;
            }
            SDL_Rect sdlRect = { (i * 32), (j * 32), 32, 32 };
            SDL_RenderFillRect(m_renderer, &sdlRect);
            SDL_SetRenderDrawColor(m_renderer, 205, 179, 139, 255);
        }
    }

    SDL_SetRenderDrawColor(m_renderer, 205, 179, 139, 255);

    // Türme zum Auswählen

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
            SDL_Rect sdlRect = { ((hX + j) * 32), ((hY + i) * 32), 32, 32 };
            SDL_RenderDrawRect(m_renderer, &sdlRect);
            SDL_Surface* image = NULL; // SDL_LoadBMP("small.bmp");
            switch (indexBild)
            {
            default:
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
            SDL_FreeSurface(image);
            SDL_DestroyTexture(texture);
            indexBild += 1;
        }
    }

    SDL_RenderPresent(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 0xff, 0xff, 0xff, 0xff);

}



void Game::renderGoblin(int index)
{
    Enemy akt = enemyArray[index];
    SDL_Texture* goblin_texture = nullptr;
    auto surface = IMG_Load("goblinOhneHintergrund.png");
    if (!surface)
    {
        std::cerr << "Failed to create surface.\n";
    }
    goblin_texture = SDL_CreateTextureFromSurface(m_renderer,surface);
    if (!goblin_texture)
    {
        std::cerr << "failed to create texture.\n";
        }
    // Das hier drüber muss später in eine eigene Methode und goblin:texture muss ein Datenfeld sein.        
    
    
    SDL_Rect rect = { akt.getXPosi(), akt.getYPosi(), 32, 32 }; //posi {X, Y, breite, höhe}
    if (goblin_texture)
    {
        SDL_RenderCopy(m_renderer, goblin_texture, nullptr, &rect);
    }
    else {
        //SDL_SetRenderDrawColor(m_renderer, 0, 0xff, 0xff, 0xff);
        SDL_RenderFillRect(m_renderer, &rect);
    }
    SDL_DestroyTexture(goblin_texture);
    SDL_FreeSurface(surface);
}

void Game::renderAttack(int index)
{
    Attack akt = attackArray[index];
    SDL_Texture* texture = nullptr;
    auto surface = IMG_Load("Ball.png");
    if (!surface)
    {
        std::cerr << "Failed to create surface.\n";
    }
    texture = SDL_CreateTextureFromSurface(m_renderer, surface);
    if (!texture)
    {
        std::cerr << "failed to create texture.\n";
    }
    // Das hier drüber muss später in eine eigene Methode und goblin:texture muss ein Datenfeld sein.        


    SDL_Rect rect = { akt.getPosi().x, akt.getPosi().y, 10, 10 }; //posi {X, Y, breite, höhe}
    if (texture)
    {
        SDL_RenderCopy(m_renderer, texture, nullptr, &rect);
    }
    else {
        //SDL_SetRenderDrawColor(m_renderer, 0, 0xff, 0xff, 0xff);
        SDL_RenderFillRect(m_renderer, &rect);
    }
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}



void Game::render()
{
    SDL_RenderCopy(m_renderer, m_background, NULL, NULL);
    //SDL_RenderClear(m_renderer);
    // Türme zum Auswählen

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
            SDL_Rect sdlRect = { ((hX + j) * 32), ((hY + i) * 32), 32, 32 };
            SDL_RenderDrawRect(m_renderer, &sdlRect);
            SDL_Surface* image = NULL; // SDL_LoadBMP("small.bmp");
            switch (indexBild)
            {
            default:
            case 1: image = IMG_Load("small.png"); break;
            case 2: image = IMG_Load("medium.png"); break;
            case 3: image = IMG_Load("large.png"); break;
            case 4: image = IMG_Load("fire.png"); break;
            case 5: image = IMG_Load("water.png"); break;
            case 6: image = IMG_Load("wind.png"); break;
            case 7: image = IMG_Load("lightning.png"); break;
            case 8: image = IMG_Load("plant.png"); break;
            case 9: image = IMG_Load("toxic.png"); break;
            }

            SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, image);
            SDL_RenderCopy(m_renderer, texture, NULL, &sdlRect);
            //SDL_RenderPresent(m_renderer);
            SDL_FreeSurface(image);
            SDL_DestroyTexture(texture);

            indexBild += 1;
        }
    }

    //SDL_RenderPresent(m_renderer);
    //SDL_SetRenderDrawColor(m_renderer, 0xff, 0xff, 0xff, 0xff);

    // Türme auf dem Spielfeld laden
   
    int n = size(towerArray);

    for (int i = 0; i < n; i++)
    {
        if (towerArray[i].getAffinity()!= nothing)
        {
            //SDL_SetRenderDrawColor(m_renderer, 100, 100, 100, 0xff);

            SDL_Rect sdlRect = { (towerArray[i].getXPosi() * 32), (towerArray[i].getYPosi() * 32), 32, 32 };
            //SDL_RenderFillRect(m_renderer, &sdlRect);

            SDL_Surface* image = NULL; // SDL_LoadBMP("small.bmp");
            switch (towerArray[i].getAffinity())
            {
            default:
            case 1: image = IMG_Load("small.png"); break;
            case 2: image = IMG_Load("medium.png"); break;
            case 3: image = IMG_Load("large.png"); break;
            case 4: image = IMG_Load("fire.png"); break;
            case 5: image = IMG_Load("water.png"); break;
            case 6: image = IMG_Load("wind.png"); break;
            case 7: image = IMG_Load("lightning.png"); break;
            case 8: image = IMG_Load("plant.png"); break;
            case 9: image = IMG_Load("toxic.png"); break;
            }
            
            DrawCircle(m_renderer,towerArray[i].getXPosi()*32+16, towerArray[i].getYPosi()*32+16, towerArray[i].getRange());
            SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, image);
            SDL_RenderCopy(m_renderer, texture, NULL, &sdlRect);

            SDL_FreeSurface(image);
            SDL_DestroyTexture(texture);

            isInside2(i, towerArray[i].getIndexAttackOfEnemy());
        }
    }
    //SDL_RenderPresent(m_renderer);
    // Gegner auf dem Spielfeld laden
    n = size(enemyArray);
    if (hilfe > 0)
    {
        hilfe = hilfe-1;
    }
    else
    {
        setNewRandomEnemy();
        hilfe = 30;
    }

    SDL_SetRenderDrawColor(m_renderer, 205, 179, 139, 255);
    //std::cout << "Wir sind hier" << std::endl;
    for (int i = 0; i < n; i++)
    {
        if (enemyArray[i].getType() != notEnemy && enemyArray[i].getHealthPoints() >0)
        {
            renderGoblin(i);
            goEnemy(i);
        }
    }



    //Attacken auf dem Spielfeld laden

   

    for (int i = 0; i < MaxAttack ; i++)
    {
        if (attackArray[i].isInitialized == true)
        {
            renderAttack(i);
            attackArray[i].fly();
        }
    }
    

    // Gold anzeigen

    TTF_Font* Sans = TTF_OpenFont("arial.ttf", 20);
    SDL_Color White = { 0xff, 0xff, 0xff };

    std::ostringstream oss;
    oss << "Gold: " << gold;
    std::string var = oss.str();



    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, var.c_str(), White);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect = { 350,700,surfaceMessage->w,surfaceMessage->h }; //create a rect
    SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);

    SDL_UpdateWindowSurface(m_window);
    
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(Sans);
}



int Game::setAttack(int indexTower, int indexEnemy)
{
    Point pDest;
    pDest.x = enemyArray[indexEnemy].getXPosi()+16;
    pDest.y = enemyArray[indexEnemy].getYPosi()+16;

    Point pPosi;
    pPosi.x = (towerArray[indexTower].getXPosi() *32) +16;
    pPosi.y = (towerArray[indexTower].getYPosi() *32) +16;
    
    Attack attack(pDest,pPosi);
    bool weiter = true;
    for (int i = 0; weiter == true  and i < MaxAttack; i++)
    {
        if (attackArray[i].isInitialized == false)
        {
            attackArray[i] = attack;
            weiter = false;
        }
    }


    return 0;
}


int Game::setDefense(int xC, int yC, AffinityType type,int price) {
    Point p; 
    p.x = xC;
    p.y = yC;
    Defense defense(type,p,price);

    towerArray[indexTowerArray] = defense;
    indexTowerArray += 1;


    return 0;
}

int Game::setEnemy(int xC, int yC, EnemyType type)
{   
    Point p;
    p.x = xC;
    p.y = yC;

    Enemy enemy(type, p);
    


    bool weiter = true;
    for (int i = 0; weiter == true and i < MaxEnemy; i++)
    {
        if (enemyArray[i].getType() == notEnemy)
        {
            enemyArray[i] = enemy;
            weiter = false;
        }
    }


    return 0;
}

void Game::setNewRandomEnemy()
{
    int randomEnemy = getRandom(10);
    int randomWeg = getRandom(3);

    EnemyType type = notEnemy;

    switch(randomEnemy)
    {
        case 0: type = notEnemy ; break;
        case 1: type = goblin; break;
        case 2: type = goblin_knite; break;
        case 3: type = slim_goblin; break;
        default: type = notEnemy; break;
    }

    if (type != notEnemy)
    {
        switch (randomWeg)
        {
            default:
            case 0: setEnemy(startWeg1.x, startWeg1.y, type); break;
            case 1: setEnemy(startWeg2.x, startWeg2.y, type); break;
            case 2: setEnemy(startWeg3.x, startWeg3.y, type); break;
        }
    }
}





void Game::goEnemy(int index)
{
    Enemy gegner = enemyArray[index];

    int xC = gegner.getXPosi();
    int yC = gegner.getYPosi();


    float hilfe1 = xC / 32;
    xC = int(hilfe1);

    float hilfe2 = yC / 32;
    yC = int(hilfe2);


     if(gegner.getDestination() == nowhere || gegner.getStepsLeft() == 0 && gegner.getDestination() != nowhere)
    {

        if (field[xC + 1][yC] == weg && gegner.getDestination() != Destination::left) // nach rechts
        {
            enemyArray[index].setDestination(Destination::right);
            enemyArray[index].setSteps((int) (32 / gegner.getHaste()));

            Point p;
            p.x = gegner.getXPosi() + gegner.getHaste();
            p.y = gegner.getYPosi();
            enemyArray[index].setPosi(p);


            enemyArray[index].setSteps(enemyArray[index].getStepsLeft() - 1);
        }
        else if (field[xC][yC + 1] == weg && gegner.getDestination() != Destination::top) // nach unten
        {
            enemyArray[index].setDestination(Destination::bottom);
            enemyArray[index].setSteps((int)(32 / gegner.getHaste()));

            Point p;
            p.x = gegner.getXPosi();
            p.y = gegner.getYPosi() + gegner.getHaste();
            enemyArray[index].setPosi(p);


            enemyArray[index].setSteps(enemyArray[index].getStepsLeft() - 1);
        }
        else if (field[xC][yC - 1] == weg && gegner.getDestination() != Destination::bottom) // nach oben
        {
            enemyArray[index].setDestination(Destination::top);
            enemyArray[index].setSteps((int)(32 / gegner.getHaste()));

            Point p;
            p.x = gegner.getXPosi();
            p.y = gegner.getYPosi() - gegner.getHaste();
            enemyArray[index].setPosi(p);


            enemyArray[index].setSteps(enemyArray[index].getStepsLeft() - 1);
        }
        else if (field[xC + 1][yC] == burg || field[xC][yC + 1] == burg || field[xC][yC - 1] == burg)
        {
            //Spiel Beenden
            verloren = true;
        }
    }
    else
    {
        Destination akt_destgegner = gegner.getDestination();

        if (akt_destgegner == Destination::right) // nach rechts
        {
            Point p;
            p.x = gegner.getXPosi() + gegner.getHaste();
            p.y = gegner.getYPosi();
            enemyArray[index].setPosi(p);
        }
        else if (akt_destgegner == Destination::bottom) // nach unten
        {
            Point p;
            p.x = gegner.getXPosi();
            p.y = gegner.getYPosi() + gegner.getHaste();
            enemyArray[index].setPosi(p);
        }
        else if (akt_destgegner == Destination::top) // nach oben
        {
            Point p;
            p.x = gegner.getXPosi();
            p.y = gegner.getYPosi() - gegner.getHaste();
            enemyArray[index].setPosi(p);
        }
        else
        {

        }

        enemyArray[index].setSteps(enemyArray[index].getStepsLeft() - 1);
        if (enemyArray[index].getStepsLeft() < 1)
        {
            enemyArray[index].setSteps(0);
        }
    }

   
    

}

void Game::loop() {

}

void Game::isInside(int indexDefense)
{
    // Compare radius of circle with distance
    // of its center from given point
    int xTower = (towerArray[indexDefense].getXPosi() *32) + 16;
    int yTower = (towerArray[indexDefense].getYPosi() *32) + 16;
    int rad = towerArray[indexDefense].getRange();

    int n = size(enemyArray);
    for (int i = 0;  i < n; i++)
    {
        if (enemyArray[i].getType() != notEnemy && enemyArray[i].getHealthPoints() >0)
        {
            int x = enemyArray[i].getXPosi();
            int y = enemyArray[i].getYPosi();
            if ((x - xTower) * (x - xTower) + (y - yTower) * (y - yTower) <= rad * rad)
            {//Im radius == schießen
                setAttack(indexDefense,i);
                enemyArray[i].damage(towerArray[indexDefense].getDamage());
                if (enemyArray[i].getHealthPoints() <= 0)
                {
                    gold = gold + (enemyArray[i].getReward() * 5);
                }
            }
            
        }
    }

    
}

void Game::isInside2(int indexDefense, int indexEnemy)
{
    int xTower = (towerArray[indexDefense].getXPosi() * 32) + 16;
    int yTower = (towerArray[indexDefense].getYPosi() * 32) + 16;
    int rad = towerArray[indexDefense].getRange();
    if (indexEnemy < size(enemyArray))
    {
        if (enemyArray[indexEnemy].getType() != notEnemy && enemyArray[indexEnemy].getHealthPoints() > 0)
        {
            int x = enemyArray[indexEnemy].getXPosi();
            int y = enemyArray[indexEnemy].getYPosi();
            if ((x - xTower) * (x - xTower) + (y - yTower) * (y - yTower) <= rad * rad)
            {
                //Im radius == schießen
                setAttack(indexDefense, indexEnemy);
                enemyArray[indexEnemy].damage(towerArray[indexDefense].getDamage());
                if (enemyArray[indexEnemy].getHealthPoints() <= 0)
                {
                    gold = gold + (enemyArray[indexEnemy].getReward() * 5);
                }
            }
            else
            { // Außerhalb des Radius = > neuen Gegner suchen
                int n = size(enemyArray);
                bool weiter = true;
                for (int i = 0; weiter == true && i < n; i++)
                {
                    if (enemyArray[i].getType() != notEnemy && enemyArray[i].getHealthPoints() > 0)
                    {
                        int x = enemyArray[i].getXPosi();
                        int y = enemyArray[i].getYPosi();
                        if ((x - xTower) * (x - xTower) + (y - yTower) * (y - yTower) <= rad * rad)
                        {//Im radius == schießen
                            towerArray[indexDefense].setIndexAttackOfEnemy(i);
                            setAttack(indexDefense, i);
                            enemyArray[i].damage(towerArray[indexDefense].getDamage());
                            if (enemyArray[i].getHealthPoints() <= 0)
                            {
                                gold = gold + (enemyArray[i].getReward() * 5);
                            }
                            weiter = false;
                        }
                    }
                }
            }

        }
    }
        else
        {
            // Turm hatte keinen Gegner 
            int n = size(enemyArray);
            bool weiter = true;
            for (int i = 0; weiter == true && i < n; i++)
            {
                if (enemyArray[i].getType() != notEnemy && enemyArray[i].getHealthPoints() > 0)
                {
                    int x = enemyArray[i].getXPosi();
                    int y = enemyArray[i].getYPosi();
                    if ((x - xTower) * (x - xTower) + (y - yTower) * (y - yTower) <= rad * rad)
                    {//Im radius == schießen
                        towerArray[indexDefense].setIndexAttackOfEnemy (i);
                        setAttack(indexDefense, i);
                        enemyArray[i].damage(towerArray[indexDefense].getDamage());
                        if (enemyArray[i].getHealthPoints() <= 0)
                        {
                            gold = gold + (enemyArray[i].getReward() * 5);
                        }
                        weiter = false;
                    }
                }
            }

        }
    
}


int Game::getRandom(int grenze)
{

    unsigned long j;
    srand(time(NULL));


    int n;
    n = rand() % grenze;
    /*for (j = 0; j < 30; ++j)
    {
        
        while ((n = rand()) > RAND_MAX - (RAND_MAX - 50) % grenze)
        { }

        //printf("%d,\t%d\n", n, n % 6 + 1);
        }
        */

    return n;//(n % grenze);
}



SDL_Texture* Game::loadTexture(std::string path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

void Game::DrawCircle(SDL_Renderer* renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);
    SDL_SetRenderDrawColor(m_renderer, 139, 0, 0, 255);
    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}