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
    int i;
    int k[10] = {adventurer, smithy, baron, village, steward, great_hall, mine, salvager, sea_hag, treasure_map};
    int seed = 666;
    struct gameState state;
    int handCount;
    int bonus = 1;
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];

    // arrays full of designated treasure
    for (i = 0; i < MAX_HAND; i++) {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf("updateCoins() test");

    for (handCount = 0; handCount <= 5; handCount++){
        
        printf("\ntreasure cards: %d\n", handCount);
        printf("bonus: %d\n", bonus);

        memset(&state, 23, sizeof(struct gameState));
        initializeGame(2, k, seed, &state);
        state.handCount[0] = handCount;

        memcpy(state.hand[0],coppers,sizeof(int)*handCount);
        updateCoins(0, &state, bonus);

        printf("\ncopper\n");
        printf("actual: %d\n", state.coins);
        printf("expected: %d\n", handCount * 1 + bonus);

        assertTrue(state.coins, handCount * 1 + bonus);

        memcpy(state.hand[0],silvers,sizeof(int)*handCount);
        updateCoins(0, &state, bonus);

        printf("\nsilver\n");
        printf("actual: %d\n", state.coins);
        printf("expected: %d\n",handCount * 2 + bonus);

        assertTrue(state.coins, handCount * 2 + bonus);

        memcpy(state.hand[0],golds,sizeof(int)*handCount);
        updateCoins(0,&state,bonus);

        printf("\ngold\n");
        printf("actual: %d\n", state.coins);
        printf("expected: %d\n", handCount * 3 + bonus);

        assertTrue(state.coins, handCount * 3 + bonus);

        bonus++;


    }

    if (failure) {
        printf("\nTEST FAILURE\n");
        printf("Fails: %d\n",failure);
    }
    else {
        printf("\nTEST SUCCESSFUL\n");
    }

    return 0;

}
