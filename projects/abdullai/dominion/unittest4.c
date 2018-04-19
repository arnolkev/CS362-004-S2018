//
// Created by Illia Abdullaiev on 4/16/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "test_utils.h"


int main() {
    printf("=============== Testing buyCard Function ================\n");

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


    printf("TEST 1: It should buy a card and place it into the discard pile:");
    currentGameState.whoseTurn = currentPlayer;
    currentGameState.numBuys = 1;
    currentGameState.supplyCount[village] = 1;
    currentGameState.coins = 5;
    int status = buyCard(village, &currentGameState);
    int expectedCount =  savedGameState.discardCount[currentPlayer] + 1;
    int actualCount =  currentGameState.discardCount[currentPlayer];
    if (status == 0 && expectedCount == actualCount) {
        success();
    } else {
        printf("\nPurchased card did not appear in discard pile. Expected: %d, Actual %d", expectedCount, actualCount);
        failure();
    }


    printf("TEST 2: It should not allow to purchase cards if number of available buys is less than one:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    currentGameState.whoseTurn = currentPlayer;
    currentGameState.numBuys = 0;
    currentGameState.supplyCount[village] = 1;
    currentGameState.coins = 5;
    if (buyCard(village, &currentGameState) == -1) {
        success();
    } else {
        failure();
    }


    printf("TEST 3: It should not allow to purchase a card if that card ran out of supply:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    currentGameState.whoseTurn = currentPlayer;
    currentGameState.numBuys = 1;
    currentGameState.supplyCount[village] = 0;
    currentGameState.coins = 5;
    if (buyCard(village, &currentGameState) == -1) {
        success();
    } else {
        failure();
    }


    printf("TEST 4: It should not allow to purchase a card if the user doesn't have enough coins:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    currentGameState.whoseTurn = currentPlayer;
    currentGameState.numBuys = 1;
    currentGameState.supplyCount[province] = 1;
    currentGameState.coins = 7;
    if (buyCard(province, &currentGameState) == -1) {
        success();
    } else {
        failure();
    }

    printf("TEST 5: It should decrease number of available coins:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    currentGameState.whoseTurn = currentPlayer;
    currentGameState.numBuys = 1;
    currentGameState.supplyCount[province] = 1;
    currentGameState.coins = 8;
    buyCard(province, &currentGameState);
    if (currentGameState.coins == 0) {
        success();
    } else {
        failure();
    }


    printf("TEST 6: It should decrease number of available buys:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    currentGameState.whoseTurn = currentPlayer;
    currentGameState.numBuys = 1;
    currentGameState.supplyCount[province] = 1;
    currentGameState.coins = 8;
    buyCard(province, &currentGameState);
    if (currentGameState.numBuys == 0) {
        success();
    } else {
        failure();
    }

    printf("TEST 7: It should decrease number of available cards to purchase:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    currentGameState.whoseTurn = currentPlayer;
    currentGameState.numBuys = 1;
    currentGameState.supplyCount[province] = 2;
    currentGameState.coins = 8;
    buyCard(province, &currentGameState);
    if (currentGameState.supplyCount[province] == 1) {
        success();
    } else {
        failure();
    }


    printf("TEST 8: It should not cause side effects such as change to the victory card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    currentGameState.whoseTurn = currentPlayer;
    currentGameState.numBuys = 1;
    currentGameState.supplyCount[village] = 1;
    currentGameState.coins = 5;
    buyCard(province, &currentGameState);
    victoryCardsNotChanged(&currentGameState, &savedGameState);


    return 0;
}
