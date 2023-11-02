//
// Created by Nick Urch on 11/28/2022.
//
// Definitions for the Sorry! Pawns.
//
// Functions:
//      Constructor Sorry_Pawn(std::string c) - Create new object. Color must be passed in.
//      Getters and Setters are pretty self-explanatory
//
//============================================================================================

#include "Sorry_Pawn.h"
#include <iostream>
#include <utility>

Sorry_Pawn::Sorry_Pawn(std::string c, int n) : color(std::move(c)), pieceNum(n) {
    isHome = false;
    isSafe = false;
    atStart = true;

    if (color == RED) {
        switch (pieceNum)
        {
            case 0:
                xPos = 1;
                yPos = 12;
                break;
            case 1:
                xPos = 2;
                yPos = 12;
                break;
            case 2:
                xPos = 3;
                yPos = 12;
                break;
            case 3:
                xPos = 4;
                yPos = 12;
                break;
        }

    } else if (color == BLUE) {
        switch(pieceNum)
        {
            case 0:
                xPos = 3;
                yPos = 1;
                break;
            case 1:
                xPos = 3;
                yPos = 2;
                break;
            case 2:
                xPos = 3;
                yPos = 3;
                break;
            case 3:
                xPos = 3;
                yPos = 4;
                break;
        }
    } else if (color == GREEN) {
        switch (pieceNum)
        {
            case 0:
                xPos = 12;
                yPos = 14;
                break;
            case 1:
                xPos = 12;
                yPos = 13;
                break;
            case 2:
                xPos = 12;
                yPos = 12;
                break;
            case 3:
                xPos = 12;
                yPos = 11;
                break;
        }
    } else if (color == YELLOW) {
        switch(pieceNum)
        {
            case 0:
                xPos = 14;
                yPos = 3;
                break;
            case 1:
                xPos = 13;
                yPos = 3;
                break;
            case 2:
                xPos = 12;
                yPos = 3;
                break;
            case 3:
                xPos = 11;
                yPos = 3;
                break;
        }
    }
}

int Sorry_Pawn::getXPos() {
    return xPos;
}

int Sorry_Pawn::getYPos() {
    return yPos;
}

void Sorry_Pawn::setXPos(int x) {
    xPos = x;
}

void Sorry_Pawn::setYPos(int y) {
    yPos = y;
}

bool Sorry_Pawn::getSafe() {
    return isSafe;
}

bool Sorry_Pawn::getHome() {
    return isHome;
}

bool Sorry_Pawn::getStart() {
    return atStart;
}
void Sorry_Pawn::setHome() {
    if (color == RED)
    {
        if ( (xPos >= 6 && xPos <= 9) && (yPos == 13) ) {
            isHome = true;
        } else {
            isHome = false;
        }
    }
    else if (color == BLUE)
    {
        if ( (xPos == 2) && (yPos >= 6 && yPos <= 9) ) {
            isHome = true;
        } else {
            isHome = false;
        }
    }
    else if (color == GREEN)
    {
        if ( (xPos == 13) && (yPos >= 6 && yPos<= 9) ) {
            isHome = true;
        } else {
            isHome = false;
        }
    }
    else if (color == YELLOW)
    {
        if ( (xPos >= 6 && xPos <= 9) && (yPos == 2) ) {
            isHome = true;
        } else {
            isHome = false;
        }
    }
    else
    {
        std::cout << "Unknown Piece Color!" << std::endl;
    }
}

void Sorry_Pawn::setSafe() {
    if (color == RED)
    {
        if ( (xPos >= 1 && xPos <= 5) && (yPos == 13) ) {
            isSafe = true;
        } else {
            isSafe = false;
        }
    }
    else if (color == BLUE)
    {
        if ( (xPos == 2) && (yPos >= 1 && yPos <= 5) ) {
            isSafe = true;
        } else {
            isSafe = false;
        }
    }
    else if (color == GREEN)
    {
        if ( (xPos == 13) && (yPos >= 10 && yPos<= 14) ) {
            isSafe = true;
        } else {
            isSafe = false;
        }
    }
    else if (color == YELLOW)
    {
        if ( (xPos >= 10 && xPos <= 14) && (yPos == 2) ) {
            isSafe = true;
        } else {
            isSafe = false;
        }
    }
    else
    {
        std::cout << "Unknown Piece Color!" << std::endl;
    }
}

void Sorry_Pawn::setStart() {
    if (color == RED)
    {
        if ( (xPos >= 1 && xPos <= 4) && (yPos == 12) ) {
            atStart = true;
        } else {
            atStart = false;
        }
    }
    else if (color == BLUE)
    {
        if ( (xPos == 3) && (yPos >= 1 && yPos <= 4) ) {
            atStart = true;
        } else {
            atStart = false;
        }
    }
    else if (color == GREEN)
    {
        if ( (xPos == 12) && (yPos >= 11 && yPos<= 14) ) {
            atStart = true;
        } else {
            atStart = false;
        }
    }
    else if (color == YELLOW)
    {
        if ( (xPos >= 11 && xPos <= 14) && (yPos == 3) ) {
            atStart = true;
        } else {
            atStart = false;
        }
    }
    else
    {
        std::cout << "Unknown Piece Color!" << std::endl;
    }
}

void Sorry_Pawn::Update_Pawn_Status() {
    this->setHome();
    this->setSafe();
    this->setStart();
}

bool Sorry_Pawn::onBoard() {
    if(!this->getHome() && !this->getSafe() && !this->getStart()) {
        return true;
    }
    else {
        return false;
    }
}

std::string Sorry_Pawn::getColor() {
    return color;
}

int Sorry_Pawn::getPieceNum() {
    return pieceNum;
}


