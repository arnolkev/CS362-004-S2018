//
// Created by Illia Abdullaiev on 4/17/18.
//

#ifndef CS362_004_S2018_TEST_UTILS_H
#define CS362_004_S2018_TEST_UTILS_H

#include "../../bessermbDominion/dominion/dominion.h"

// Print either success or failure to unit tests stdout.
void success();
void failure();

// Check that playing a card does not produce side effects.
int otherPlayerNotChanged(struct gameState *currentGameState, struct gameState *savedGameState, int NOISY);
int victoryCardsNotChanged(struct gameState *currentGameState, struct gameState *savedGameState, int NOISY);
int kingdomCardsNotChanged(struct gameState *currentGameState, struct gameState *savedGameState, int kingdomCards[10], int NOISY);
int generateRandomNumber(int min, int max);
int * getRandomKingdomCards();

#endif //CS362_004_S2018_TEST_UTILS_H
