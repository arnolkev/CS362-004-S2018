//
// Created by Illia Abdullaiev on 4/16/18.
//

// This is handleVillage unit test

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "test_utils.h"


int main() {
    printf("Testing handleVillage function...\n");

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
    struct gameState currentGameState, savedGameState;

    initializeGame(2, kingdomCards, seed, &currentGameState);
    memcpy(&savedGameState, &currentGameState, sizeof(struct gameState));


    printf("TEST 1: Current player should receive one extra card:");
    handleVillage(currentPlayer, &currentGameState, 0);
    int newCards = 1;
    int discardCards = 1;
    int expected1 = savedGameState.handCount[currentPlayer] + newCards - discardCards;
    int actual1 = currentGameState.handCount[currentPlayer];
    if (expected1 == actual1) {
        success();
    } else {
        printf("\nExpected # of cards in hands: %d\n", expected1);
        printf("Actual # of cards in hands: %d.", actual1);
        failure();
    }


    printf("TEST 2: Current player should receive two more actions:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    handleVillage(currentPlayer, &currentGameState, 0);
    int newActions = 2;
    int expected2 = savedGameState.numActions + newActions;
    int actual2 = currentGameState.numActions;
    if (expected2 == actual2) {
        success();
    } else {
        printf("\nExpected # of current actions: %d\n", expected2);
        printf("Actual # of current actions: %d.", actual2);
        failure();
    }

    printf("TEST 3: Other player's state has not changed:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    handleVillage(currentPlayer, &currentGameState, 0);
    otherPlayerNotChanged(&currentGameState, &savedGameState);


    printf("TEST 4: No state change occurred to the victory card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    handleVillage(currentPlayer, &currentGameState, 0);
    victoryCardsNotChanged(&currentGameState, &savedGameState);


    printf("TEST 5: No state change occurred to the kingdom card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    handleVillage(currentPlayer, &currentGameState, 0);
    kingdomCardsNotChanged(&currentGameState, &savedGameState, kingdomCards);


    return 0;
}