//
// Created by Nick Urch on 11/15/2022.
//
// Declarations for the Sorry! Deck of Cards.
//
//============================================

#pragma once

#define DECK_SIZE 44

class Sorry_Deck {
    int curIndex = 0;
    //13 is Sorry! Card
    int cards[DECK_SIZE] = {1 , 1 , 1 , 1,
                            2 , 2 , 2 , 2,
                            3 , 3 , 3 , 3,
                            4 , 4 , 4 , 4,
                            5 , 5 , 5 , 5,
                            7 , 7 , 7 , 7,
                            8 , 8 , 8 , 8,
                            10, 10, 10, 10,
                            11, 11, 11, 11,
                            12, 12, 12, 12,
                            13, 13, 13, 13};
public:
    Sorry_Deck();
    void Shuffle_Deck();
    int Draw_Card();
    void Card_Text(int c);
};