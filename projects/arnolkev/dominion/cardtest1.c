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
    int treasureCount = 0;
    int originalTreasureCount = 0;
    int card;
    printf("playAdventurer() test\n");
    memset(&state, 23, sizeof(struct gameState));
    memset(&original, 23, sizeof(struct gameState));

    initializeGame(2, k, seed, &state);
    memcpy(&original, &state, sizeof(struct gameState));

    cardEffect(adventurer, 0, 0, 0, &state, 0, &bonus);
    //compare handsizes
    printf("\ngain two cards\n");
    printf("actual: %d\n", state.handCount[0]);
    printf("expected: %d\n", original.handCount[0] + 1);

    assertTrue(state.handCount[0], original.handCount[0] + 1);

    //compare treasure totals
     for (i = 0; i < state.handCount[0]; i++) 
    {
        card = state.hand[0][i];
        if (card == copper || card == silver || card == gold) 
        {
            treasureCount++;
        }
    }


    for (i = 0; i < original.handCount[0]; i++) 
    {
        card = original.hand[0][i];
        if (card == copper || card == silver || card == gold) 
        {
            originalTreasureCount++;
        }
    }

    printf("\ngain 2 treasure cards\n");
    assertTrue(originalTreasureCount + 2,treasureCount);



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