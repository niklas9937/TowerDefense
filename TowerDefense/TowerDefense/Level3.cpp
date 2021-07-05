#include "Level3.h"
Level3::Level3()
{
    levelAnzahl = 1;
    bild = "HintergrundLevel3.bmp";

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

    Enemy enemy5(goblin, Point{ weg3.x,weg3.y });
    welle2.push(enemy5);

    Enemy enemy6(goblin_knite, Point{ weg1.x,weg1.y });
    welle2.push(enemy6);

    Enemy enemy7(goblin_knite, Point{ weg1.x,weg1.y });
    welle2.push(enemy7);

    Enemy enemy8(slim_goblin, Point{ weg1.x,weg1.y });
    welle2.push(enemy8);

    //Welle3
    Enemy enemy9(goblin_knite, Point{ weg2.x,weg2.y });
    welle3.push(enemy9);

    Enemy enemy10(goblin_knite, Point{ weg2.x,weg2.y });
    welle3.push(enemy10);

    Enemy enemy11(goblin_knite, Point{ weg2.x,weg2.y });
    welle3.push(enemy11);

    Enemy enemy12(goblin_knite, Point{ weg2.x,weg2.y });
    welle3.push(enemy12);

    field[18][0] = weg;
    field[18][1] = weg;
    field[19][1] = weg;
    field[19][2] = weg;
    field[19][3] = weg;
    field[19][4] = weg;
    field[19][5] = weg;
    field[20][5] = weg;
    field[20][6] = weg;
    field[20][7] = weg;
    field[21][7] = weg;
    field[21][8] = weg;
    field[21][9] = weg;
    

    field[0][8] = weg;
    field[1][8] = weg;
    field[1][7] = weg;
    field[2][7] = weg;
    field[3][7] = weg;
    field[4][7] = weg;
    field[5][7] = weg;
    field[6][7] = weg;
    field[7][7] = weg;
    field[8][7] = weg;
    field[9][7] = weg;
    field[9][8] = weg;
    field[10][8] = weg;
    field[11][8] = weg;
    field[11][9] = weg;
    field[11][10] = weg;
    field[12][10] = weg;
    field[13][10] = weg;
    field[14][10] = weg;
    field[14][9] = weg;
    field[15][9] = weg;
    field[16][9] = weg;
    field[17][9] = weg;
    field[17][10] = weg;
    field[18][10] = weg;
    field[19][10] = weg;
    field[20][10] = weg;

    field[17][19] = weg;
    field[17][18] = weg;
    field[17][17] = weg;
    field[18][17] = weg;
    field[18][16] = weg;
    field[18][15] = weg;
    field[18][14] = weg;
    field[19][14] = weg;
    field[19][13] = weg;
    field[19][12] = weg;
    field[20][12] = weg;
    field[21][12] = weg;
    field[21][11] = weg;

    field[21][10] = burg;


}
