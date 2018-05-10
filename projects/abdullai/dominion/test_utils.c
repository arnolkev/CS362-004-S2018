//
// Created by Illia Abdullaiev on 4/17/18->
//

#include "test_utils.h"
#include <stdio.h>

void success() {
    printf(" TEST SUCCESSFULLY COMPLETED\n\n");
}

void failure() {
    printf(" TEST FAILED\n\n");
}

int otherPlayerNotChanged(struct gameState *currentGameState, struct gameState *savedGameState, int NOISY) {
    if (currentGameState->deckCount[1] == savedGameState->deckCount[1] &&
        currentGameState->discardCount[1] == savedGameState->discardCount[1] &&
        currentGameState->handCount[1] == savedGameState->handCount[1]) {
        if (NOISY == 1) {
            success();
        }
        return 1;
    } else {
        failure();
        return 2;
    }
}

int victoryCardsNotChanged(struct gameState *currentGameState, struct gameState *savedGameState, int NOISY) {
    if (currentGameState->supplyCount[estate] == savedGameState->supplyCount[estate] &&
        currentGameState->supplyCount[duchy] == savedGameState->supplyCount[duchy] &&
        currentGameState->supplyCount[province] == savedGameState->supplyCount[province]) {
        if (NOISY == 1) {
            success();
        }
        return 1;
    } else {
        failure();
        return 2;
    }
}

int kingdomCardsNotChanged(struct gameState *currentGameState, struct gameState *savedGameState, int kingdomCards[10], int NOISY) {
    int successful = 1;
    for (int i = 0; i < 10; i++) {
        if (currentGameState->supplyCount[kingdomCards[i]] != savedGameState->supplyCount[kingdomCards[i]]) {
            successful = 0;
            break;
        }
    };
    if (successful == 1) {
        if (NOISY == 1) {
            success();
        }
        return 1;
    } else {
        failure();
        return 2;
    }
}

int generateRandomNumber(int min, int max) {
    return (rand() % (max + 1 - min)) + min;
}

int * getRandomKingdomCards() {
    static int cards[10];

    for (int i = 0; i < 10; i++) {
        int unique = 0;
        while (unique == 0) {
            int foundDuplicate = 0;
            //treasure cards start with index 7 and end at 26
            int card = generateRandomNumber(7, 26);

            for (int j = 0; j <= i; j++) {
                if (cards[j] == card) {
                    foundDuplicate = 1;
                    break;
                }
            }

            //the card is unique if there are no duplicates, add it the array of cards
            if (foundDuplicate == 0) {
                unique = 1;
                cards[i] = card;
            }
        }
    }

    return cards;
}
