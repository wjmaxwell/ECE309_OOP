//======================================================================================================================
//
// Created by Trey Parker on 12/7/22
// Finished by Jack Maxwell & Nick Urch on 12/14/22
// Card_Rules.cpp contains all the functions related to pawn movement and player/computer decision making
//
//======================================================================================================================

#include <iostream>

#include "Card_Rules.h"
#include "Sorry_Board.h"

Card_Rules::Card_Rules() {}

bool Card_Rules::Check_Win(int playerNum, Sorry_Board &b) {
    // CHECKS FOR WINNER AFTER EACH TURN

    switch (playerNum) {
        case 0 :
            if (b.red[0]->getHome() && b.red[1]->getHome() && b.red[2]->getHome() && b.red[3]->getHome())
                return true;
            break;
        case 1 :
            if (b.blue[0]->getHome() && b.blue[1]->getHome() && b.blue[2]->getHome() && b.blue[3]->getHome())
                return true;
            break;
        case 2 :
            if (b.yellow[0]->getHome() && b.yellow[1]->getHome() && b.yellow[2]->getHome() && b.yellow[3]->getHome())
                return true;
            break;
        case 3 :
            if (b.green[0]->getHome() && b.green[1]->getHome() && b.green[2]->getHome() && b.green[3]->getHome())
                return true;
            break;
        default : break;

    }
    return false;
}

void Card_Rules::Ask_Player_For_Move(int playerNum, int card, Sorry_Board &b) {
    // ASKS PLAYER FOR ACTION DECISION BASED ON DRAWN CARD

    char choice;
    int valid_choice = 0;
    int action_completed = 0;

    switch (card) {
        case 1: // start a pawn or move +1 space
            while (action_completed == 0) {
                valid_choice = 0;
                while (!valid_choice) {  // checks for a valid card choice entry
                    std::cin >> choice;
                    if (choice == 'A' || choice == 'B' || choice == 'C') {
                        valid_choice = 1;
                    } else {
                        std::cout << "Invalid choice! Pick either A, B, or C" << std::endl;
                    }
                }

                if (choice == 'A') {
                    if (Check_For_Valid_Start(playerNum, b)) {
                        Start_Pawn(playerNum, b);
                        action_completed = 1;
                    }
                } else if (choice == 'B') {
                    int pieceNum;
                    std::cout << "Choose a pawn to move (0-3)" << std::endl;
                    std::cin >> pieceNum;
                    if (Check_For_Valid_Move(playerNum, pieceNum, b, 1)) {
                        Move_Pawn(playerNum, pieceNum, b, 1);
                        action_completed = 1;
                    } else {
                        std::cout << "Invalid move attempt. Try again." << std::endl;
                    }
                }
                else {
                    std::cout << "Forfeited Turn" << std::endl;
                    action_completed = 1;
                }
            }
            break;

        case 2: // start a pawn or move +2 spaces
            while (action_completed == 0) {
                valid_choice = 0;
                while (!valid_choice) {  // checks for a valid card choice entry
                    std::cin >> choice;
                    if (choice == 'A' || choice == 'B' || choice == 'C') {
                        valid_choice = 1;
                    } else {
                        std::cout << "Invalid choice! Pick either A, B, or C" << std::endl;
                    }
                }

                if (choice == 'A') {
                    if (Check_For_Valid_Start(playerNum, b)) {
                        Start_Pawn(playerNum, b);
                        action_completed = 1;
                    }
                } else if (choice == 'B') {
                    int pieceNum;
                    std::cout << "Choose a pawn to move (0-3)" << std::endl;
                    std::cin >> pieceNum;
                    if (Check_For_Valid_Move(playerNum, pieceNum, b, 2)) {
                        Move_Pawn(playerNum, pieceNum, b, 2);
                        action_completed = 1;
                    } else {
                        std::cout << "Invalid move attempt. Try again." << std::endl;
                    }
                }
                else {
                    std::cout << "Forfeited Turn" << std::endl;
                    action_completed = 1;
                }
            }
            break;

        case 3: // move a pawn +3 spaces
            while (action_completed == 0) {
                valid_choice = 0;
                while (!valid_choice) {  // checks for a valid card choice entry
                    std::cin >> choice;
                    if (choice == 'A' || choice == 'B') {
                        valid_choice = 1;
                    } else {
                        std::cout << "Invalid choice! Pick either A or B" << std::endl;
                    }
                }

                if (choice == 'A') {
                    int pieceNum;
                    std::cout << "Choose a pawn to move (0-3)" << std::endl;
                    std::cin >> pieceNum;
                    if (Check_For_Valid_Move(playerNum, pieceNum, b, 3)) {
                        Move_Pawn(playerNum, pieceNum, b, 3);
                        action_completed = 1;
                    } else {
                        std::cout << "Invalid move attempt. Try again." << std::endl;
                    }
                } else if (choice == 'B') {
                    std::cout << "Forfeited Turn" << std::endl;
                    action_completed = 1;
                }
            }
            break;

        case 4: // move a pawn -4 spaces
            while (action_completed == 0) {
                valid_choice = 0;
                while (!valid_choice) {  // checks for a valid card choice entry
                    std::cin >> choice;
                    if (choice == 'A' || choice == 'B') {
                        valid_choice = 1;
                    } else {
                        std::cout << "Invalid choice! Pick either A or B" << std::endl;
                    }
                }

                if (choice == 'A') {
                    int pieceNum;
                    std::cout << "Choose a pawn to move (0-3)" << std::endl;
                    std::cin >> pieceNum;
                    if (Check_For_Valid_Move(playerNum, pieceNum, b, -4)) {
                        Move_Pawn(playerNum, pieceNum, b, -4);
                        action_completed = 1;
                    } else {
                        std::cout << "Invalid move attempt. Try again." << std::endl;
                    }
                } else if (choice == 'B') {
                    std::cout << "Forfeited Turn" << std::endl;
                    action_completed = 1;
                }
            }
            break;

        case 5: // move pawn +5 spaces
            while (action_completed == 0) {
                valid_choice = 0;
                while (!valid_choice) {  // checks for a valid card choice entry
                    std::cin >> choice;
                    if (choice == 'A' || choice == 'B') {
                        valid_choice = 1;
                    } else {
                        std::cout << "Invalid choice! Pick either A or B" << std::endl;
                    }
                }

                if (choice == 'A') {
                    int pieceNum;
                    std::cout << "Choose a pawn to move (0-3)" << std::endl;
                    std::cin >> pieceNum;
                    if (Check_For_Valid_Move(playerNum, pieceNum, b, 5)) {
                        Move_Pawn(playerNum, pieceNum, b, 5);
                        action_completed = 1;
                    } else {
                        std::cout << "Invalid move attempt. Try again." << std::endl;
                    }
                } else if (choice == 'B') {
                    std::cout << "Forfeited Turn" << std::endl;
                    action_completed = 1;
                }
            }
            break;

        case 7: // move a pawn +7 spaces
            while (action_completed == 0) {
                valid_choice = 0;
                while (!valid_choice) {  // checks for a valid card choice entry
                    std::cin >> choice;
                    if (choice == 'A' || choice == 'B') {
                        valid_choice = 1;
                    } else {
                        std::cout << "Invalid choice! Pick either A or B" << std::endl;
                    }
                }

                if (choice == 'A') {
                    int pieceNum;
                    std::cout << "Choose a pawn to move (0-3)" << std::endl;
                    std::cin >> pieceNum;
                    if (Check_For_Valid_Move(playerNum, pieceNum, b, 7)) {
                        Move_Pawn(playerNum, pieceNum, b, 7);
                        action_completed = 1;
                    } else {
                        std::cout << "Invalid move attempt. Try again." << std::endl;
                    }
                } else if (choice == 'B') {
                    std::cout << "Forfeited Turn" << std::endl;
                    action_completed = 1;
                }
            }
            break;

        case 8: // move a pawn +8 spaces
            while (action_completed == 0) {
                valid_choice = 0;
                while (!valid_choice) {  // checks for a valid card choice entry
                    std::cin >> choice;
                    if (choice == 'A' || choice == 'B') {
                        valid_choice = 1;
                    } else {
                        std::cout << "Invalid choice! Pick either A or B" << std::endl;
                    }
                }

                if (choice == 'A') {
                    int pieceNum;
                    std::cout << "Choose a pawn to move (0-3)" << std::endl;
                    std::cin >> pieceNum;
                    if (Check_For_Valid_Move(playerNum, pieceNum, b, 8)) {
                        Move_Pawn(playerNum, pieceNum, b, 8);
                        action_completed = 1;
                    } else {
                        std::cout << "Invalid move attempt. Try again." << std::endl;
                    }
                } else if (choice == 'B') {
                    std::cout << "Forfeited Turn" << std::endl;
                    action_completed = 1;
                }
            }
            break;

        case 10:    // move pawn +10 or -1 spaces
            while (action_completed == 0) {
                valid_choice = 0;
                while (!valid_choice) {  // checks for a valid card choice entry
                    std::cin >> choice;
                    if (choice == 'A' || choice == 'B' || choice == 'C') {
                        valid_choice = 1;
                    } else {
                        std::cout << "Invalid choice! Pick either A, B, or C" << std::endl;
                    }
                }

                if (choice == 'A') {
                    int pieceNum;
                    std::cout << "Choose a pawn to move (0-3)" << std::endl;
                    std::cin >> pieceNum;
                    if (Check_For_Valid_Move(playerNum, pieceNum, b, 10)) {
                        Move_Pawn(playerNum, pieceNum, b, 10);
                        action_completed = 1;
                    } else {
                        std::cout << "Invalid move attempt. Try again." << std::endl;
                    }
                } else if (choice == 'B') {
                    int pieceNum;
                    std::cout << "Choose a pawn to move (0-3)" << std::endl;
                    std::cin >> pieceNum;
                    if (Check_For_Valid_Move(playerNum, pieceNum, b, -1)) {
                        Move_Pawn(playerNum, pieceNum, b, -1);
                        action_completed = 1;
                    } else {
                        std::cout << "Invalid move attempt. Try again." << std::endl;
                    }
                }
                else {
                    std::cout << "Forfeited Turn" << std::endl;
                    action_completed = 1;
                }
            }
            break;

        case 11:    // move +11 spaces or swap board positions
            while (action_completed == 0) {
                valid_choice = 0;
                while (!valid_choice) {  // checks for a valid card choice entry
                    std::cin >> choice;
                    if (choice == 'A' || choice == 'B' || choice == 'C') {
                        valid_choice = 1;
                    } else {
                        std::cout << "Invalid choice! Pick either A, B, or C" << std::endl;
                    }
                }

                if (choice == 'A') {
                    int pieceNum;
                    std::cout << "Choose a pawn to move (0-3)" << std::endl;
                    std::cin >> pieceNum;
                    if (Check_For_Valid_Move(playerNum, pieceNum, b, 11)) {
                        Move_Pawn(playerNum, pieceNum, b, 11);
                        action_completed = 1;
                    } else {
                        std::cout << "Invalid move attempt. Try again." << std::endl;
                    }
                } else if (choice == 'B') {
                    int swapNum, pieceNum, swapPiece;
                    std::cout << "Select a pawn of yours (0-3) to swap" << std::endl;
                    std::cin >> pieceNum;
                    std::cout << "Select an opponent to swap with (Red - 0, Blue - 1, Yellow - 2, Green - 3)" << std::endl;
                    std::cin >> swapNum;
                    std::cout << "Select an opponent's pawn (0-3) to swap with" << std::endl;
                    std::cin >> swapPiece;
                    if(Check_For_Valid_Swap(playerNum, swapNum, pieceNum, swapPiece, b)) {
                        Swap_Pawn(playerNum, swapNum, pieceNum, swapPiece, b);
                        action_completed = 1;
                    }
                    else {
                        std::cout << "Invalid swap attempt. Try again" << std::endl;
                    }
                }
                else {
                    std::cout << "Forfeited Turn" << std::endl;
                    action_completed = 1;
                }
            }
            break;

        case 12:    // move pawn +12 spaces
            while (action_completed == 0) {
                valid_choice = 0;
                while (!valid_choice) {  // checks for a valid card choice entry
                    std::cin >> choice;
                    if (choice == 'A' || choice == 'B') {
                        valid_choice = 1;
                    } else {
                        std::cout << "Invalid choice! Pick either A or B" << std::endl;
                    }
                }

                if (choice == 'A') {
                    int pieceNum;
                    std::cout << "Choose a pawn to move (0-3)" << std::endl;
                    std::cin >> pieceNum;
                    if (Check_For_Valid_Move(playerNum, pieceNum, b, 12)) {
                        Move_Pawn(playerNum, pieceNum, b, 12);
                        action_completed = 1;
                    } else {
                        std::cout << "Invalid move attempt. Try again." << std::endl;
                    }
                } else if (choice == 'B') {
                    std::cout << "Forfeited Turn" << std::endl;
                    action_completed = 1;
                }
            }
            break;

        case 13:    // Sorry! action
            while (action_completed == 0) {
                valid_choice = 0;
                while (!valid_choice) {  // checks for a valid card choice entry
                    std::cin >> choice;
                    if (choice == 'A' || choice == 'B') {
                        valid_choice = 1;
                    } else {
                        std::cout << "Invalid choice! Pick either A or B" << std::endl;
                    }
                }

                if (choice == 'A') {
                    int swapNum, pieceNum, swapPiece;
                    std::cout << "Select a pawn of yours (0-3) to swap" << std::endl;
                    std::cin >> pieceNum;
                    std::cout << "Select an opponent to swap with (Red - 0, Blue - 1, Yellow - 2, Green - 3)" << std::endl;
                    std::cin >> swapNum;
                    std::cout << "Select an opponent pawn (0-3) to swap with" << std::endl;
                    std::cin >> swapPiece;
                    if (Check_For_Valid_Sorry(playerNum, swapNum, pieceNum, swapPiece, b)) {
                        Sorry_Move(playerNum, swapNum, pieceNum, swapPiece, b);
                        action_completed = 1;
                    } else {
                        std::cout << "Invalid Sorry! attempt. Try again." << std::endl;
                    }
                } else if (choice == 'B') {
                    std::cout << "Forfeited Turn" << std::endl;
                    action_completed = 1;
                }
            }
            break;
        default: break;
    }
}

void Card_Rules::Ask_Computer_For_Move(int playerNum, int card, Sorry_Board &b) {
    // First Check if a pawn can get Home
    if (All_Pawns_At_Start(playerNum, b)) {
        if (card != 1 && card != 2 && card != 13)
            return;
    }
    if (card != 13 && card != 4) { //Cannot Get Home on a Sorry or Back 4 Card
        for (int i = 0; i < 4; i++) {
            if (playerNum == 0) {
                if (Distance_From_Home(b.red[i]) == card) {
                    Move_Pawn(playerNum, i, b, card);
                    return;
                }
            } else if (playerNum == 1) {
                if (Distance_From_Home(b.blue[i]) == card) {
                    Move_Pawn(playerNum, i, b, card);
                    return;
                }
            } else if (playerNum == 2) {
                if (Distance_From_Home(b.yellow[i]) == card) {
                    Move_Pawn(playerNum, i, b, card);
                    return;
                }
            } else if (playerNum == 3) {
                if (Distance_From_Home(b.green[i]) == card) {
                    Move_Pawn(playerNum, i, b, card);
                    return;
                }
            }
        }
    }
    //If no pawn can get home Do this...
    for (int p = 0; p < 4; p++) {
        if (p == playerNum) {
            switch (card) {
                case 1 :
                case 2 :
                    for (int i = 0; i < 4; i++) {
                        if (Check_For_Valid_Start(playerNum, b)) {
                            if (playerNum == 0) {
                                if (b.red[i]->getStart()) {
                                    b.red[i]->setXPos(0);
                                    b.red[i]->setYPos(12);
                                    b.red[i]->setStart();    //false
                                    b.Update_Board();
                                    return;
                                }
                            } else if (playerNum == 1) {
                                if (b.blue[i]->getStart()) {
                                    b.blue[i]->setXPos(3);
                                    b.blue[i]->setYPos(0);
                                    b.blue[i]->setStart();    //false
                                    b.Update_Board();
                                    return;
                                }
                            } else if (playerNum == 2) {
                                if (b.yellow[i]->getStart()) {
                                    b.yellow[i]->setXPos(15);
                                    b.yellow[i]->setYPos(3);
                                    b.yellow[i]->setStart();    //false
                                    b.Update_Board();
                                    return;
                                }
                            } else if (playerNum == 3) {
                                if (b.green[i]->getStart()) {
                                    b.green[i]->setXPos(12);
                                    b.green[i]->setYPos(15);
                                    b.green[i]->setStart();    //false
                                    b.Update_Board();
                                    return;
                                }
                            }
                        } else {
                            if (playerNum == 0) {
                                if (b.red[i]->getXPos() == 0 && b.red[i]->getYPos() == 12) {
                                    if (Check_For_Valid_Move(playerNum, i, b, card)) {
                                        Move_Pawn(playerNum, i, b, card);
                                        return;
                                    }
                                }
                            } else if (playerNum == 1) {
                                if (b.blue[i]->getXPos() == 3 && b.blue[i]->getYPos() == 0) {
                                    if (Check_For_Valid_Move(playerNum, i, b, card)) {
                                        Move_Pawn(playerNum, i, b, card);
                                        return;
                                    }
                                }
                            } else if (playerNum == 2) {
                                if (b.yellow[i]->getXPos() == 15 && b.yellow[i]->getYPos() == 3) {
                                    if (Check_For_Valid_Move(playerNum, i, b, card)) {
                                        Move_Pawn(playerNum, i, b, card);
                                        return;
                                    }
                                }
                            } else if (playerNum == 2) {
                                if (b.green[i]->getXPos() == 12 && b.green[i]->getYPos() == 15) {
                                    if (Check_For_Valid_Move(playerNum, i, b, card)) {
                                        Move_Pawn(playerNum, i, b, card);
                                        return;
                                    }
                                }
                            }
                        }
                    }
                    //No starting move, find another pawn to move
                    for (int i = 0; i < 4; i++) {
                        if (playerNum == 0) {
                            if (Check_For_Valid_Move(playerNum, i, b, card))
                                Move_Pawn(playerNum, i, b, card);
                        } else if (playerNum == 1) {
                            if (Check_For_Valid_Move(playerNum, i, b, card))
                                Move_Pawn(playerNum, i, b, card);
                        } else if (playerNum == 2) {
                            if (Check_For_Valid_Move(playerNum, i, b, card))
                                Move_Pawn(playerNum, i, b, card);
                        } else if (playerNum == 3) {
                            if (Check_For_Valid_Move(playerNum, i, b, card))
                                Move_Pawn(playerNum, i, b, card);
                        }
                    }
                    break;
                case 3 :
                    for (int i = 0; i < 4; i++) {
                        if (Check_For_Valid_Move(playerNum, i, b, card)) {
                            Move_Pawn(playerNum, i, b, card);
                            return;
                        }
                    }
                    break;
                case 4 :
                    card = -(card);
                    for (int i = 0; i < 4; i++) {
                        if (Check_For_Valid_Move(playerNum, i, b, card)) {
                            Move_Pawn(playerNum, i, b, card);
                            return;
                        }
                    }
                    break;
                case 5 :
                case 7 :
                case 8 :
                    for (int i = 0; i < 4; i++) {
                        if (Check_For_Valid_Move(playerNum, i, b, card)) {
                            Move_Pawn(playerNum, i, b, card);
                            return;
                        }
                    }
                    break;
                case 10 :
                    //Try forward movement first
                    for (int i = 0; i < 4; i++) {
                        if (Check_For_Valid_Move(playerNum, i, b, card)) {
                            Move_Pawn(playerNum, i, b, card);
                            return;
                        }
                    }
                    //If no forward movement, try back 1
                    for (int i = 0; i < 4; i++) {
                        if (Check_For_Valid_Move(playerNum, i, b, -1)) {
                            Move_Pawn(playerNum, i, b, -1);
                            return;
                        }
                    }
                    break;
                case 11 : {
                    //The computer will try to swap with the closest pawn to their safe zone first
                    int dist = 0;
                    int closeStart;
                    int closeSafe[4];
                    int pawnNumToSwap = 5;
                    int playerNumToSwap = 5;
                    //Get the closest to start of computers pawns
                    for (int i = 0; i < 4; i++) {
                        if (playerNum == 0) {
                            if (Distance_From_Home(b.red[i]) > dist) {
                                dist = Distance_From_Home(b.red[i]);
                                closeStart = i;
                            }
                        } else if (playerNum == 1) {
                            if (Distance_From_Home(b.blue[i]) > dist) {
                                dist = Distance_From_Home(b.blue[i]);
                                closeStart = i;
                            }
                        } else if (playerNum == 2) {
                            if (Distance_From_Home(b.yellow[i]) > dist) {
                                dist = Distance_From_Home(b.yellow[i]);
                                closeStart = i;
                            }
                        } else if (playerNum == 3) {
                            if (Distance_From_Home(b.green[i]) > dist) {
                                dist = Distance_From_Home(b.green[i]);
                                closeStart = i;
                            }
                        }
                        // Get the opponent with the closest pawn to home.
                        closeSafe[i] = Closest_To_Home(i, b);
                    }

                    for (int i = 0; i < 4; i++) {
                        if (i != playerNum) {
                            if (Check_For_Valid_Swap(playerNum, i, closeStart, closeSafe[i], b)) {
                                Swap_Pawn(playerNum, i, closeStart, closeSafe[i], b);
                                return;
                            }
                        }
                    }
                    for (int i = 0; i < 4; i++) {
                        if (Check_For_Valid_Move(playerNum, i, b, card)) {
                            Move_Pawn(playerNum, i, b, card);
                            return;
                        }
                    }

                    break; }
                case 12 :
                    for (int i = 0; i < 4; i++) {
                        if (Check_For_Valid_Move(playerNum, i, b, card)) {
                            Move_Pawn(playerNum, i, b, card);
                            return;
                        }
                    }
                    break;
                case 13 : {
                    int pawnToSwap = 5;
                    int playerToSwap = 5;
                    //Get a valid pawn for Sorry Card
                    for (int i = 3; i <= 0; i--) {
                        if (playerNum == 0) {
                            if (b.red[i]->getStart()) {
                                pawnToSwap = i;
                            }
                        } else if (playerNum == 1) {
                            if (b.blue[i]->getStart()) {
                                pawnToSwap = i;
                            }
                        } else if (playerNum == 2) {
                            if (b.yellow[i]->getStart()) {
                                pawnToSwap = i;
                            }
                        } else if (playerNum == 3) {
                            if (b.green[i]->getStart()) {
                                pawnToSwap = i;
                            }
                        }
                    }
                    if (pawnToSwap < 5) {
                        for (int i = 0; i < 4; i++) {
                            for (int j = 0; j < 4; j++) {
                                if (Check_For_Valid_Sorry(playerNum, i, pawnToSwap, j, b)) {
                                    Sorry_Move(playerNum, i, pawnToSwap, j, b);
                                    break;
                                }
                            }
                        }
                    }
                    break; }
                default :
                    break;
            }
        }
    }
}

void Card_Rules::Move_Pawn(int playerNum, int pieceNum, Sorry_Board &b, int dist){
    // MOVES PAWNS FORWARDS & BACKWARDS THROUGHOUT THE BOARD AFTER VALIDATION OF MOVEMENT FROM CHECK_FOR_VALID_MOVE

    int pX;
    int pY;
    int inSafe = 0;
    int outSafe = 0;

    if (playerNum == 0) {   // RED player
        pX = b.red[pieceNum]->getXPos();
        pY = b.red[pieceNum]->getYPos();

        if(dist > 0) {  // forward movement
            while (dist > 0) {
                if(!b.red[pieceNum]->getSafe() && !b.red[pieceNum]->getHome() && !inSafe) {// check if pawn is in safe/home zones
                    if (pY == 0 && pX < 15) {
                        pX++;
                        dist--;
                    } else if (pX == 15 && pY < 15) {
                        pY++;
                        dist--;
                    } else if (pY == 15 && pX > 0) {
                        pX--;
                        dist--;
                    } else if (pX == 0 && pY > 0) {
                        //check for RED safe zone here
                        if(pX == 0 && pY == 13) {
                            pX++;
                            inSafe = 1;
                            //b.red[pieceNum]->setSafe(); // pawn is in safe zone
                        }
                        else {
                            pY--;
                        }
                        dist--;
                    }
                }
                else if((b.red[pieceNum]->getSafe() && !(b.red[pieceNum]->getHome())) || inSafe) { // check if pawn is in Safe zone
                    pX++;   // pY = 13 always when pawn->isSafe = true
                    dist--;
                }
            }
        }
        else if (dist < 0) { // backwards movement
            while (dist < 0) {
                if((!b.red[pieceNum]->getSafe() && !b.red[pieceNum]->getHome()) || outSafe) {// check if pawn is in safe/home zones
                    if (pY == 0 && pX <= 15) {
                        pX--;
                        dist++;
                    } else if (pX == 15 && pY <= 15) {
                        pY--;
                        dist++;
                    } else if (pY == 15 && pX >= 0) {
                        pX++;
                        dist++;
                    } else if (pX == 0 && pY >= 0) {
                        pY++;
                        dist++;
                    }
                }
                else if(b.red[pieceNum]->getSafe() && !b.red[pieceNum]->getHome() && !outSafe) { // checks if pawn is in Safe zone
                    pX--;
                    dist++;
                    // checks if backwards movement puts pawn out of safe zone
                    if(pX == 0 && pY == 13) {
                        //b.red[pieceNum]->setSafe();
                        outSafe = 1;
                    }
                }

            }
        }

        if(b.Board[pY][pX] != nullptr) {
            Pawn_To_Start(pX, pY, b.Board[pY][pX]->getColor(), b);
        }

        b.red[pieceNum]->setXPos(pX);
        b.red[pieceNum]->setYPos(pY);
        b.red[pieceNum]->Update_Pawn_Status();
        b.Update_Board();
    }

    if(playerNum == 1) {    // BLUE player
        pX = b.blue[pieceNum]->getXPos();
        pY = b.blue[pieceNum]->getYPos();

        if(dist > 0) {  // forward movement
            while (dist > 0) {
                if(!b.blue[pieceNum]->getSafe() && !b.blue[pieceNum]->getHome() && !inSafe) {// check if pawn is in safe/home zones
                    if (pY == 0 && pX < 15) {
                        if(pX == 2 && pY == 0) {
                            pY++;
                            inSafe = 1;
                            //b.blue[pieceNum]->setSafe(); // pawn is in safe zone
                        }
                        else {
                            pX++;
                        }
                        dist--;
                        //check for BLUE safe zone here

                    } else if (pX == 15 && pY < 15) {
                        pY++;
                        dist--;
                    } else if (pY == 15 && pX > 0) {
                        pX--;
                        dist--;
                    } else if (pX == 0 && pY > 0) {
                        pY--;
                        dist--;
                    }
                }
                else if((b.blue[pieceNum]->getSafe() && !b.blue[pieceNum]->getHome()) || inSafe) { // check if pawn is in Safe zone
                    pY++;   // pX = 2 always when pawn->isSafe = true
                    dist--;
                }
            }
        }
        else if (dist < 0) { // backwards movement check
            while (dist < 0) {
                if((!b.blue[pieceNum]->getSafe() && !b.blue[pieceNum]->getHome()) || outSafe) {// check if pawn is in safe/home zones
                    if (pY == 0 && pX <= 15) {
                        pX--;
                        dist++;
                    } else if (pX == 15 && pY <= 15) {
                        pY--;
                        dist++;
                    } else if (pY == 15 && pX >= 0) {
                        pX++;
                        dist++;
                    } else if (pX == 0 && pY >= 0) {
                        pY++;
                        dist++;
                    }
                }
                else if(b.blue[pieceNum]->getSafe() && !b.blue[pieceNum]->getHome() && !outSafe) { // checks if pawn is in Safe zone
                    pY--;
                    dist++;
                    // checks if backwards movement puts pawn out of safe zone
                    if(pX == 2 && pY == 0) {
                        outSafe = 1;
                    }
                }
            }
        }

        if(b.Board[pY][pX] != nullptr) {
            Pawn_To_Start(pX, pY, b.Board[pY][pX]->getColor(), b);
        }

        b.blue[pieceNum]->setXPos(pX);
        b.blue[pieceNum]->setYPos(pY);
        b.blue[pieceNum]->Update_Pawn_Status();
        b.Update_Board();
    }

    if(playerNum == 2) {    // YELLOW player
        pX = b.yellow[pieceNum]->getXPos();
        pY = b.yellow[pieceNum]->getYPos();

        if(dist > 0) {  // forward movement
            while (dist > 0) {
                if(!b.yellow[pieceNum]->getSafe() && !b.yellow[pieceNum]->getHome() && !inSafe) {// check if pawn is in safe/home zones
                    if (pY == 0 && pX < 15) {
                        pX++;
                        dist--;
                    } else if (pX == 15 && pY < 15) {
                        //check for YELLOW safe zone here
                        if(pX == 15 && pY == 2) {
                            pX--;
                            inSafe = 1;
                            //b.yellow[pieceNum]->setSafe(); // pawn is in safe zone
                        }
                        else {
                            pY++;
                        }
                        dist--;
                    } else if (pY == 15 && pX > 0) {
                        pX--;
                        dist--;
                    } else if (pX == 0 && pY > 0) {
                        pY--;
                        dist--;
                    }
                }
                else if((b.yellow[pieceNum]->getSafe() && !b.yellow[pieceNum]->getHome()) || inSafe) { // check if pawn is in Safe zone
                    pX--;   // pY = 2 always when pawn->isSafe = true
                    dist--;
                    // need to check if pawn is in home or not, must turn off movement when it is in home
                }
            }
        }
        else if (dist < 0) { // backwards movement check
            while (dist < 0) {
                if((!b.yellow[pieceNum]->getSafe() && !b.yellow[pieceNum]->getHome()) || outSafe) {// check if pawn is in safe/home zones
                    if (pY == 0 && pX <= 15) {
                        pX--;
                        dist++;
                    } else if (pX == 15 && pY <= 15) {
                        pY--;
                        dist++;
                    } else if (pY == 15 && pX >= 0) {
                        pX++;
                        dist++;
                    } else if (pX == 0 && pY >= 0) {
                        pY++;
                        dist++;
                    }
                }
                else if(b.yellow[pieceNum]->getSafe() && !b.yellow[pieceNum]->getHome() && !outSafe) { // checks if pawn is in Safe zone
                    pX++;
                    dist++;
                    // checks if backwards movement puts pawn out of safe zone
                    if(pX == 15 && pY == 2) {
                        outSafe = 1;
                        //b.yellow[pieceNum]->setSafe();
                    }
                }
            }
        }

        if(b.Board[pY][pX] != nullptr) {
            Pawn_To_Start(pX, pY, b.Board[pY][pX]->getColor(), b);
        }

        b.yellow[pieceNum]->setXPos(pX);
        b.yellow[pieceNum]->setYPos(pY);
        b.yellow[pieceNum]->Update_Pawn_Status();
        b.Update_Board();
    }

    if(playerNum == 3) {    // GREEN player
        pX = b.green[pieceNum]->getXPos();
        pY = b.green[pieceNum]->getYPos();

        if(dist > 0) {  // forward movement
            while (dist > 0) {
                if(!b.green[pieceNum]->getSafe() && !b.green[pieceNum]->getHome() && !inSafe) {// check if pawn is in safe/home zones
                    if (pY == 0 && pX < 15) {
                        pX++;
                        dist--;
                    } else if (pX == 15 && pY < 15) {
                        pY++;
                        dist--;
                    } else if (pY == 15 && pX > 0) {
                        //check for GREEN safe zone here
                        if(pX == 13 && pY == 15) {
                            pY--;
                            inSafe = 1;
                            //b.green[pieceNum]->setSafe(); // pawn is in safe zone
                        }
                        else {
                            pX--;
                        }
                        dist--;
                    } else if (pX == 0 && pY > 0) {
                        pY--;
                        dist--;
                    }
                }
                else if((b.green[pieceNum]->getSafe() && !b.green[pieceNum]->getHome()) || inSafe) { // check if pawn is in Safe zone
                    pY--;   // pX = 13 always when pawn->isSafe = true
                    dist--;
                }
            }
        }
        else if (dist < 0) { // backwards movement check
            while (dist < 0) {
                if((!b.green[pieceNum]->getSafe() && !b.green[pieceNum]->getHome()) || outSafe) {// check if pawn is in safe/home zones
                    if (pY == 0 && pX <= 15) {
                        pX--;
                        dist++;
                    } else if (pX == 15 && pY <= 15) {
                        pY--;
                        dist++;
                    } else if (pY == 15 && pX >= 0) {
                        pX++;
                        dist++;
                    } else if (pX == 0 && pY >= 0) {
                        pY++;
                        dist++;
                    }
                }
                else if(b.green[pieceNum]->getSafe() && !b.yellow[pieceNum]->getHome() && !outSafe) { // checks if pawn is in Safe zone
                    pY++;
                    dist++;
                    // checks if backwards movement puts pawn out of safe zone
                    if(pX == 13 && pY == 15) {
                        outSafe = 1;
                        //b.green[pieceNum]->setSafe();
                    }
                }
            }
        }

        if(b.Board[pY][pX] != nullptr) {
            Pawn_To_Start(pX, pY, b.Board[pY][pX]->getColor(), b);
        }

        b.green[pieceNum]->setXPos(pX);
        b.green[pieceNum]->setYPos(pY);
        b.green[pieceNum]->Update_Pawn_Status();
        b.Update_Board();
    }

}

void Card_Rules::Start_Pawn(int playerNum, Sorry_Board &b){
    // PUTS A PAWN IN ITS STARTING POSITION ON THE BOARD AFTER VALIDATION FROM CHECK_FOR_VALID_START

    int pieceNum;
    int completed = 0;
    while(completed == 0) {
        std::cout << "Enter what pawn to put in play (0-3):" << std::endl;
        std::cin >> pieceNum;
        if (pieceNum <= 3 && pieceNum >= 0) {
            if(playerNum == 0) {    // RED player
                if (b.red[pieceNum]->getStart()) { // valid pawn selected, pawn is at start position
                    if(b.Board[12][0] != nullptr) {
                        Pawn_To_Start(0, 12, b.Board[12][0]->getColor(), b);
                    }
                    b.red[pieceNum]->setXPos(0);
                    b.red[pieceNum]->setYPos(12);
                    b.red[pieceNum]->setStart();    //false
                    b.Update_Board();
                    completed = 1;
                } else { // invalid pawn selected (pawn is already on the board), ask again
                    std::cout << "Selected pawn is already on the board, choose a new pawn" << std::endl;
                }
            }
            else if(playerNum == 1) {   // BLUE player
                if (b.blue[pieceNum]->getStart()) { // valid pawn selected, pawn is at start position
                    if(b.Board[0][3] != nullptr) {
                        Pawn_To_Start(3, 0, b.Board[0][3]->getColor(), b);
                    }
                    b.blue[pieceNum]->setXPos(3);
                    b.blue[pieceNum]->setYPos(0);
                    b.blue[pieceNum]->setStart();   // false
                    b.Update_Board();
                    completed = 1;
                } else { // invalid pawn selected (pawn is already on the board), ask again
                    std::cout << "Selected pawn is already on the board, choose a new pawn" << std::endl;
                }
            }
            else if(playerNum == 2) {   // YELLOW player
                if (b.yellow[pieceNum]->getStart()) { // valid pawn selected, pawn is at start position
                    if(b.Board[3][15] != nullptr) {
                        Pawn_To_Start(15, 3, b.Board[3][15]->getColor(), b);
                    }
                    b.yellow[pieceNum]->setXPos(15);
                    b.yellow[pieceNum]->setYPos(3);
                    b.yellow[pieceNum]->setStart(); //false
                    b.Update_Board();
                    completed = 1;
                } else { // invalid pawn selected (pawn is already on the board), ask again
                    std::cout << "Selected pawn is already on the board, choose a new pawn" << std::endl;
                }
            }
            else if(playerNum == 3) {   // GREEN player
                if (b.green[pieceNum]->getStart()) { // valid pawn selected, pawn is at start position
                    if(b.Board[15][12] != nullptr) {
                        Pawn_To_Start(12, 15, b.Board[15][12]->getColor(), b);
                    }
                    b.green[pieceNum]->setXPos(12);
                    b.green[pieceNum]->setYPos(15);
                    b.green[pieceNum]->setStart();  //false
                    b.Update_Board();
                    completed = 1;
                } else { // invalid pawn selected (pawn is already on the board), ask again
                    std::cout << "Selected pawn is already on the board, choose a new pawn" << std::endl;
                }
            }
        } else { // invalid entry, ask again
            std::cout << "Invalid pawn piece entry. Entry needs to be between 0 and 3" << std::endl;
        }
    }
}

void Card_Rules::Pawn_To_Start(int x, int y, std::string color, Sorry_Board &b) {
    // MOVES PAWNS ON BOARD BACK TO START ZONE IF LANDED ON BY ANOTHER COLOR OR SELECTED BY SORRY! ACTION

    int tmpx;
    int tmpy;

    if (color == "Red") {
        for (int i = 0; i < 4; i++) {
            tmpx = b.red[i]->getXPos();
            tmpy = b.red[i]->getYPos();
            if (tmpx == x && tmpy == y) {
                tmpx = b.red[i]->getPieceNum() + 1;
                tmpy = 12;
                b.red[i]->setXPos(tmpx);
                b.red[i]->setYPos(tmpy);
                b.red[i]->Update_Pawn_Status();
                break;
            }
        }
    } else if (color == "Blue") {
        for (int i = 0; i < 4; i++) {
            tmpx = b.blue[i]->getXPos();
            tmpy = b.blue[i]->getYPos();
            if (tmpx == x && tmpy == y) {
                tmpx = 3;
                tmpy = b.blue[i]->getPieceNum() + 1;
                b.blue[i]->setXPos(tmpx);
                b.blue[i]->setYPos(tmpy);
                b.blue[i]->Update_Pawn_Status();
                break;
            }
        }
    } else if (color == "Yellow") {
        for (int i = 0; i < 4; i++) {
            tmpx = b.yellow[i]->getXPos();
            tmpy = b.yellow[i]->getYPos();
            if (tmpx == x && tmpy == y) {
                tmpx = 11 + b.yellow[i]->getPieceNum();
                tmpy = 3;
                b.yellow[i]->setXPos(tmpx);
                b.yellow[i]->setYPos(tmpy);
                b.yellow[i]->Update_Pawn_Status();
                break;
            }
        }
    } else if (color == "Green") {
        for (int i = 0; i < 4; i++) {
            tmpx = b.green[i]->getXPos();
            tmpy = b.green[i]->getYPos();
            if (tmpx == x && tmpy == y) {
                tmpx = 12;
                tmpy = 11 + b.green[i]->getPieceNum();
                b.green[i]->setXPos(tmpx);
                b.green[i]->setYPos(tmpy);
                b.green[i]->Update_Pawn_Status();
                break;
            }
        }
    }
}

void Card_Rules::Swap_Pawn(int playerNum, int swapNum, int pieceNum, int swapPiece, Sorry_Board &b) {
    // SWAPS POSITIONS OF PAWNS ON THE BOARD AFTER VALIDATION FROM CHECK_FOR_VALID_SWAP

    if(playerNum == 0) {
        int tmpx = b.red[pieceNum]->getXPos();
        int tmpy = b.red[pieceNum]->getYPos();

        if(swapNum == 1) {
            b.red[pieceNum]->setXPos(b.blue[swapPiece]->getXPos());
            b.red[pieceNum]->setYPos(b.blue[swapPiece]->getYPos());
            b.blue[swapPiece]->setXPos(tmpx);
            b.blue[swapPiece]->setYPos(tmpy);
        }
        else if(swapNum == 2) {
            b.red[pieceNum]->setXPos(b.yellow[swapPiece]->getXPos());
            b.red[pieceNum]->setYPos(b.yellow[swapPiece]->getYPos());
            b.yellow[swapPiece]->setXPos(tmpx);
            b.yellow[swapPiece]->setYPos(tmpy);
        }
        else if(swapNum == 3) {
            b.red[pieceNum]->setXPos(b.green[swapPiece]->getXPos());
            b.red[pieceNum]->setYPos(b.green[swapPiece]->getYPos());
            b.green[swapPiece]->setXPos(tmpx);
            b.green[swapPiece]->setYPos(tmpy);
        }
    }

    else if(playerNum == 1) {
        int tmpx = b.blue[pieceNum]->getXPos();
        int tmpy = b.blue[pieceNum]->getYPos();

        if(swapNum == 0) {
            b.blue[pieceNum]->setXPos(b.red[swapPiece]->getXPos());
            b.blue[pieceNum]->setYPos(b.red[swapPiece]->getYPos());
            b.red[swapPiece]->setXPos(tmpx);
            b.red[swapPiece]->setYPos(tmpy);
        }
        else if(swapNum == 2) {
            b.blue[pieceNum]->setXPos(b.yellow[swapPiece]->getXPos());
            b.blue[pieceNum]->setYPos(b.yellow[swapPiece]->getYPos());
            b.yellow[swapPiece]->setXPos(tmpx);
            b.yellow[swapPiece]->setYPos(tmpy);
        }
        else if(swapNum == 3) {
            b.blue[pieceNum]->setXPos(b.green[swapPiece]->getXPos());
            b.blue[pieceNum]->setYPos(b.green[swapPiece]->getYPos());
            b.green[swapPiece]->setXPos(tmpx);
            b.green[swapPiece]->setYPos(tmpy);
        }
    }

    else if(playerNum == 2) {
        int tmpx = b.yellow[pieceNum]->getXPos();
        int tmpy = b.yellow[pieceNum]->getYPos();

        if(swapNum == 0) {
            b.yellow[pieceNum]->setXPos(b.red[swapPiece]->getXPos());
            b.yellow[pieceNum]->setYPos(b.red[swapPiece]->getYPos());
            b.red[swapPiece]->setXPos(tmpx);
            b.red[swapPiece]->setYPos(tmpy);
        }
        else if(swapNum == 1) {
            b.yellow[pieceNum]->setXPos(b.blue[swapPiece]->getXPos());
            b.yellow[pieceNum]->setYPos(b.blue[swapPiece]->getYPos());
            b.blue[swapPiece]->setXPos(tmpx);
            b.blue[swapPiece]->setYPos(tmpy);
        }
        else if(swapNum == 3) {
            b.yellow[pieceNum]->setXPos(b.green[swapPiece]->getXPos());
            b.yellow[pieceNum]->setYPos(b.green[swapPiece]->getYPos());
            b.green[swapPiece]->setXPos(tmpx);
            b.green[swapPiece]->setYPos(tmpy);
        }
    }

    else if(playerNum == 3) {
        int tmpx = b.green[pieceNum]->getXPos();
        int tmpy = b.green[pieceNum]->getYPos();

        if(swapNum == 0) {
            b.green[pieceNum]->setXPos(b.red[swapPiece]->getXPos());
            b.green[pieceNum]->setYPos(b.red[swapPiece]->getYPos());
            b.red[swapPiece]->setXPos(tmpx);
            b.red[swapPiece]->setYPos(tmpy);
        }
        else if(swapNum == 1) {
            b.green[pieceNum]->setXPos(b.blue[swapPiece]->getXPos());
            b.green[pieceNum]->setYPos(b.blue[swapPiece]->getYPos());
            b.blue[swapPiece]->setXPos(tmpx);
            b.blue[swapPiece]->setYPos(tmpy);
        }
        else if(swapNum == 2) {
            b.green[pieceNum]->setXPos(b.yellow[swapPiece]->getXPos());
            b.green[pieceNum]->setYPos(b.yellow[swapPiece]->getYPos());
            b.yellow[swapPiece]->setXPos(tmpx);
            b.yellow[swapPiece]->setYPos(tmpy);
        }
    }

    b.Update_Board();
}

void Card_Rules::Sorry_Move(int playerNum, int swapNum, int pieceNum, int swapPiece, Sorry_Board &b) {
    // REPLACES A PAWNS START POSITION WITH PAWN ON THE BOARD. SENDS THE PAWN ON THE BOARD BACK TO ITS START POSITION
    // AFTER VALIDATION FROM CHECK_FOR_VALID_SORRY

    int tmpx;
    int tmpy;

    if(playerNum == 0) {
        if(swapNum == 1) {
            tmpx = b.blue[swapPiece]->getXPos();
            tmpy = b.blue[swapPiece]->getYPos();
            Pawn_To_Start(tmpx, tmpy, "Blue", b);
            b.red[pieceNum]->setXPos(tmpx);
            b.red[pieceNum]->setYPos(tmpy);

            b.red[pieceNum]->Update_Pawn_Status();
            b.blue[pieceNum]->Update_Pawn_Status();
        }
        else if(swapNum == 2) {
            tmpx = b.yellow[swapPiece]->getXPos();
            tmpy = b.yellow[swapPiece]->getYPos();
            Pawn_To_Start(tmpx, tmpy, "Yellow", b);
            b.red[pieceNum]->setXPos(tmpx);
            b.red[pieceNum]->setYPos(tmpy);

            b.red[pieceNum]->Update_Pawn_Status();
            b.yellow[pieceNum]->Update_Pawn_Status();
        }
        else if(swapNum == 3) {
            tmpx = b.green[swapPiece]->getXPos();
            tmpy = b.green[swapPiece]->getYPos();
            Pawn_To_Start(tmpx, tmpy, "Green", b);
            b.red[pieceNum]->setXPos(tmpx);
            b.red[pieceNum]->setYPos(tmpy);

            b.red[pieceNum]->Update_Pawn_Status();
            b.green[pieceNum]->Update_Pawn_Status();

        }
    }
    else if(playerNum == 1) {
        if(swapNum == 0) {
            tmpx = b.red[swapPiece]->getXPos();
            tmpy = b.red[swapPiece]->getYPos();
            Pawn_To_Start(tmpx, tmpy, "Red", b);
            b.blue[pieceNum]->setXPos(tmpx);
            b.blue[pieceNum]->setYPos(tmpy);

            b.blue[pieceNum]->Update_Pawn_Status();
            b.red[pieceNum]->Update_Pawn_Status();
        }
        else if(swapNum == 2) {
            tmpx = b.yellow[swapPiece]->getXPos();
            tmpy = b.yellow[swapPiece]->getYPos();
            Pawn_To_Start(tmpx, tmpy, "Yellow", b);
            b.blue[pieceNum]->setXPos(tmpx);
            b.blue[pieceNum]->setYPos(tmpy);

            b.blue[pieceNum]->Update_Pawn_Status();
            b.yellow[pieceNum]->Update_Pawn_Status();
        }
        else if(swapNum == 3) {
            tmpx = b.green[swapPiece]->getXPos();
            tmpy = b.green[swapPiece]->getYPos();
            Pawn_To_Start(tmpx, tmpy, "Green", b);
            b.blue[pieceNum]->setXPos(tmpx);
            b.blue[pieceNum]->setYPos(tmpy);

            b.blue[pieceNum]->Update_Pawn_Status();
            b.green[pieceNum]->Update_Pawn_Status();

        }
    }
    else if(playerNum == 2) {
        if(swapNum == 0) {
            tmpx = b.red[swapPiece]->getXPos();
            tmpy = b.red[swapPiece]->getYPos();
            Pawn_To_Start(tmpx, tmpy, "Red", b);
            b.yellow[pieceNum]->setXPos(tmpx);
            b.yellow[pieceNum]->setYPos(tmpy);

            b.yellow[pieceNum]->Update_Pawn_Status();
            b.red[pieceNum]->Update_Pawn_Status();
        }
        else if(swapNum == 1) {
            tmpx = b.blue[swapPiece]->getXPos();
            tmpy = b.blue[swapPiece]->getYPos();
            Pawn_To_Start(tmpx, tmpy, "Blue", b);
            b.yellow[pieceNum]->setXPos(tmpx);
            b.yellow[pieceNum]->setYPos(tmpy);

            b.yellow[pieceNum]->Update_Pawn_Status();
            b.blue[pieceNum]->Update_Pawn_Status();
        }
        else if(swapNum == 3) {
            tmpx = b.green[swapPiece]->getXPos();
            tmpy = b.green[swapPiece]->getYPos();
            Pawn_To_Start(tmpx, tmpy, "Green", b);
            b.yellow[pieceNum]->setXPos(tmpx);
            b.yellow[pieceNum]->setYPos(tmpy);

            b.yellow[pieceNum]->Update_Pawn_Status();
            b.green[pieceNum]->Update_Pawn_Status();

        }
    }
    else if(playerNum == 3) {
        if(swapNum == 0) {
            tmpx = b.red[swapPiece]->getXPos();
            tmpy = b.red[swapPiece]->getYPos();
            Pawn_To_Start(tmpx, tmpy, "Red", b);
            b.green[pieceNum]->setXPos(tmpx);
            b.green[pieceNum]->setYPos(tmpy);

            b.green[pieceNum]->Update_Pawn_Status();
            b.red[pieceNum]->Update_Pawn_Status();
        }
        else if(swapNum == 1) {
            tmpx = b.blue[swapPiece]->getXPos();
            tmpy = b.blue[swapPiece]->getYPos();
            Pawn_To_Start(tmpx, tmpy, "Blue", b);
            b.green[pieceNum]->setXPos(tmpx);
            b.green[pieceNum]->setYPos(tmpy);

            b.green[pieceNum]->Update_Pawn_Status();
            b.blue[pieceNum]->Update_Pawn_Status();
        }
        else if(swapNum == 3) {
            tmpx = b.yellow[swapPiece]->getXPos();
            tmpy = b.yellow[swapPiece]->getYPos();
            Pawn_To_Start(tmpx, tmpy, "Yellow", b);
            b.green[pieceNum]->setXPos(tmpx);
            b.green[pieceNum]->setYPos(tmpy);

            b.green[pieceNum]->Update_Pawn_Status();
            b.yellow[pieceNum]->Update_Pawn_Status();
        }
    }

    b.Update_Board();
}

bool Card_Rules::Check_For_Valid_Start(int playerNum, Sorry_Board &b) {
    // CHECKS START SPACE ON BOARD TO VALIDATE DESIRED START ACTION

    if(playerNum == 0) {    // RED player
        // check if any RED pawn is at the Start zone
        if(b.red[0]->getStart() || b.red[1]->getStart() || b.red[2]->getStart() || b.red[3]->getStart()) {
            if (b.Board[12][0] == nullptr) { // no pawns on RED start space
                return true;    // valid move
            } else if (b.Board[12][0]->getColor() != "Red") {    // different color pawn on RED start space
                return true;    // valid move, must send different color pawn back to its home
            } else {  // RED pawn on RED start space
                return false; // invalid move
            }
        }
        else {  // no RED pawns are at start (pawn->atStart == false), invalid move to put pawn at start
            return false;
        }
    }
    else if(playerNum == 1) {    // BLUE player
        // check if any BLUE pawn is at the Start zone
        if(b.blue[0]->getStart() || b.blue[1]->getStart() || b.blue[2]->getStart() || b.blue[3]->getStart()) {
            if (b.Board[0][3] == nullptr) { // no pawns on BLUE start space
                return true;    // valid move
            } else if (b.Board[0][3]->getColor() != "Blue") {    // different color pawn on BLUE start space
                return true;    // valid move, must send different color pawn back to its home
            } else {  // RED pawn on BLUE start space
                return false; // invalid move
            }
        }
        else {  // no BLUE pawns are at start (pawn->atStart == false), invalid move to put pawn at start
            return false;
        }
    }
    else if(playerNum == 2) {    // YELLOW player
        // check if any YELLOW pawn is at the Start zone
        if(b.yellow[0]->getStart() || b.yellow[1]->getStart() || b.yellow[2]->getStart() || b.yellow[3]->getStart()) {
            if (b.Board[3][15] == nullptr) { // no pawns on RED start space
                return true;    // valid move
            } else if (b.Board[3][15]->getColor() != "Yellow") {    // different color pawn on YELLOW start space
                return true;    // valid move, must send different color pawn back to its home
            } else {  // YELLOW pawn on YELLOW start space
                return false; // invalid move
            }
        }
        else {  // no YELLOW pawns are at start (pawn->atStart == false), invalid move to put pawn at start
            return false;
        }
    }
    else {    // playerNum 3 : GREEN player
        // check if any GREEN pawn is at the Start zone
        if(b.green[0]->getStart() || b.green[1]->getStart() || b.green[2]->getStart() || b.green[3]->getStart()) {
            if (b.Board[15][12] == nullptr) { // no pawns on GREEN start space
                return true;    // valid move
            } else if (b.Board[15][12]->getColor() != "Green") {    // different color pawn on GREEN start space
                return true;    // valid move, must send different color pawn back to its home
            } else {  // GREEN pawn on GREEN start space
                return false; // invalid move
            }
        }
        else { // no GREEN pawns are at start (pawn->atStart == false), invalid move to put pawn at start
            return false;
        }
    }
}

bool Card_Rules::Check_For_Valid_Move(int playerNum, int pieceNum, Sorry_Board &b, int dist) {
    // CHECKS FOR OPEN BOARD SPACE OF DESIRED MOVEMENT BEFORE THE PAWN IS MOVED

    int xpos;
    int ypos;
    int inSafe = 0;
    int outSafe = 0;

    if (playerNum == 0) {
        if (b.red[pieceNum]->getHome()) {
            std::cout << "Cannot move. Piece selected is in Home Zone" << std::endl;
            return false;
        } else if (b.red[pieceNum]->getStart()) {
            std::cout << "Cannot move. Piece selected is in Start Zone" << std::endl;
            return false;
        } else {
            xpos = b.red[pieceNum]->getXPos();
            ypos = b.red[pieceNum]->getYPos();
            if (dist > 0) { // forward movement check
                while (dist > 0) {
                    if (!b.red[pieceNum]->getSafe() && !b.red[pieceNum]->getHome() && !inSafe) {// check if pawn is in safe/home zones
                        if (ypos == 0 && xpos < 15) {
                            xpos++;
                            dist--;
                        } else if (xpos == 15 && ypos < 15) {
                            ypos++;
                            dist--;
                        } else if (ypos == 15 && xpos > 0) {
                            xpos--;
                            dist--;
                        } else if (xpos == 0 && ypos > 0) {
                            //check for RED safe zone here
                            if (xpos == 0 && ypos == 13) {
                                xpos++;
                                inSafe = 1;
                                //b.red[pieceNum]->setSafe(); // pawn is in safe zone
                            } else {
                                ypos--;
                            }
                            dist--;
                        }
                    } else if ((b.red[pieceNum]->getSafe() && !(b.red[pieceNum]->getHome())) || inSafe) { // check if pawn is in Safe zone
                        xpos++;   // ypos = 13 always when pawn->isSafe = true
                        dist--;
                    }
                }
            } else if (dist < 0) { // backwards movement
                while (dist < 0) {
                    if ((!b.red[pieceNum]->getSafe() && !b.red[pieceNum]->getHome()) || outSafe) {// check if pawn is in safe/home zones
                        if (ypos == 0 && xpos <= 15) {
                            xpos--;
                            dist++;
                        } else if (xpos == 15 && ypos <= 15) {
                            ypos--;
                            dist++;
                        } else if (ypos == 15 && xpos >= 0) {
                            xpos++;
                            dist++;
                        } else if (xpos == 0 && ypos >= 0) {
                            ypos++;
                            dist++;
                        }
                    } else if (b.red[pieceNum]->getSafe() && !b.red[pieceNum]->getHome() && !outSafe) { // checks if pawn is in Safe zone
                        xpos--;
                        dist++;
                        // checks if backwards movement puts pawn out of safe zone
                        if (xpos == 0 && ypos == 13) {
                            //b.red[pieceNum]->setSafe();
                            outSafe = 1;
                        }
                    }
                }
            }

            if (xpos > 9 && ypos == 13 && xpos != 15) {
                return false;
            } else if (b.Board[ypos][xpos] == nullptr) {
                return true;
            } else if (b.Board[ypos][xpos]->getColor() != "Red") {
                return true;
            } else {
                return false;
            }
        }
    }
    else if (playerNum == 1) {
        if (b.blue[pieceNum]->getHome()) {
            std::cout << "Cannot move. Piece selected is in Home Zone" << std::endl;
            return false;
        } else if (b.blue[pieceNum]->getStart()) {
            std::cout << "Cannot move. Piece selected is in Start Zone" << std::endl;
            return false;
        } else {
            xpos = b.blue[pieceNum]->getXPos();
            ypos = b.blue[pieceNum]->getYPos();
            if (dist > 0) { // forward movement check
                while (dist > 0) {
                    if (!b.blue[pieceNum]->getSafe() && !b.blue[pieceNum]->getHome() && !inSafe) {// check if pawn is in safe/home zones
                        if (ypos == 0 && xpos < 15) {
                            //check for BLUE safe zone here
                            if (xpos == 2 && ypos == 0) {
                                ypos++;
                                inSafe = 1;
                            }
                            else {
                                xpos++;
                            }
                            dist--;
                        } else if (xpos == 15 && ypos < 15) {
                            ypos++;
                            dist--;
                        } else if (ypos == 15 && xpos > 0) {
                            xpos--;
                            dist--;
                        } else if (xpos == 0 && ypos > 0) {
                            ypos--;
                            dist--;
                        }
                    } else if ((b.blue[pieceNum]->getSafe() && !(b.blue[pieceNum]->getHome())) || inSafe) { // check if pawn is in Safe zone
                        ypos++;   // xpos = 2 always when pawn->isSafe = true
                        dist--;
                    }
                }
            } else if (dist < 0) { // backwards movement
                while (dist < 0) {
                    if ((!b.blue[pieceNum]->getSafe() && !b.blue[pieceNum]->getHome()) || outSafe) {// check if pawn is in safe/home zones
                        if (ypos == 0 && xpos <= 15) {
                            xpos--;
                            dist++;
                        } else if (xpos == 15 && ypos <= 15) {
                            ypos--;
                            dist++;
                        } else if (ypos == 15 && xpos >= 0) {
                            xpos++;
                            dist++;
                        } else if (xpos == 0 && ypos >= 0) {
                            ypos++;
                            dist++;
                        }
                    } else if (b.blue[pieceNum]->getSafe() && !b.blue[pieceNum]->getHome() && !outSafe) { // checks if pawn is in Safe zone
                        ypos--;
                        dist++;
                        // checks if backwards movement puts pawn out of safe zone
                        if (xpos == 2 && ypos == 0) {
                            outSafe = 1;
                        }
                    }
                }
            }

            if (xpos == 2 && ypos > 9 && ypos != 15) {
                return false;
            } else if (b.Board[ypos][xpos] == nullptr) {
                return true;
            } else if (b.Board[ypos][xpos]->getColor() != "Blue") {
                return true;
            } else {
                return false;
            }
        }
    }
    else if (playerNum == 2) {
        if (b.yellow[pieceNum]->getHome()) {
            std::cout << "Cannot move. Piece selected is in Home Zone" << std::endl;
            return false;
        } else if (b.yellow[pieceNum]->getStart()) {
            std::cout << "Cannot move. Piece selected is in Start Zone" << std::endl;
            return false;
        } else {
            xpos = b.yellow[pieceNum]->getXPos();
            ypos = b.yellow[pieceNum]->getYPos();
            if (dist > 0) { // forward movement check
                while (dist > 0) {
                    if (!b.yellow[pieceNum]->getSafe() && !b.yellow[pieceNum]->getHome() && !inSafe) {// check if pawn is in safe/home zones
                        if (ypos == 0 && xpos < 15) {
                            xpos++;
                            dist--;
                        } else if (xpos == 15 && ypos < 15) {
                            //check for YELLOW safe zone here
                            if (xpos == 15 && ypos == 2) {
                                xpos--;
                                inSafe = 1;
                            }
                            else {
                                ypos++;
                            }
                            dist--;
                        } else if (ypos == 15 && xpos > 0) {
                            xpos--;
                            dist--;
                        } else if (xpos == 0 && ypos > 0) {
                            ypos--;
                            dist--;
                        }
                    } else if ((b.yellow[pieceNum]->getSafe() && !(b.yellow[pieceNum]->getHome())) || inSafe) { // check if pawn is in Safe zone
                        xpos--;   // ypos = 2 always when pawn->isSafe = true
                        dist--;
                    }
                }
            } else if (dist < 0) { // backwards movement
                while (dist < 0) {
                    if ((!b.yellow[pieceNum]->getSafe() && !b.yellow[pieceNum]->getHome()) || outSafe) {// check if pawn is in safe/home zones
                        if (ypos == 0 && xpos <= 15) {
                            xpos--;
                            dist++;
                        } else if (xpos == 15 && ypos <= 15) {
                            ypos--;
                            dist++;
                        } else if (ypos == 15 && xpos >= 0) {
                            xpos++;
                            dist++;
                        } else if (xpos == 0 && ypos >= 0) {
                            ypos++;
                            dist++;
                        }
                    } else if (b.yellow[pieceNum]->getSafe() && !b.yellow[pieceNum]->getHome() && !outSafe) { // checks if pawn is in Safe zone
                        xpos++;
                        dist++;
                        // checks if backwards movement puts pawn out of safe zone
                        if (xpos == 15 && ypos == 2) {
                            outSafe = 1;
                        }
                    }
                }
            }

            if (xpos < 6 && ypos == 2 && xpos != 0) {
                return false;
            } else if (b.Board[ypos][xpos] == nullptr) {
                return true;
            } else if (b.Board[ypos][xpos]->getColor() != "Yellow") {
                return true;
            } else {
                return false;
            }
        }
    }
    else { // Player 3
        if (b.green[pieceNum]->getHome()) {
            std::cout << "Cannot move. Piece selected is in Home Zone" << std::endl;
            return false;
        } else if (b.green[pieceNum]->getStart()) {
            std::cout << "Cannot move. Piece selected is in Start Zone" << std::endl;
            return false;
        } else {
            xpos = b.green[pieceNum]->getXPos();
            ypos = b.green[pieceNum]->getYPos();
            if (dist > 0) { // forward movement check
                while (dist > 0) {
                    if (!b.green[pieceNum]->getSafe() && !b.green[pieceNum]->getHome() && !inSafe) {// check if pawn is in safe/home zones
                        if (ypos == 0 && xpos < 15) {
                            xpos++;
                            dist--;
                        } else if (xpos == 15 && ypos < 15) {
                            ypos++;
                            dist--;
                        } else if (ypos == 15 && xpos > 0) {
                            //check for GREEN safe zone here
                            if (xpos == 13 && ypos == 15) {
                                ypos--;
                                inSafe = 1;
                            }
                            else {
                                xpos--;
                            }
                            dist--;
                        } else if (xpos == 0 && ypos > 0) {
                            ypos--;
                            dist--;
                        }
                    } else if ((b.green[pieceNum]->getSafe() && !(b.green[pieceNum]->getHome())) || inSafe) { // check if pawn is in Safe zone
                        ypos--;   // xpos = 13 always when pawn->isSafe = true
                        dist--;
                    }
                }
            } else if (dist < 0) { // backwards movement
                while (dist < 0) {
                    if ((!b.green[pieceNum]->getSafe() && !b.green[pieceNum]->getHome()) || outSafe) {// check if pawn is in safe/home zones
                        if (ypos == 0 && xpos <= 15) {
                            xpos--;
                            dist++;
                        } else if (xpos == 15 && ypos <= 15) {
                            ypos--;
                            dist++;
                        } else if (ypos == 15 && xpos >= 0) {
                            xpos++;
                            dist++;
                        } else if (xpos == 0 && ypos >= 0) {
                            ypos++;
                            dist++;
                        }
                    } else if (b.green[pieceNum]->getSafe() && !b.green[pieceNum]->getHome() && !outSafe) { // checks if pawn is in Safe zone
                        ypos++;
                        dist++;
                        // checks if backwards movement puts pawn out of safe zone
                        if (xpos == 13 && ypos == 15) {
                            outSafe = 1;
                        }
                    }
                }
            }
            if (xpos == 13 && ypos < 6 && ypos != 0) {
                return false;
            } else if (b.Board[ypos][xpos] == nullptr) {
                return true;
            } else if (b.Board[ypos][xpos]->getColor() != "Yellow") {
                return true;
            } else {
                return false;
            }
        }
    }
}

bool Card_Rules::Check_For_Valid_Swap(int playerNum, int swapNum, int pieceNum, int swapPiece, Sorry_Board &b) {
    // CHECKS FOR VALID DESIRED SWAP MOVEMENT BEFORE SWAPPING PAWNS

    if(playerNum == 0) {
        if(swapNum == 1) {
            if(!b.red[pieceNum]->onBoard() || !b.blue[swapPiece]->onBoard()) {
                std::cout << "One of the attempted swap pieces are not in play" << std::endl;
                return false;
            }
            else {
                return true;
            }
        }
        else if(swapNum == 2) {
            if(!b.red[pieceNum]->onBoard() || !b.yellow[swapPiece]->onBoard()) {
                std::cout << "One of the attempted swap pieces are not in play" << std::endl;
                return false;
            }
            else {
                return true;
            }
        }
        else if(swapNum == 3) {
            if(!b.red[pieceNum]->onBoard() || !b.green[swapPiece]->onBoard()) {
                std::cout << "One of the attempted swap pieces are not in play" << std::endl;
                return false;
            }
            else {
                return true;
            }
        }
        else {
            std::cout << "Invalid swap number selected" << std::endl;
            return false;
        }
    }
    else if(playerNum == 1) {
        if(swapNum == 0) {
            if(!b.blue[pieceNum]->onBoard() || !b.red[swapPiece]->onBoard()) {
                std::cout << "One of the attempted swap pieces are not in play" << std::endl;
                return false;
            }
            else {
                return true;
            }
        }
        else if(swapNum == 2) {
            if(!b.blue[pieceNum]->onBoard() || !b.yellow[swapPiece]->onBoard()) {
                std::cout << "One of the attempted swap pieces are not in play" << std::endl;
                return false;
            }
            else {
                return true;
            }
        }
        else if(swapNum == 3) {
            if(!b.blue[pieceNum]->onBoard() || !b.green[swapPiece]->onBoard()) {
                std::cout << "One of the attempted swap pieces are not in play" << std::endl;
                return false;
            }
            else {
                return true;
            }
        }
        else {
            std::cout << "Invalid swap number selected" << std::endl;
            return false;
        }
    }
    else if(playerNum == 2) {
        if(swapNum == 0) {
            if(!b.yellow[pieceNum]->onBoard() || !b.red[swapPiece]->onBoard()) {
                std::cout << "One of the attempted swap pieces are not in play" << std::endl;
                return false;
            }
            else {
                return true;
            }
        }
        else if(swapNum == 1) {
            if(!b.yellow[pieceNum]->onBoard() || !b.blue[swapPiece]->onBoard()) {
                std::cout << "One of the attempted swap pieces are not in play" << std::endl;
                return false;
            }
            else {
                return true;
            }
        }
        else if(swapNum == 3) {
            if(!b.yellow[pieceNum]->onBoard() || !b.green[swapPiece]->onBoard()) {
                std::cout << "One of the attempted swap pieces are not in play" << std::endl;
                return false;
            }
            else {
                return true;
            }
        }
        else {
            std::cout << "Invalid swap number selected" << std::endl;
            return false;
        }
    }
    else if(playerNum == 3) {
        if(swapNum == 0) {
            if(!b.green[pieceNum]->onBoard() || !b.red[swapPiece]->onBoard()) {
                std::cout << "One of the attempted swap pieces are not in play" << std::endl;
                return false;
            }
            else {
                return true;
            }
        }
        else if(swapNum == 1) {
            if(!b.green[pieceNum]->onBoard() || !b.blue[swapPiece]->onBoard()) {
                std::cout << "One of the attempted swap pieces are not in play" << std::endl;
                return false;
            }
            else {
                return true;
            }
        }
        else if(swapNum == 2) {
            if(!b.green[pieceNum]->onBoard() || !b.yellow[swapPiece]->onBoard()) {
                std::cout << "One of the attempted swap pieces are not in play" << std::endl;
                return false;
            }
            else {
                return true;
            }
        }
        else {
            std::cout << "Invalid swap number selected" << std::endl;
            return false;
        }
    }
    else {
        std::cout << "Invalid player number selected" << std::endl;
        return false;
    }
}

bool Card_Rules::Check_For_Valid_Sorry(int playerNum, int swapNum, int pieceNum, int swapPiece, Sorry_Board &b) {
    // CHECKS FOR VALID SORRY! SWAP MOVEMENT BEFORE MAKING THE SORRY! ACTION

    if (playerNum == 0) {
        if (swapNum == 1) {
            if (!b.red[pieceNum]->getStart() || !b.blue[swapPiece]->onBoard()) {
                std::cout << "Invalid choice of pawns" << std::endl;
                return false;
            } else {
                return true;
            }
        } else if (swapNum == 2) {
            if (!b.red[pieceNum]->getStart() || !b.yellow[swapPiece]->onBoard()) {
                std::cout << "Invalid choice of pawns" << std::endl;
                return false;
            } else {
                return true;
            }
        } else if (swapNum == 3) {
            if (!b.red[pieceNum]->getStart() || !b.green[swapPiece]->onBoard()) {
                std::cout << "Invalid choice of pawns" << std::endl;
                return false;
            } else {
                return true;
            }
        } else {
            std::cout << "Invalid swap number selected" << std::endl;
            return false;
        }
    } else if (playerNum == 1) {
        if (swapNum == 0) {
            if (!b.blue[pieceNum]->getStart() || !b.red[swapPiece]->onBoard()) {
                std::cout << "Invalid choice of pawns" << std::endl;
                return false;
            } else {
                return true;
            }
        } else if (swapNum == 2) {
            if (!b.blue[pieceNum]->getStart() || !b.yellow[swapPiece]->onBoard()) {
                std::cout << "Invalid choice of pawns" << std::endl;
                return false;
            } else {
                return true;
            }
        } else if (swapNum == 3) {
            if (!b.blue[pieceNum]->getStart() || !b.green[swapPiece]->onBoard()) {
                std::cout << "Invalid choice of pawns" << std::endl;
                return false;
            } else {
                return true;
            }
        } else {
            std::cout << "Invalid swap number selected" << std::endl;
            return false;
        }
    } else if (playerNum == 2) {
        if (swapNum == 0) {
            if (!b.yellow[pieceNum]->getStart() || !b.red[swapPiece]->onBoard()) {
                std::cout << "Invalid choice of pawns" << std::endl;
                return false;
            } else {
                return true;
            }
        } else if (swapNum == 1) {
            if (!b.yellow[pieceNum]->getStart() || !b.blue[swapPiece]->onBoard()) {
                std::cout << "Invalid choice of pawns" << std::endl;
                return false;
            } else {
                return true;
            }
        } else if (swapNum == 3) {
            if (!b.yellow[pieceNum]->getStart() || !b.green[swapPiece]->onBoard()) {
                std::cout << "Invalid choice of pawns" << std::endl;
                return false;
            } else {
                return true;
            }
        } else {
            std::cout << "Invalid swap number selected" << std::endl;
            return false;
        }
    } else if (playerNum == 3) {
        if (swapNum == 0) {
            if (!b.green[pieceNum]->getStart() || !b.red[swapPiece]->onBoard()) {
                std::cout << "Invalid choice of pawns" << std::endl;
                return false;
            } else {
                return true;
            }
        } else if (swapNum == 1) {
            if (!b.green[pieceNum]->getStart() || !b.blue[swapPiece]->onBoard()) {
                std::cout << "Invalid choice of pawns" << std::endl;
                return false;
            } else {
                return true;
            }
        } else if (swapNum == 2) {
            if (!b.green[pieceNum]->getStart() || !b.yellow[swapPiece]->onBoard()) {
                std::cout << "Invalid choice of pawns" << std::endl;
                return false;
            } else {
                return true;
            }
        } else {
            std::cout << "Invalid swap number selected" << std::endl;
            return false;
        }
    } else {
        std::cout << "Invalid player number selected" << std::endl;
        return false;
    }
}

int Card_Rules::Distance_From_Home(Sorry_Pawn *pawn) {
    int x = pawn->getXPos();
    int y = pawn->getYPos();
    if (pawn->getStart()) return 66;
    if (pawn->getHome()) return 0;
    if (pawn->getSafe()) {
        if (pawn->getColor() == RED)
            return 6 - x;
        else if (pawn->getColor() == BLUE)
            return 6 - y;
        else if (pawn->getColor() == YELLOW)
            return x - 9;
        else if (pawn->getColor() == GREEN)
            return y - 9;
    }
    if (pawn->getColor() == RED) {
        if (x == 0) {
            if (y > 12) {
                return (y - 13) + 6;
            } else {
                return y + 53;
            }
        } else if (y == 0) {
            return (15 - x) + 38;
        } else if (x == 15) {
            return (15 - y) + 23;
        } else if (y == 15) {
            return x + 8;
        }
    } else if (pawn->getColor() == BLUE) {
        if (x == 0) {
            return x + 8;
        } else if (y == 0) {
            if (x < 3) {
                return (2 - x) + 6;
            } else {
                return (15 - x) + 53;
            }
        } else if (x == 15) {
            return (15 - y) + 38;
        } else if (y == 15) {
            return x + 23;
        }
    } else if (pawn->getColor() == YELLOW) {
        if (x == 0) {
            return y + 23;
        } else if (y == 0) {
            return (15 - x) + 8;
        } else if (x == 15) {
            if (y < 3) {
                return (2 - y) + 6;
            } else {
                return (15 - y) + 53;
            }
        } else if (y == 15) {
            return x + 38;
        }
    } else if (pawn->getColor() == GREEN) {
        if (x == 0) {
            return y + 38;
        } else if (y == 0) {
            return (15 - x) + 23;
        } else if (x == 15) {
            return (15 - x) + 8;
        } else if (y == 15) {
            if (x > 12) {
                return (15 - x) + 6;
            } else {
                return x + 53;
            }
        }
    }
    return 0;
}

int Card_Rules::Closest_To_Home(int playerNum, Sorry_Board &b) {
    int dist = 100;
    int closest;
    for (int i = 0; i < 4; i++) {
        if (playerNum == 0) {
            if (Distance_From_Home(b.red[i]) < dist) {
                closest = i;
                dist = Distance_From_Home(b.red[i]);
            }
        } else if (playerNum == 1) {
            if (Distance_From_Home(b.blue[i]) < dist) {
                closest = i;
                dist = Distance_From_Home(b.blue[i]);
            }
        } else if (playerNum == 2) {
            if (Distance_From_Home(b.yellow[i]) < dist) {
                closest = i;
                dist = Distance_From_Home(b.yellow[i]);
            }
        } else if (playerNum == 3) {
            if (Distance_From_Home(b.green[i]) < dist) {
                closest = i;
                dist = Distance_From_Home(b.green[i]);
            }
        }
    }
    return closest;
}

bool Card_Rules::All_Pawns_At_Start(int playerNum, Sorry_Board &b) {
    if (playerNum == 0) {
        if (b.red[0]->getStart() && b.red[1]->getStart() && b.red[2]->getStart() && b.red[3]->getStart())
            return true;
    } else if (playerNum == 1) {
        if (b.blue[0]->getStart() && b.blue[1]->getStart() && b.blue[2]->getStart() && b.blue[3]->getStart())
            return true;
    } else if (playerNum == 2) {
        if (b.yellow[0]->getStart() && b.yellow[1]->getStart() && b.yellow[2]->getStart() && b.yellow[3]->getStart())
            return true;
    } else if (playerNum == 3) {
        if (b.green[0]->getStart() && b.green[1]->getStart() && b.green[2]->getStart() && b.green[3]->getStart())
            return true;
    }
    return false;
}

