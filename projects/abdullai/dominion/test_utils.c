//
// Created by Illia Abdullaiev on 4/17/18->
//

#include "test_utils.h"
#include <stdio.h>

void success() {
    printf(" SUCCESS\n");
}

void failure() {
    printf(" FAILURE\n");
}

void otherPlayerNotChanged(struct gameState *currentGameState, struct gameState *savedGameState) {
    if (currentGameState->deckCount[1] == savedGameState->deckCount[1] &&
        currentGameState->discardCount[1] == savedGameState->discardCount[1] &&
        currentGameState->handCount[1] == savedGameState->handCount[1]) {
        success();
    } else {
        failure();
    }
}

void victoryCardsNotChanged(struct gameState *currentGameState, struct gameState *savedGameState) {
    if (currentGameState->supplyCount[estate] == savedGameState->supplyCount[estate] &&
        currentGameState->supplyCount[duchy] == savedGameState->supplyCount[duchy] &&
        currentGameState->supplyCount[province] == savedGameState->supplyCount[province]) {
        success();
    } else {
        failure();
    }
}

void kingdomCardsNotChanged(struct gameState *currentGameState, struct gameState *savedGameState, int kingdomCards[10]) {
    int successful = 1;
    for (int i = 0; i < 10; i++) {
        if (currentGameState->supplyCount[kingdomCards[i]] != savedGameState->supplyCount[kingdomCards[i]]) {
            successful = 0;
            break;
        }
    };
    if (successful == 1) {
        success();
    } else {
        failure();
    }
}
