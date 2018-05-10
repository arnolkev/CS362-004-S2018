#include "dominion.h"


void handleSmithy(int currentPlayer, struct gameState *state, int handPos) {
    int i = 0;

    //+3 Cards
    for (i = 0; i < 3; i++) {
        drawCard(currentPlayer, state);
    }

    //discard card from hand
    discardCard(handPos, currentPlayer, state, 1);
}