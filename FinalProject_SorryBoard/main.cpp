//
// File Contains the main function for Sorry!
//
// The main function will begin a finite state machine for the Sorry! game.
//
// States - 0. Initialize Objects and Choose Players.
//          1. Start game / Draw Card. Goto State 2.
//          2. Let Player decide move or Choose best move for computer. Goto State 3.
//          3. Check for winner if winner goto State 4. If not update next player and move to State 1.
//          4. Winner! Display game results. Ask for new game goto State 0 or exit.
//
//=====================================================================================================

#include <iostream>
#include "Sorry_Deck.h"
#include "Sorry_Board.h"
#include "Computer_Player.h"
#include "Console_Player.h"
#include "Card_Rules.h"

using namespace std;

#define TOTAL_PLAYERS   4

// FSM States
#define RESET_GAME      0
#define NEW_TURN        1
#define MAKE_MOVE       2
#define CHECK_FOR_WIN   3
#define WINNER_FOUND    4

bool Ask_If_Human(int i);
bool Ask_To_Restart();
void Reset_Board(Sorry_Board &b);

int main() {
    //Create Objects and Variables
    bool gameOver = false;
    int gameState = RESET_GAME;
    int currentCard;
    int currentPlayer;
    Sorry_Deck deck;
    Sorry_Board board;
    Card_Rules rules;
    Sorry_Player *players[TOTAL_PLAYERS];

    // Game State Machine
    while (!gameOver) {
        switch (gameState) {
            // Initialize
            case RESET_GAME :
                currentPlayer = 0;
                deck.Shuffle_Deck();
                for (int i = 0; i < TOTAL_PLAYERS; i++) {
                    if (Ask_If_Human(i)) {
                        auto *tmp = new Console_Player(i);
                        players[i] = tmp;
                    } else {
                        auto *tmp = new Computer_Player(i);
                        players[i] = tmp;
                    }
                }
                gameState = NEW_TURN;
                break;
            // Start/New Turn
            case NEW_TURN :
                board.Show_Board();
                cout << "It is now " << players[currentPlayer]->getColor() << "'s Turn to Play. Card Drawn..." << endl;
                currentCard = deck.Draw_Card();
                deck.Card_Text(currentCard);
                gameState = MAKE_MOVE;
                break;
            // Decide Game Play
            case MAKE_MOVE :
                if (players[currentPlayer]->getIsHuman()) {
                    rules.Ask_Player_For_Move(currentPlayer, currentCard, board);
                } else {
                    rules.Ask_Computer_For_Move(currentPlayer, currentCard, board);
                }
                gameState = CHECK_FOR_WIN;
                break;
            // Check for Winner
            case CHECK_FOR_WIN :
                if (rules.Check_Win(currentPlayer, board)) {
                    gameState = WINNER_FOUND;
                } else {
                    // If a 2 card was picked, player gets another turn.
                    if (currentCard == 2) {
                        cout << players[currentPlayer]->getColor() << " gets another turn." << endl;
                    } else {
                        currentPlayer++;
                        if (currentPlayer >= TOTAL_PLAYERS)
                            currentPlayer = 0;
                    }
                    gameState = NEW_TURN;
                }
                break;
            // Winner
            case WINNER_FOUND :
                //Display winner and ask to exit or restart game.
                cout << endl << "********" << players[currentPlayer]->getColor() << " wins the game! ********" << endl;
                if (Ask_To_Restart()) {
                    Reset_Board(board);
                    gameState = RESET_GAME;
                } else {
                    gameOver = true;
                }
                break;
            default : break;
        }
    }
    // FSM Stopped Exit Program
    return 0;
}

bool Ask_If_Human(int i) {
    string tmpStr;
    char choice;
    switch (i) {
        case 0 : tmpStr = RED; break;
        case 1 : tmpStr = BLUE; break;
        case 2 : tmpStr = YELLOW; break;
        case 3 : tmpStr = GREEN; break;
        default: break;
    }
    do {
        cout << "Is Player #" << i + 1 << " (" << tmpStr << ") A Human Player? (Y-N)" << endl;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            return true;
        } else if (choice == 'N' || choice == 'n') {
            return false;
        } else {
            cout << "Invalid Choice." << endl;
        }
    } while (true);
}

bool Ask_To_Restart() {
    char decision;
    do {
        cout << "Would you like to Start a New Game? (Y-N)." << endl;
        cin >> decision;
        if (decision == 'Y' || decision == 'y') {
            return true;
        } else if (decision == 'N' || decision =='n') {
            return false;
        } else {
            cout << "Invalid Input." << endl;
        }
    } while (true);
}

void Reset_Board(Sorry_Board &b) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            b.Board[i][j] = nullptr;
    }
    for (int i = 0; i < TOTAL_PLAYERS; i++) {
        b.Send_Pawn_To_Start(*b.red[i]);
        b.Send_Pawn_To_Start(*b.blue[i]);
        b.Send_Pawn_To_Start(*b.green[i]);
        b.Send_Pawn_To_Start(*b.yellow[i]);
    }
}



