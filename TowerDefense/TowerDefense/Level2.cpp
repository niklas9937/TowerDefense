#include "Level2.h"
Level2::Level2()
{
    levelAnzahl = 2;
    bild = "Hintergrundlevel2.bmp";

    //Welle 1
    Enemy enemy1(goblin, Point{ weg1.x,weg1.y });
    welle1.push(enemy1);

    Enemy enemy2(goblin_knite, Point{ weg2.x,weg2.y });
    welle1.push(enemy2);

    Enemy enemy3(slim_goblin, Point{ weg2.x,weg2.y });
    welle1.push(enemy3);


    //Welle 2
    Enemy enemy4(goblin, Point{ weg2.x,weg2.y });
    welle2.push(enemy4);

    //Welle3
    Enemy enemy5(goblin, Point{ weg2.x,weg2.y });
    welle3.push(enemy5);

    field[0][6] = weg;
    field[1][6] = weg;
    field[2][6] = weg;
    field[3][6] = weg;
    field[4][6] = weg;
    field[5][6] = weg;
    field[6][6] = weg;
    field[6][7] = weg;
    field[7][7] = weg;
    field[8][7] = weg;
    field[8][8] = weg;
    field[9][8] = weg;
    field[10][8] = weg;
    field[11][8] = weg;
    field[12][8] = weg;
    field[13][8] = weg;
    field[14][8] = weg;
    field[14][9] = weg;
    field[14][10] = weg;
    field[15][10] = weg;
    field[16][10] = weg;
    field[17][10] = weg;
    field[18][10] = weg;
    field[19][10] = weg;
    field[20][10] = weg;

    field[0][13] = weg;
    field[1][13] = weg;
    field[2][13] = weg;
    field[3][13] = weg;
    field[4][13] = weg;
    field[5][13] = weg;
    field[6][13] = weg;
    field[7][13] = weg;
    field[7][14] = weg;
    field[8][14] = weg;
    field[9][14] = weg;
    field[10][14] = weg;
    field[11][14] = weg;
    field[12][14] = weg;
    field[12][13] = weg;
    field[13][13] = weg;
    field[14][13] = weg;
    field[15][13] = weg;
    field[16][13] = weg;
    field[17][13] = weg;
    field[18][13] = weg;
    field[19][13] = weg;
    field[19][12] = weg;
    field[20][12] = weg;
    field[21][12] = weg;
    field[21][11] = weg;


    


    field[21][10] = burg;


}
