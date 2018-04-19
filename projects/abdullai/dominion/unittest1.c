//
// Created by Illia Abdullaiev on 4/16/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "test_utils.h"


int main() {
    printf("=============== Testing handCard Function ================\n");

    int kingdomCards[10] = {
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
    int seed = 1000;
    int currentPlayer = 0;
    int temphand[MAX_HAND];
    struct gameState currentGameState, savedGameState;

    initializeGame(2, kingdomCards, seed, &currentGameState);
    memcpy(&savedGameState, &currentGameState, sizeof(struct gameState));


    printf("TEST 1: It should return the card by given position:");
    currentGameState.hand[currentPlayer][0] = smithy;
    currentGameState.whoseTurn = currentPlayer;
    if (handCard(0, &currentGameState) == smithy) {
        success();
    } else {
        failure();
    }

    printf("TEST 2: It should not cause side effects such as change to the victory card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    handCard(0, &currentGameState);
    victoryCardsNotChanged(&currentGameState, &savedGameState);


    printf("TEST 3: It should not cause side effects such as change to the kingdom card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    handCard(0, &currentGameState);
    kingdomCardsNotChanged(&currentGameState, &savedGameState, kingdomCards);

    return 0;
}