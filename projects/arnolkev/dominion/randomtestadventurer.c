#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>


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
    srand(time(NULL));
    int i, j;
    int k[10] = {adventurer, smithy, baron, village, steward, great_hall, mine, salvager, sea_hag, treasure_map};
    int seed;
    struct gameState *state;
    int treasureCount = 0;
    int originalTreasureCount = 0;
    int card;
    int players;
    printf("playAdventurer() random test\n");


    for(i = 0; i < 500; i++){
        originalTreasureCount = 0;
        treasureCount = 0;
        players = rand() % 4;
        seed = rand();

        state = malloc(sizeof(struct gameState));
        

        initializeGame(players, k, seed, state);
        


        state->deckCount[0] = rand() % MAX_DECK;
        for(j = 10; j < state->deckCount[0]; j++){
            state->deck[0][j] = rand() % 27;
        }
        shuffle(0, state);


        state->discardCount[0] = rand() % (MAX_DECK - state->deckCount[0]);
        if(state->discardCount[0] != 0){
            state->discardCount[0]--;
        }
        for(j = 0; j < state->discardCount[0]; j++){
            state->discard[0][j] = rand() % 27;
        }
        int chance = rand() % 10;
		if(chance == 5){
			for (j = 0; j < state->deckCount[0];j++){
            state->discard[0][state->discardCount[0] + j] = state->deck[0][j];
            state->deck[0][j] = -1;
            }
            
            state->discardCount[0] += state->deckCount[0];
            state->deckCount[0] = 0;
		}


        state->handCount[0] = (rand() % (MAX_HAND - (state->deckCount[0] + state->discardCount[0]))) + 1;

        state->hand[0][0] = adventurer;
        
        for(j = 1; j < state->handCount[0]; j++){
            state->hand[0][j] = rand() % 27;
        }
       

        for (j = 0; j < state->handCount[0]; j++) 
        {
            card = state->hand[0][j];
            if (card == copper || card == silver || card == gold) 
            {
                originalTreasureCount++;
            }
        }
        int oghandcount = state->handCount[0];
        cardEffect(adventurer, 0, 0, 0, state, 0, 0);

        for (j = 0; j < state->handCount[0]; j++) 
        {
            card = state->hand[0][j];
            if (card == copper || card == silver || card == gold) 
            {
                treasureCount++;
            }
        }
        
        assertTrue(originalTreasureCount + 2,treasureCount);
        assertTrue(oghandcount+1, state->handCount[0]);
        free(state);
    }
    printf("Status: %d failures of the playAdventurer\n", failure);
    return 0;
}