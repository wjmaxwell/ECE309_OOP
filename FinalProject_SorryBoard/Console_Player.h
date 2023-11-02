//
// Created by Nick Urch on 11/28/2022.
//
// Console Player Declarations
//
//=======================================
#pragma once

#include "Sorry_Player.h"

class Console_Player : public Sorry_Player {
public:
    Console_Player(int i);
    bool getIsHuman();
};

