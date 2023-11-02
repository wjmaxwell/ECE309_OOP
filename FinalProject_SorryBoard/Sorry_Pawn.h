//
// Created by Nick Urch on 11/28/2022.
//
// Declarations for the Sorry! Pawns.
//
//============================================
#pragma once

#define RED     "Red"
#define BLUE    "Blue"
#define GREEN   "Green"
#define YELLOW  "Yellow"

#include <string>
//#include "Sorry_Board.h"
//Created by Nick Urch, finished by Joseph Homenick
class Sorry_Pawn {
    const std::string color;
    int xPos;
    int yPos;
    bool isHome;
    bool isSafe;
    bool atStart;
    int pieceNum;
public:
    Sorry_Pawn(std::string c, int n);
    int getXPos();
    int getYPos();
    bool getHome();
    bool getSafe();
    bool getStart();
    std::string getColor();
    int getPieceNum();
    void setXPos(int x);
    void setYPos(int y);
    void setHome();
    void setSafe();
    void setStart();
    void Update_Pawn_Status();
    bool onBoard();

};

