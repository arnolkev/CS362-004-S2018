//
// Created by Illia Abdullaiev on 4/16/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "test_utils.h"


int main() {
    printf("=============== Testing isGameOver Function ================\n");

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
    struct gameState currentGameState, savedGameState;

    initializeGame(2, kingdomCards, seed, &currentGameState);
    memcpy(&savedGameState, &currentGameState, sizeof(struct gameState));


    printf("TEST 1: It should return true if province pile is empty:");
    currentGameState.supplyCount[province] = 0;
    if (isGameOver(&currentGameState) == 1) {
        success();
    } else {
        failure();
    }

    printf("TEST 2: It should return false if there is at least one province card left (and supply piles are full):");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    currentGameState.supplyCount[province] = 1;
    if (isGameOver(&currentGameState) == 0) {
        success();
    } else {
        failure();
    }

    printf("TEST 3: It should return true if at least three supply piles are empty");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    currentGameState.supplyCount[smithy] = 0;
    currentGameState.supplyCount[gold] = 0;
    currentGameState.supplyCount[tribute] = 0;
    if (isGameOver(&currentGameState) == 1) {
        success();
    } else {
        failure();
    }

    printf("TEST 4: It should return false if only two supply piles are empty");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    currentGameState.supplyCount[smithy] = 0;
    currentGameState.supplyCount[gold] = 0;
    if (isGameOver(&currentGameState) == 0) {
        success();
    } else {
        failure();
    }

    printf("TEST 5: It should not cause side effects such as change to the victory card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    isGameOver(&currentGameState);
    victoryCardsNotChanged(&currentGameState, &savedGameState);


    printf("TEST 6: It should not cause side effects such as change to the kingdom card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    isGameOver(&currentGameState);
    kingdomCardsNotChanged(&currentGameState, &savedGameState, kingdomCards);

    return 0;
}