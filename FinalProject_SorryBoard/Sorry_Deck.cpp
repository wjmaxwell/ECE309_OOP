//
// Created by Nick Urch on 11/15/2022.
//
// This is the Definitions for the Sorry! Deck of Cards
//
// Functions :
//      Constructor Sorry_Deck() will create a new object.
//      void Shuffle_Deck() randomizes the deck of cards.
//      int Draw_Card() returns the integer value of the top card in the deck.
//                  Automatically Shuffles the deck if the last card was drawn.
//      void Card_Text(int c) displays to the console the text written on the game card.
//
//=================================================================================================

#include <iostream>
#include <random>
#include <time.h>

#include "Sorry_Deck.h"

using namespace std;

Sorry_Deck::Sorry_Deck() {}

void Sorry_Deck::Shuffle_Deck() {
    std::cout << "Shuffling the Deck" << std::endl;
    // Random Seed
    srand(time(0));
    // Generate Random Number and Swap
    for (int i = 0; i < DECK_SIZE; i++) {
        int r = i + rand() % (DECK_SIZE - i);
        //Swap
        std::swap(cards[i], cards[r]);
    }
    curIndex = 0;
}

int Sorry_Deck::Draw_Card() {
    int card = cards[curIndex++];
    // If last card, then shuffle deck
    if (curIndex >= DECK_SIZE) {
        Shuffle_Deck();
    }
    return card;
}

void Sorry_Deck::Card_Text(int c) {
    switch (c) {
        case 1 :
            cout << "One : Choice (A) Move a pawn from your Home one space." << endl;
            cout << "      Choice (B) Move a pawn one space forward." << endl;
            cout << "      Choice (C) Forfeit turn ONLY if unable to move a pawn." << endl;
            break;
        case 2 :
            cout << "Two : Choice (A) Move a pawn from your Home." << endl;
            cout << "      Choice (B) Move a pawn two spaces forward." << endl;
            cout << "      Choice (C) Forfeit turn ONLY if unable to move a pawn." << endl;
            cout << "      Congratulations! You receive another turn!" << endl;
            break;
        case 3 :
            cout << "Three : Choice (A) Move a pawn forward three spaces." << endl;
            cout << "        Choice (B) Forfeit turn ONLY if unable to move a pawn." << endl;
            break;
        case 4 :
            cout << "Four : Choice (A) Move a pawn backwards four spaces." << endl;
            cout << "       Choice (B) Forfeit turn ONLY if unable to move a pawn." << endl;
            break;
        case 5 :
            cout << "Five : Choice (A) Move a pawn forward five spaces." << endl;
            cout << "       Choice (B) Forfeit turn ONLY if unable to move a pawn." << endl;
            break;
        case 7 :
            cout << "Seven : Choice (A) Move a pawn forward seven spaces" << endl;
            cout << "        Choice (B) Forfeit turn ONLY if unable to move a pawn." << endl;
            break;
        case 8 :
            cout << "Eight : Choice (A) Move a pawn forward eight spaces." << endl;
            cout << "        Choice (B) Forfeit turn ONLY if unable to move a pawn." << endl;
            break;
        case 10 :
            cout << "Ten : Choice (A) Move a pawn forward ten spaces." << endl;
            cout << "      Choice (B) Move a pawn backwards one space." << endl;
            cout << "      Choice (C) Forfeit turn ONLY if unable to move a pawn." << endl;
            break;
        case 11 :
            cout << "Eleven : Choice (A) Move a pawn forward eleven spaces." << endl;
            cout << "         Choice (B) Switch one of your pawns in play with that of an opponent." << endl;
            cout << "         Choice (C) Forfeit turn ONLY if unable to move a pawn." << endl;
            cout << "         You may choose to forfeit instead of switching pawns." << endl;
            break;
        case 12 :
            cout << "Twelve : Choice (A) Move a pawn forward twelve spaces." << endl;
            cout << "         Choice (B) Forfeit turn ONLY if unable to move a pawn." << endl;
            break;
        case 13 :
            cout << "Sorry! : Choice (A) Move one of your pawns from your Start and replace it with an opponents." << endl;
            cout << "         The opponents pawn is moved back to their Start. Cannot be used in opponents pawn in a Safe Zone" << endl;
            cout << "         Choice (B) Forfeit turn ONLY if unable to move a pawn." << endl;
            break;
        default : break;
    }
}