//
// Created by Illia Abdullaiev on 4/16/18.
//

// This is handleSmithy unit test

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "test_utils.h"


int main() {
    printf("Testing handleSmithy function...\n");

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


    printf("TEST 1: Current player should receive extra three cards:");
    handleSmithy(currentPlayer, &currentGameState, 0);
    int newCards = 3;
    int discardCards = 1;
    if (currentGameState.handCount[currentPlayer] == (savedGameState.handCount[currentPlayer] + newCards - discardCards)) {
        success();
    } else {
        printf("\nExpected # of cards in hands: %d\n", savedGameState.handCount[currentPlayer] + 3);
        printf("Actual # of cards in hands: %d.", currentGameState.handCount[currentPlayer]);
        failure();
    }


    printf("TEST 2: Current player's deck should decrease by three cards:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    handleSmithy(currentPlayer, &currentGameState, 0);
    if (currentGameState.deckCount[currentPlayer] == (savedGameState.deckCount[currentPlayer] - 3)) {
        success();
    } else {
        failure();
    }

    printf("TEST 3: Current player's discard pile should decrease by 1:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    currentGameState.discardCount[currentPlayer] = 1;
    handleSmithy(currentPlayer, &currentGameState, 0);
    int actual = currentGameState.discardCount[currentPlayer];
    int expected = 0;
    if (actual == expected) {
        success();
    } else {
        printf("\nExpected # of cards in discard pile: %d\n", expected);
        printf("Actual # of cards in discard pile: %d.", actual);
        failure();
    }


    printf("TEST 3: Other player's state has not changed:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    handleSmithy(currentPlayer, &currentGameState, 0);
    otherPlayerNotChanged(&currentGameState, &savedGameState);


    printf("TEST 4: No state change occurred to the victory card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    handleSmithy(currentPlayer, &currentGameState, 0);
    victoryCardsNotChanged(&currentGameState, &savedGameState);


    printf("TEST 5: No state change occurred to the kingdom card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    handleSmithy(currentPlayer, &currentGameState, 0);
    kingdomCardsNotChanged(&currentGameState, &savedGameState, kingdomCards);

    return 0;
}