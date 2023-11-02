//
// Created by Joseph on 11/28/2022.
//
#pragma once

#include "Sorry_Pawn.h"

#define ROWS 16
#define COLS 16

//Completed by Joseph Homenick
class Sorry_Board {
public:
    //Board is 16 x 16 array of pointers to Sorry! Pawns
    Sorry_Pawn * Board[ROWS][COLS] = {nullptr};
    Sorry_Pawn * red[4] = {nullptr};
    Sorry_Pawn * blue[4] = {nullptr};
    Sorry_Pawn * yellow[4] = {nullptr};
    Sorry_Pawn * green[4] = {nullptr};
    Sorry_Board();
    ~Sorry_Board();
    Sorry_Board(const Sorry_Board &other);
    Sorry_Board& operator=(const Sorry_Board &other);
    void Show_Board();
    void Update_Board();
    void Send_Pawn_To_Start(Sorry_Pawn pawn);

};