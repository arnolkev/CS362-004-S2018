//
// Created by Illia Abdullaiev on 4/16/18.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../bessermbDominion/dominion/dominion.h"
#include "test_utils.h"


int main() {
    printf("======================= Testing Steward Card ===================\n");

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
    int bonus = 0;
    struct gameState currentGameState, savedGameState;

    initializeGame(2, kingdomCards, seed, &currentGameState);
    memcpy(&savedGameState, &currentGameState, sizeof(struct gameState));


    printf("TEST 1: Choice A - current user draws two more cards:");
    cardEffect(steward, 1, 0, 0, &currentGameState, 0, &bonus);
    int newCards = 2;
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


    printf("TEST 2: Choice B - current user gains two coins:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    cardEffect(steward, 2, 0, 0, &currentGameState, 0, &bonus);
    int expected2 = savedGameState.coins + 2;
    int actual2 = currentGameState.coins;
    if (expected2 == actual2) {
        success();
    } else {
        printf("\nExpected # of coins: %d\n", expected2);
        printf("Actual # of coins: %d.", actual2);
        failure();
    }


    printf("TEST 3: Choice C - current user can trash any two cards in the hands:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    int card1Position = 1;
    int card2Position = 2;
    cardEffect(steward, 0, card1Position, card2Position, &currentGameState, 0, &bonus);
    //expect both cards to be removed from player's hands
    if (currentGameState.hand[currentPlayer][card1Position] == -1 && currentGameState.hand[currentPlayer][card2Position] == -1) {
        success();
    } else {
        failure();
    }


    printf("TEST 4: Other player's state has not changed:");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    cardEffect(steward, 1, 0, 0, &currentGameState, 0, &bonus);
    otherPlayerNotChanged(&currentGameState, &savedGameState, 1);


    printf("TEST 5: No state change occurred to the victory card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    cardEffect(steward, 1, 0, 0, &currentGameState, 0, &bonus);
    victoryCardsNotChanged(&currentGameState, &savedGameState, 1);


    printf("TEST 6: No state change occurred to the kingdom card piles");
    memcpy(&currentGameState, &savedGameState, sizeof(struct gameState));
    cardEffect(steward, 1, 0, 0, &currentGameState, 0, &bonus);
    kingdomCardsNotChanged(&currentGameState, &savedGameState, kingdomCards, 1);


    return 0;
}
