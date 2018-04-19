//
// Created by Illia Abdullaiev on 4/16/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "test_utils.h"


int main() {
    printf("======================= Testing Smithy Card ===================\n");

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
    int bonus = 0;
    int currentPlayer = 0;
    struct gameState currentGameState, savedGameState;

    initializeGame(2, kingdomCards, seed, &currentGameState);
    memcpy(&savedGameState, &currentGameState, sizeof(struct gameState));


    printf("TEST 1: Current player should receive extra three cards:");
    cardEffect(smithy, 0, 0, 0, &currentGameState, 0, &bonus);
    int newCards = 3;
    int discardCards = 1;
    int expected = savedGameState.handCount[currentPlayer] + newCards - discardCards;
    int actual = currentGameState.handCount[currentPlayer];
    if (expected == actual) {
        success();
    } else {
        printf("\nExpected # of cards in hands: %d\n", expected);
        printf("Actual # of cards in hands: %d.", actual);
        failure();
    }


    printf("TEST 2: Current player's deck should decrease by three cards:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    cardEffect(smithy, 0, 0, 0, &currentGameState, 0, &bonus);
    if (currentGameState.deckCount[currentPlayer] == (savedGameState.deckCount[currentPlayer] - 3)) {
        success();
    } else {
        failure();
    }

    printf("TEST 3: Other player's state has not changed:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    cardEffect(smithy, 0, 0, 0, &currentGameState, 0, &bonus);
    otherPlayerNotChanged(&currentGameState, &savedGameState);


    printf("TEST 4: No state change occurred to the victory card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    cardEffect(smithy, 0, 0, 0, &currentGameState, 0, &bonus);
    victoryCardsNotChanged(&currentGameState, &savedGameState);


    printf("TEST 5: No state change occurred to the kingdom card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    cardEffect(smithy, 0, 0, 0, &currentGameState, 0, &bonus);
    kingdomCardsNotChanged(&currentGameState, &savedGameState, kingdomCards);

    return 0;
}