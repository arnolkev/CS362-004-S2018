//
// Created by Illia Abdullaiev on 4/16/18.
//

// This is handleSmithy unit test
// Rules:

//1. Current player should receive exact 3 cards.
//2. 3 cards should come from his own pile.
//3. No state change should occur for other players.
//4. No state change should occur to the victory card piles and kingdom card piles.

#include "dominion.h"

#define TESTFUNC "handleSmithy"

int main() {
    int seed = 1000;
    int currentPlayer = 0;
    int kingdom[10] = {
            adventurer,
            smithy,
            village,
            steward,
            minion,
            mine,
            feast,
            remodel,
            tribute,
            council_room
    };
    struct gameState gameState, testGameState;
    initializeGame(2, kingdom, seed, &gameState);
    return 0;
}