//
// Created by Nick Urch on 11/28/2022.
//
// Player Declarations
//
//=======================================
#pragma once

#include <string>

class Sorry_Player {
    const int turnNum;
    std::string color;
public:
    Sorry_Player(int n);
    int getTurnNum();
    std::string getColor();
    char Ask_Move(int card);
    virtual bool getIsHuman();
};

