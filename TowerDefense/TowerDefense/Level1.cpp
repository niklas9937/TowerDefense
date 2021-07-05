#include "Level1.h"
Level1::Level1()
{
    levelAnzahl = 1;
    bild = "Hintergrund.bmp";

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

    Enemy enemy27(goblin_knite, Point{ weg1.x,weg1.y });
    welle2.push(enemy27);

    Enemy enemy28(goblin_knite, Point{ weg1.x,weg1.y });
    welle2.push(enemy28);

    Enemy enemy29(goblin, Point{ weg3.x,weg3.y });
    welle2.push(enemy29);

    Enemy enemy30(goblin_knite, Point{ weg1.x,weg1.y });
    welle2.push(enemy30);

    Enemy enemy31(goblin_knite, Point{ weg1.x,weg1.y });
    welle2.push(enemy31);


    //Welle3
    Enemy enemy9(goblin_knite, Point{ weg3.x,weg3.y });
    welle3.push(enemy9);

    Enemy enemy10(goblin_knite, Point{ weg2.x,weg2.y });
    welle3.push(enemy10);

    Enemy enemy11(goblin_knite, Point{ weg2.x,weg2.y });
    welle3.push(enemy11);

    Enemy enemy12(goblin_knite, Point{ weg3.x,weg3.y });
    welle3.push(enemy12);

    Enemy enemy13(goblin_knite, Point{ weg2.x,weg2.y });
    welle3.push(enemy3);

    Enemy enemy14(goblin_knite, Point{ weg1.x,weg1.y });
    welle3.push(enemy14);

    Enemy enemy15(goblin_knite, Point{ weg3.x,weg3.y });
    welle3.push(enemy15);

    Enemy enemy16(goblin_knite, Point{ weg1.x,weg1.y });
    welle3.push(enemy16);

    Enemy enemy17(goblin_knite, Point{ weg1.x,weg1.y });
    welle3.push(enemy17);

    Enemy enemy18(slim_goblin, Point{ weg1.x,weg1.y });
    welle3.push(enemy18);

    Enemy enemy19(goblin, Point{ weg2.x,weg2.y });
    welle3.push(enemy4);

    Enemy enemy20(goblin, Point{ weg3.x,weg3.y });
    welle3.push(enemy20);

    Enemy enemy21(goblin_knite, Point{ weg1.x,weg1.y });
    welle3.push(enemy21);

    Enemy enemy22(goblin_knite, Point{ weg1.x,weg1.y });
    welle3.push(enemy22);


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
