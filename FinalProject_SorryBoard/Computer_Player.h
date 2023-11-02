// Created by Nick Urch on 11/28/2022.
//
// Computer Player Declarations
//
//=======================================
#pragma once

#include "Sorry_Player.h"

class Computer_Player : public Sorry_Player {
public:
    Computer_Player(int i);
    bool getIsHuman();
};

