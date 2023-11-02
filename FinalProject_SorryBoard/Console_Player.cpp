//
// Created by Nick Urch on 11/28/2022.
//
// Definitions for the Sorry! Player Derived Console Player Class.
//
// Functions:
//      Char Ask_Move(int card) : Some Cards require a choice.
//                                This will ask the player to make a choice.
//
//==============================================================================

#include "Console_Player.h"

Console_Player::Console_Player(int i) : Sorry_Player(i) {}

bool Console_Player::getIsHuman() {
    return true;
}
