#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int failure = 0;

void assertTrue(int a, int b)
 {
    if (a == b) 
    {
        printf("Test: PASSED\n");
    }
    else
    {
        printf("Test: FAILED\n");
        failure++;
    }
}

int main() {
    int i;
    int k[10] = {adventurer, smithy, baron, village, steward, great_hall, mine, salvager, sea_hag, treasure_map};
    int seed = 666;
    struct gameState state, original;
    
    int bonus = 1;

    printf("playSmithy() test\n");
    memset(&state, 23, sizeof(struct gameState));
    memset(&original, 23, sizeof(struct gameState));

    initializeGame(2, k, seed, &state);
    memcpy(&original, &state, sizeof(struct gameState));

    cardEffect(smithy, 0, 0, 0, &state, 0, &bonus);


    printf("\ngain 3 cards\n");
    printf("actual: %d\n", state.handCount[0]);
    printf("expected: %d\n", original.handCount[0] + 2);
    assertTrue(state.handCount[0], original.handCount[0] + 2);

    printf("\n3 cards were from own deck\n");
    printf("actual: %d\n", state.deckCount[0]);
    printf("expected: %d\n", original.deckCount[0] - 3);
    assertTrue(state.deckCount[0], original.deckCount[0] - 3);

    printf("\nNo change to supply piles\n");
     for (i = 0; i <= 26; i++) 
     {
        printf("checking card pile %d\n", i);
        printf("actual: %d\n", state.supplyCount[i]);
        printf("expected: %d\n", original.supplyCount[i]);
        assertTrue(state.supplyCount[i], original.supplyCount[i]);
    }


    if (failure) 
    {
        printf("\nTEST FAILURE\n");
        printf("Fails: %d\n",failure);
    }
    else 
    {
        printf("\nTEST SUCCESSFUL\n");
    }

    return 0;

}