//
// Created by Nick Urch on 11/28/2022.
//
// Definitions for the Sorry! Player Derived Computer Player Class.
//
// Functions:
//      Char Ask_Move(int card) : Some Cards require a choice.
//                                This will choose the best move for the computer.
//
//======================================================================================

#include "Computer_Player.h"

Computer_Player::Computer_Player(int i) : Sorry_Player(i) {}

bool Computer_Player::getIsHuman() {
    return false;
}


