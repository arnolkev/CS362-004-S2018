#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int failure = 0;

void assertTrue(int a, int b) {
    if (a == b) {
        printf("Test: PASSED\n");
    }
    else {
        printf("Test: FAILED\n");
        failure++;
    }
}

int main() {
    int k[10] = {adventurer, smithy, baron, village, steward, great_hall, mine, salvager, sea_hag, treasure_map};
    int seed = 666;
    struct gameState state;
    int handCount, deckCount;


    printf("gainCard() test\n");
    memset(&state,23,sizeof(struct gameState));
    initializeGame(2, k, seed, &state);


    printf("\nsupply pile is empty\n");
    state.supplyCount[copper] = 0;
    assertTrue(gainCard(copper, &state, 0, 0), -1);
    
    state.supplyCount[copper] = 30;

    printf("\nadd card to deck\n");
    deckCount = state.deckCount[0];
    gainCard(copper, &state, 1, 0);
    assertTrue(deckCount + 1, state.deckCount[0]);

    printf("\nAdd card to hand\n");
    handCount = state.handCount[0];
    gainCard(copper, &state, 2, 0);
    assertTrue(handCount + 1, state.handCount[0]);

    printf("\ncheck if correct card was added\n");
    assertTrue(copper, state.hand[0][0]);

    printf("\nAdd card to discard pile\n");
    int discardCount = state.discardCount[0];
    gainCard(copper, &state, 0, 0);
    assertTrue(discardCount + 1, state.discardCount[0]);

    printf("\ncheck if correct card was added\n");
    assertTrue(copper, state.discard[0][0]);

    printf("\nDecrease copper supply\n");
    int coppertotal = state.supplyCount[copper];
    gainCard(copper, &state, 0, 0);
    assertTrue(coppertotal - 1, state.supplyCount[copper]);




    if (failure) {
        printf("\nTEST FAILURE\n");
        printf("Fails: %d\n",failure);
    }
    else {
        printf("\nTEST SUCCESSFUL\n");
    }

    return 0;

}