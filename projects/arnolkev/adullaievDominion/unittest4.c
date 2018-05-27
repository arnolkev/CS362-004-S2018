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


    printf("isGameOver() test\n");

    memset(&state, 23, sizeof(struct gameState));
    initializeGame(2, k, seed, &state);

    state.supplyCount[province] = 0;

    printf("\nprovince cards empty\n");
    assertTrue(isGameOver(&state), 1);

    state.supplyCount[province] = 1;

    state.supplyCount[0] = 0;
    state.supplyCount[1] = 0;
    state.supplyCount[2] = 0;

    printf("\nall supply piles empty\n");
    assertTrue(isGameOver(&state), 1);

    state.supplyCount[0] = 1;

    printf("\ntwo supply piles empty\n");
    assertTrue(isGameOver(&state), 0);

    state.supplyCount[1] = 1;

    printf("\none supply pile empty\n");
    assertTrue(isGameOver(&state), 0);

    state.supplyCount[2] = 1;

    printf("\nProvince cards not empty and");
    printf("\nThree supply piles not empty\n");
    assertTrue(isGameOver(&state), 0);





    if (failure) {
        printf("\nTEST FAILURE\n");
        printf("Fails: %d\n",failure);
    }
    else {
        printf("\nTEST SUCCESSFUL\n");
    }

    return 0;

}