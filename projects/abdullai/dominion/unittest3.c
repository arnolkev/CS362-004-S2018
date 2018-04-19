//
// Created by Illia Abdullaiev on 4/16/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "test_utils.h"


int main() {
    printf("=============== Testing updateCoins Function ================\n");

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


    printf("TEST 1: It should not add new coins if the player does not have treasure cards in hands");
    currentGameState.hand[currentPlayer][0] = village;
    currentGameState.hand[currentPlayer][1] = minion;
    currentGameState.hand[currentPlayer][2] = mine;
    currentGameState.handCount[currentPlayer] = 3;
    updateCoins(currentPlayer, &currentGameState, 0);
    if (currentGameState.coins == 0) {
        success();
    } else {
        failure();
    }

    printf("TEST 2: It should handle all three kinds of treasury cards");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    currentGameState.hand[currentPlayer][0] = copper;
    currentGameState.hand[currentPlayer][1] = silver;
    currentGameState.hand[currentPlayer][2] = gold;
    currentGameState.handCount[currentPlayer] = 3;
    updateCoins(currentPlayer, &currentGameState, 0);
    if (currentGameState.coins == 6) {
        success();
    } else {
        failure();
    }

    printf("TEST 3: It should add given bonus on top of treasure cards");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    currentGameState.hand[currentPlayer][0] = copper;
    currentGameState.hand[currentPlayer][1] = silver;
    currentGameState.hand[currentPlayer][2] = gold;
    currentGameState.handCount[currentPlayer] = 3;
    updateCoins(currentPlayer, &currentGameState, 2);
    if (currentGameState.coins == 8) {
        success();
    } else {
        failure();
    }


    printf("TEST 5: It should not cause side effects such as change to the victory card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    updateCoins(currentPlayer, &currentGameState, 2);
    victoryCardsNotChanged(&currentGameState, &savedGameState);


    printf("TEST 6: It should not cause side effects such as change to the kingdom card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    updateCoins(currentPlayer, &currentGameState, 2);
    kingdomCardsNotChanged(&currentGameState, &savedGameState, kingdomCards);


    return 0;
}