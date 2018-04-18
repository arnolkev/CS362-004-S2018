//
// Created by Illia Abdullaiev on 4/17/18.
//

#ifndef CS362_004_S2018_TEST_UTILS_H
#define CS362_004_S2018_TEST_UTILS_H

#include "dominion.h"

// Print either success or failure to unit tests stdout.
void success();
void failure();

// Check that playing a card does not produce side effects.
void otherPlayerNotChanged(struct gameState *currentGameState, struct gameState *savedGameState);
void victoryCardsNotChanged(struct gameState *currentGameState, struct gameState *savedGameState);
void kingdomCardsNotChanged(struct gameState *currentGameState, struct gameState *savedGameState, int kingdomCards[10]);

#endif //CS362_004_S2018_TEST_UTILS_H
