//
// Created by Illia Abdullaiev on 4/16/18.
//

// This is handleAdventurerCard unit test

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "test_utils.h"


int main() {
    printf("Testing handleAdventurerCard function...\n");

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
    int topCard, secondTopCard;
    struct gameState currentGameState, savedGameState;

    initializeGame(2, kingdomCards, seed, &currentGameState);
    memcpy(&savedGameState, &currentGameState, sizeof(struct gameState));


    printf("TEST 1: Current player's has two new cards in hands:");
    handleAdventurerCard(currentPlayer, &currentGameState, temphand);
    int newCards = 2;
    int discardCards = 1;
    int expected = savedGameState.deckCount[currentPlayer] + newCards - discardCards;
    int actual = currentGameState.handCount[currentPlayer];
    if (actual == expected) {
        success();
    } else {
        printf("\nExpected number of cards in hands: %d\n", expected);
        printf("Actual number of cards in hands: %d.", actual);
        failure();
    }


    printf("TEST 2: Two new cards are of treasure type:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    handleAdventurerCard(currentPlayer, &currentGameState, temphand);
    topCard = currentGameState.hand[currentPlayer][currentGameState.handCount[currentPlayer] - 1];
    secondTopCard = currentGameState.hand[currentPlayer][currentGameState.handCount[currentPlayer] - 2];
    if ((topCard == copper || topCard == silver || topCard == gold) && (secondTopCard == copper || secondTopCard == silver || secondTopCard == gold)) {
        success();
    } else {
        failure();
    }


    printf("TEST 3: Current player's deck has changed:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    handleAdventurerCard(currentPlayer, &currentGameState, temphand);
    if (currentGameState.deckCount[currentPlayer] != savedGameState.deckCount[currentPlayer]) {
        success();
    } else {
        failure();
    }

    printf("TEST 4: Other player's state has not changed:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    handleAdventurerCard(currentPlayer, &currentGameState, temphand);
    otherPlayerNotChanged(&currentGameState, &savedGameState);

    printf("TEST 5: No state change occurred to the victory card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    handleAdventurerCard(currentPlayer, &currentGameState, temphand);
    victoryCardsNotChanged(&currentGameState, &savedGameState);


    printf("TEST 6: No state change occurred to the kingdom card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    handleAdventurerCard(currentPlayer, &currentGameState, temphand);
    kingdomCardsNotChanged(&currentGameState, &savedGameState, kingdomCards);


    return 0;
}