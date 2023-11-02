//
// Created by Nick Urch on 11/28/2022.
//
// Definitions for the Sorry! Player Base Class.
//      Two derived classes will come out of this. Console_Player and Computer_Player.
//
// Functions:
//      Constructor - Sorry_Player(int n) : Creates Player objects with the Players turn number in the game rotation.
//      Int getTurnNum() : Returns the players turn number in the rotation.
//      String getColor() : Returns color of Pawns that this player is using.
//      Virtual char Ask_Move(int card) : Some Cards require a choice.  This function will do one of two things.
//              (1) Ask a Human Player to decide what choice to make.
//              (2) Decide the best move for a Computer Player.
//              These will be implemented in the derived classes. Does nothing in this class.
//
//====================================================================================================================

#include <string>
#include "Sorry_Player.h"

Sorry_Player::Sorry_Player(int n) : turnNum(n) {
    switch (n) {
        case 0 : color = "Red"; break;
        case 1 : color = "Blue"; break;
        case 2 : color = "Yellow"; break;
        case 3 : color = "Green"; break;
        default: break;
    }
}

int Sorry_Player::getTurnNum() {
    return turnNum;
}

std::string Sorry_Player::getColor() {
    return color;
}

char Sorry_Player::Ask_Move(int card) {
    return 0;
}

bool Sorry_Player::getIsHuman() {
    return false;
}



