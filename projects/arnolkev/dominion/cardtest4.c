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
    struct gameState state, original;
    int bonus = 1;

    printf("playSteward() test\n");
    memset(&state, 23, sizeof(struct gameState));
    memset(&original, 23, sizeof(struct gameState));
    initializeGame(2, k, seed, &state);
    memcpy(&original, &state, sizeof(struct gameState));

    cardEffect(steward, 1, 0, 0, &state, 0, &bonus);

    printf("\nchoice 1 gain 2 cards\n");
    printf("actual: %d\n", state.handCount[0]);
    printf("expected: %d\n", original.handCount[0] + 1);
    assertTrue(state.handCount[0], original.handCount[0] + 1);


    printf("\ncard was from own deck\n");
    printf("actual: %d\n", state.deckCount[0]);
    printf("expected: %d\n", original.deckCount[0] - 2);
    assertTrue(state.deckCount[0], original.deckCount[0] - 2);
    
    printf("\ncheck coins\n");
    printf("actual: %d\n", state.coins);
    printf("expected: %d\n", original.coins);
    assertTrue(state.coins, original.coins);
    
    printf("\nNo change to supply piles\n");
    for (i = 0; i <= 26; i++) 
    {
        printf("checking card pile %d\n", i);
        printf("actual: %d\n", state.supplyCount[i]);
        printf("expected: %d\n", original.supplyCount[i]);
        assertTrue(state.supplyCount[i], original.supplyCount[i]);
    }

    state.handCount[0]--;
    state.deckCount[0]++;
    state.deckCount[0]++;
    
    
    cardEffect(steward, 2, 0, 0, &state, 0, &bonus);

    printf("\nchoice 2 gain 2 coins\n");
    printf("actual: %d\n", state.coins);
    printf("expected: %d\n", original.coins + 2);
    assertTrue(state.coins, original.coins + 2);

    printf("\ncheck hand\n");
    printf("actual: %d\n", state.handCount[0]);
    printf("expected: %d\n", original.handCount[0] - 1);
    assertTrue(state.handCount[0], original.handCount[0] - 1);


    printf("\ncheck deck\n");
    printf("actual: %d\n", state.deckCount[0]);
    printf("expected: %d\n", original.deckCount[0]);
    assertTrue(state.deckCount[0], original.deckCount[0]);


    printf("\nNo change to supply piles\n");
    for (i = 0; i <= 26; i++) 
    {
        printf("checking card pile %d\n", i);
        printf("actual: %d\n", state.supplyCount[i]);
        printf("expected: %d\n", original.supplyCount[i]);
        assertTrue(state.supplyCount[i], original.supplyCount[i]);
    }

    state.handCount[0]++;
    state.coins--;
    state.coins--;
   

    cardEffect(steward, 3, 0, 0, &state, 0, &bonus);

    printf("\nchoice 3 trash 2 cards\n");
     printf("\ncheck cards are not in discard");
    printf("actual: %d\n", state.discardCount[0]);
    printf("expected: %d\n", original.discardCount[0] + 1);
    assertTrue(state.discardCount[0], original.discardCount[0] + 1);
    
    printf("\ncheck coins\n");
    printf("actual: %d\n", state.coins);
    printf("expected: %d\n", original.coins);
    assertTrue(state.coins, original.coins);

    printf("\ncheck hand\n");
    printf("actual: %d\n", state.handCount[0]);
    printf("expected: %d\n", original.handCount[0] - 3);
    assertTrue(state.handCount[0], original.handCount[0] - 3);


    printf("\ncheck deck\n");
    printf("actual: %d\n", state.deckCount[0]);
    printf("expected: %d\n", original.deckCount[0]);
    assertTrue(state.deckCount[0], original.deckCount[0]);

   



    if (failure) {
        printf("\nTEST FAILURE\n");
        printf("Fails: %d\n",failure);
    }
    else {
        printf("\nTEST SUCCESSFUL\n");
    }

    return 0;

}