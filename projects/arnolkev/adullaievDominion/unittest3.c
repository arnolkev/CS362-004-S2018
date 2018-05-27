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
    int handCount = 1;
    int hand1[MAX_HAND];
    hand1[0] = copper;
    int fullhand[MAX_HAND];
    fullhand[0] = copper;
    fullhand[1] = silver;
    fullhand[2] = gold;
    fullhand[3] = smithy;
    fullhand[4] = baron;


    printf("discardCard() test\n");
    memset(&state, 23, sizeof(struct gameState));
    initializeGame(2, k, seed, &state);
    state.handCount[0] = handCount;
    memcpy(state.hand[0], hand1, sizeof(int)*handCount);
 
    discardCard(0, 0, &state, 0);

    printf("\nsingle card no trash\n");
    printf("actual hand size: %d\n", state.handCount[0]);
    printf("expected hand size: %d\n", handCount - 1);

    assertTrue(state.handCount[0], handCount - 1);

    printf("actual card discarded: %d\n", state.playedCards[0]);
    printf("expected card discarded: %d\n", copper);

    assertTrue(state.playedCards[0], copper);

    printf("actual card count: %d\n", state.playedCardCount);
    printf("expected card count: %d\n", 1);

    assertTrue(state.playedCardCount, 1);

    memset(&state, 23, sizeof(struct gameState));
    initializeGame(2, k, seed, &state);
    state.handCount[0] = handCount;
    memcpy(state.hand[0], hand1, sizeof(int)*handCount);

    discardCard(0, 0, &state, 1);



    printf("\nsingle card trash\n");
    printf("actual hand size: %d\n", state.handCount[0]);
    printf("expected hand size: %d\n", handCount - 1);

    assertTrue(state.handCount[0], handCount - 1);

    printf("actual playedcard count: %d\n", state.playedCardCount);
    printf("expected playedcard count: %d\n", 0);

    assertTrue(state.playedCardCount, 0);


    handCount = 5;
    memset(&state, 23, sizeof(struct gameState));
    initializeGame(2, k, seed, &state);
    state.handCount[0] = handCount;
    memcpy(state.hand[0], fullhand, sizeof(int)*handCount);

    discardCard(4, 0, &state, 1);

    printf("\nfull hand discard last card\n");
    printf("actual hand size: %d\n", state.handCount[0]);
    printf("expected hand size: %d\n", handCount - 1);

    assertTrue(state.handCount[0], handCount - 1);

    printf("actual hand pos 0: %d\n", state.hand[0][0]);
    printf("expected hand pos 0: %d\n", copper);

    assertTrue(state.hand[0][0], copper);

    printf("actual hand pos 1: %d\n", state.hand[0][1]);
    printf("expected hand pos 1: %d\n", silver);

    assertTrue(state.hand[0][1], silver);

    printf("actual hand pos 2: %d\n", state.hand[0][2]);
    printf("expected hand pos 2: %d\n", gold);

    assertTrue(state.hand[0][2], gold);

    printf("actual hand pos 3: %d\n", state.hand[0][3]);
    printf("expected hand pos 3: %d\n", smithy);

    assertTrue(state.hand[0][3], smithy);



    memset(&state, 23, sizeof(struct gameState));
    initializeGame(2, k, seed, &state);
    state.handCount[0] = handCount;
    memcpy(state.hand[0], fullhand, sizeof(int)*handCount);

    discardCard(2, 0, &state, 1);

    printf("\nfull hand discard middle card\n");
    printf("actual hand size: %d\n", state.handCount[0]);
    printf("expected hand size: %d\n", handCount - 1);

    assertTrue(state.handCount[0], handCount - 1);

    printf("actual hand pos 0: %d\n", state.hand[0][0]);
    printf("expected hand pos 0: %d\n", copper);

    assertTrue(state.hand[0][0], copper);

    printf("actual hand pos 1: %d\n", state.hand[0][1]);
    printf("expected hand pos 1: %d\n", silver);

    assertTrue(state.hand[0][1], silver);

    printf("actual hand pos 2: %d\n", state.hand[0][2]);
    printf("expected hand pos 2: %d\n", baron);

    assertTrue(state.hand[0][2], baron);

    printf("actual hand pos 3: %d\n", state.hand[0][3]);
    printf("expected hand pos 3: %d\n", smithy);

    assertTrue(state.hand[0][3], smithy);





    if (failure) {
        printf("\nTEST FAILURE\n");
        printf("Fails: %d\n",failure);
    }
    else {
        printf("\nTEST SUCCESSFUL\n");
    }

    return 0;

}