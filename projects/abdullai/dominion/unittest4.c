//
// Created by Illia Abdullaiev on 4/16/18.
//

// This is handleSteward unit test

//Rules:
//Choice is given
//Choice A: +2 cards and +2 coins
//Choice B: user can trash any two cards in the hands
//No state change should occur for other players
//No state change should occur to the victory card piles and kingdom card piles

#include "dominion.h"

#define TESTFUNC "handleSteward"

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