//
// Created by Trey Parker on 12/7/22.
//
// function declerations
// card rule/implementation
// base rules
#pragma once

#include <iostream>
#include "Sorry_Pawn.h"
#include "Sorry_Deck.h"
#include "Sorry_Board.h"
#include "Sorry_Player.h"


class Card_Rules{
private:
    bool check;
    int xVal;
    int yVal;
    int first;
    int second;
public:
    Card_Rules();
    Card_Rules(int card, int getXPos(), int getYpos());
    void baseCards(int card, int getXpos(),int getYpos());
    bool Check_Win(int playerNum, Sorry_Board &b);
    void Ask_Player_For_Move(int playerNum, int card, Sorry_Board &b);
    void Ask_Computer_For_Move(int playerNum, int card, Sorry_Board &b);
    void Move_Pawn(int playerNum, int pieceNum, Sorry_Board &b, int dist);
    void Start_Pawn(int playerNum, Sorry_Board &b);
    void Pawn_To_Start(int x, int y, std::string color, Sorry_Board &b);
    void Swap_Pawn(int playerNum, int swapNum, int pieceNum, int swapPiece, Sorry_Board &b);
    void Sorry_Move(int playerNum, int swapNum, int pieceNum, int swapPiece, Sorry_Board &b);
    bool Check_For_Valid_Start(int playerNum, Sorry_Board &b);
    bool Check_For_Valid_Move(int playerNum, int pieceNum, Sorry_Board &b, int dist);
    bool Check_For_Valid_Swap(int playerNum, int swapNum, int pieceNum, int swapPiece, Sorry_Board &b);
    bool Check_For_Valid_Sorry(int playerNum, int swapNum, int pieceNum, int swapPiece, Sorry_Board &b);
    int decisionCheck(int playerNum,int card,Sorry_Board &b,int getXPos,int getYPos);
    int Closest_To_Home(int playerNum, Sorry_Board &b);
    int Distance_From_Home(Sorry_Pawn *pawn);
    bool All_Pawns_At_Start(int playerNum, Sorry_Board &b);
};

