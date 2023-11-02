//
// Created by Joseph on 11/28/2022.
//


#include "Sorry_Board.h"
#include "Sorry_Pawn.h"
#include <iostream>
#include <string>

//Constructor
Sorry_Board::Sorry_Board()
{
    /*
    red[0] = new Sorry_Pawn("Red", 0);
    red[1] = new Sorry_Pawn("Red", 1);
    red[2] = new Sorry_Pawn("Red", 2);
    red[3] = new Sorry_Pawn("Red", 3);

    blue[0] = new Sorry_Pawn("Blue", 0);
    blue[1] = new Sorry_Pawn("Blue", 1);
    blue[2] = new Sorry_Pawn("Blue", 2);
    blue[3] = new Sorry_Pawn("Blue", 3);

    yellow[0] = new Sorry_Pawn("Yellow", 0);
    yellow[1] = new Sorry_Pawn("Yellow", 1);
    yellow[2] = new Sorry_Pawn("Yellow", 2);
    yellow[3] = new Sorry_Pawn("Yellow", 3);

    green[0] = new Sorry_Pawn("Green", 0);
    green[1] = new Sorry_Pawn("Green", 1);
    green[2] = new Sorry_Pawn("Green", 2);
    green[3] = new Sorry_Pawn("Green", 3);
    */

    //Simplified with start positions
    for (int i = 0; i < 4; i++) {
        red[i] = new Sorry_Pawn("Red", i);
        Board[12][i + 1] = red[i];
        blue[i] = new Sorry_Pawn("Blue", i);
        Board[i + 1][3] = blue[i];
        yellow[i] = new Sorry_Pawn("Yellow", i);
        Board[3][14 - i] = yellow[i];
        green[i] = new Sorry_Pawn("Green", i);
        Board[14 - i][12] = green[i];
    }

}

//Destructor
Sorry_Board::~Sorry_Board()
{
    for (int i = 0; i < 4; i++)
    {
        delete [] red[i];
        delete [] blue[i];
        delete [] green[i];
        delete [] yellow[i];
    }
}

//Copy Constructor
Sorry_Board::Sorry_Board(const Sorry_Board &other) {

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            Board[i][j] = other.Board[i][j];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        red[i] = other.red[i];
        blue[i] = other.blue[i];
        green[i] = other.green[i];
        yellow[i] = other.yellow[i];
    }
}

//Assignment Operator
Sorry_Board& Sorry_Board::operator=(const Sorry_Board &other)
{
    if (this == &other) return * this;

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            Board[i][j] = other.Board[i][j];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        red[i] = other.red[i];
        blue[i] = other.blue[i];
        green[i] = other.green[i];
        yellow[i] = other.yellow[i];
    }

    return *this;
}

void Sorry_Board::Show_Board() {
    std::string boardRow[33], tmpRow;
    boardRow[0] =    "+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+";
    boardRow[1] =    "| -  | >  | -  | -  | O  | -  | -  | -  | -  | >  | -  | -  | -  | O  | -  | -  |";
    boardRow[2] =    "+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+";
    boardRow[3] =    "| -  | S  |    |    |    |    | H  | O  | M  | E  |    | S  | A  | F  | E  | v  |";
    boardRow[4] =    "+----+----+----+----+----+    +----+----+----+----+----+----+----+----+----+----+";
    boardRow[5] =    "| O  | A  |    |    | B  |    |    |    |    |    |    |    |    |    |    | -  |";
    boardRow[6] =    "+----+----+----+----+----+    +----+----+----+----+----+----+----+----+----+----+";
    boardRow[7] =    "| -  | F  |    |    | L  |                             |    |    |    |    | -  |";
    boardRow[8] =    "+----+----+----+----+----+              +----+----+----+----+----+----+----+----+";
    boardRow[9] =    "| -  | E  |    |    | U  |              | Y  | E  | L  | L  | O  | W  |    | O  |";
    boardRow[10] =   "+----+----+----+----+----+              +----+----+----+----+----+----+----+----+";
    boardRow[11] =   "| -  |    |    |    | E  |                                                 | -  |";
    boardRow[12] =   "+----+----+----+    +----+       S  O  R  R  Y  !                +----+----+----+";
    boardRow[13] =   "| ^  | H  |    |                                                 |    | H  | -  |";
    boardRow[14] =   "+----+----+----+         <,^,>,v - Start of Slide                +----+----+----+";
    boardRow[15] =   "| -  | O  |    |         O - End of Slide                        |    | O  | -  |";
    boardRow[16] =   "+----+----+----+                                                 +----+----+----+";
    boardRow[17] =   "| -  | M  |    |         R# - Red Pawn                           |    | M  | -  |";
    boardRow[18] =   "+----+----+----+         B# - Blue Pawn                +----+    +----+----+----+";
    boardRow[19] =   "| -  | E  |    |         Y# - Yellow Pawn              | G  |    |    | E  | v  |";
    boardRow[20] =   "+----+----+----+         G# - Green Pawn               +----+    +----+----+----+";
    boardRow[21] =   "| -  |                                                 | R  |    |    |    | -  |";
    boardRow[22] =   "+----+----+----+----+----+                             +----+----+----+----+----+";
    boardRow[23] =   "| O  |    | R  | E  | D  |                             | E  |    |    | S  | -  |";
    boardRow[24] =   "+----+----+----+----+----+                             +----+----+----+----+----+";
    boardRow[25] =   "| -  |    |    |    |    |                             | E  |    |    | A  | -  |";
    boardRow[26] =   "+----+----+----+----+----+----+----+----+----+----+    +----+----+----+----+----+";
    boardRow[27] =   "| -  |    |    |    |    |    |    |    |    |    |    | N  |    |    | F  | O  |";
    boardRow[28] =   "+----+----+----+----+----+----+----+----+----+----+    +----+----+----+----+----+";
    boardRow[29] =   "| ^  | S  | A  | F  | E  |    | H  | O  | M  | E  |    |    |    |    | E  | -  |";
    boardRow[30] =   "+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+";
    boardRow[31] =   "| -  | -  | O  | -  | -  | -  | <  | -  | -  | -  | -  | O  | -  | -  | <  | -  |";
    boardRow[32] =   "+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+";

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (Board[i][j] != nullptr) {
                // If not a nullptr, show which pawn is there.
                if (Board[i][j] == red[0]) {
                    boardRow[i * 2 + 1][j * 5 + 2] = 'R';
                    boardRow[i * 2 + 1][j * 5 + 3] = '0';
                } else if (Board[i][j] == red[1]) {
                    boardRow[i * 2 + 1][j * 5 + 2] = 'R';
                    boardRow[i * 2 + 1][j * 5 + 3] = '1';
                } else if (Board[i][j] == red[2]) {
                    boardRow[i * 2 + 1][j * 5 + 2] = 'R';
                    boardRow[i * 2 + 1][j * 5 + 3] = '2';
                } else if (Board[i][j] == red[3]) {
                    boardRow[i * 2 + 1][j * 5 + 2] = 'R';
                    boardRow[i * 2 + 1][j * 5 + 3] = '3';
                } else if (Board[i][j] == blue[0]) {
                    boardRow[i * 2 + 1][j * 5 + 2] = 'B';
                    boardRow[i * 2 + 1][j * 5 + 3] = '0';
                } else if (Board[i][j] == blue[1]) {
                    boardRow[i * 2 + 1][j * 5 + 2] = 'B';
                    boardRow[i * 2 + 1][j * 5 + 3] = '1';
                } else if (Board[i][j] == blue[2]) {
                    boardRow[i * 2 + 1][j * 5 + 2] = 'B';
                    boardRow[i * 2 + 1][j * 5 + 3] = '2';
                } else if (Board[i][j] == blue[3]) {
                    boardRow[i * 2 + 1][j * 5 + 2] = 'B';
                    boardRow[i * 2 + 1][j * 5 + 3] = '3';
                } else if (Board[i][j] == green[0]) {
                    boardRow[i * 2 + 1][j * 5 + 2] = 'G';
                    boardRow[i * 2 + 1][j * 5 + 3] = '0';
                } else if (Board[i][j] == green[1]) {
                    boardRow[i * 2 + 1][j * 5 + 2] = 'G';
                    boardRow[i * 2 + 1][j * 5 + 3] = '1';
                } else if (Board[i][j] == green[2]) {
                    boardRow[i * 2 + 1][j * 5 + 2] = 'G';
                    boardRow[i * 2 + 1][j * 5 + 3] = '2';
                } else if (Board[i][j] == green[3]) {
                    boardRow[i * 2 + 1][j * 5 + 2] = 'G';
                    boardRow[i * 2 + 1][j * 5 + 3] = '3';
                } else if (Board[i][j] == yellow[0]) {
                    boardRow[i * 2 + 1][j * 5 + 2] = 'Y';
                    boardRow[i * 2 + 1][j * 5 + 3] = '0';
                } else if (Board[i][j] == yellow[1]) {
                    boardRow[i * 2 + 1][j * 5 + 2] = 'Y';
                    boardRow[i * 2 + 1][j * 5 + 3] = '1';
                } else if (Board[i][j] == yellow[2]) {
                    boardRow[i * 2 + 1][j * 5 + 2] = 'Y';
                    boardRow[i * 2 + 1][j * 5 + 3] = '2';
                } else if (Board[i][j] == yellow[3]) {
                    boardRow[i * 2 + 1][j * 5 + 2] = 'Y';
                    boardRow[i * 2 + 1][j * 5 + 3] = '3';
                }
            }
        }
    }
    for (int i = 0; i < 33; i++) {
        std::cout << boardRow[i] << std::endl;
    }
}

void Sorry_Board::Update_Board() {
    for(int i=0; i<16; i++) {
        for (int j = 0; j < 16; j++) {
            Board[i][j] = nullptr;
        }
    }

    for(int i=0; i<4; i++) {
        int x = red[i]->getXPos();
        int y = red[i]->getYPos();
        Board[y][x] = red[i];

        x = blue[i]->getXPos();
        y = blue[i]->getYPos();
        Board[y][x] = blue[i];

        x = yellow[i]->getXPos();
        y = yellow[i]->getYPos();
        Board[y][x] = yellow[i];

        x = green[i]->getXPos();
        y = green[i]->getYPos();
        Board[y][x] = green[i];
    }
}

void Sorry_Board::Send_Pawn_To_Start(Sorry_Pawn pawn) {
    int x = 0, y = 0;
    if (pawn.getColor() == RED) {
        x = pawn.getPieceNum() + 1;
        y = 12;
    } else if (pawn.getColor() == BLUE) {
        x = 3;
        y = pawn.getPieceNum() + 1;
    } else if (pawn.getColor() == YELLOW) {
        x = 14 - pawn.getPieceNum();
        y = 3;
    } else if (pawn.getColor() == GREEN) {
        x = 12;
        y = 14 - pawn.getPieceNum();
    }
    pawn.setXPos(x);
    pawn.setYPos(y);
    pawn.Update_Pawn_Status();
    Board[y][x] = &pawn;
}

