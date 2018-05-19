/*
File: randomtestcard2.c
Date: 5/13/18
Author: Brad Besserman
Description: Random tests for the smithy card
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assertTrue.h"
#include <time.h>

#define RANDOMTEST "smithyCard"

int main(int argc, char **argv)
{
    int i;
    // Number of random tests to run;
    int iterations = 1000;
    srand(time(NULL));

    printf("Adventurer card random tests\n\n");

    for (i = 0; i < iterations; i++)
    {
        // Create new game
        struct gameState state;

        // Create game with adventurer and nine other random cards
        int k[10] = {
            smithy, -1, -1, -1, -1, -1, -1, -1, -1, -1};
        int j;
        for (j = 1; j < 10; j++)
        {
            int loop = 1;

            while (loop)
            {
                int temp = rand() % 27;

                int m;
                int available = 1;
                for (m = 0; m < 10; m++)
                {
                    if (temp == k[m])
                        available = 0;
                }

                if (available)
                {
                    k[j] = temp;
                    loop = 0;
                }
            }
        }

        // Initialize two player game with random seed
        initializeGame(2, k, rand(), &state);
        // No need to randomize choices because adventurer card does not perform any choices
        /*int choice1 = 0;
        int choice2 = 0;
        int choice3 = 0;
        int handPos = 0;*/

        int hand_copy[MAX_HAND];
        int deck_copy[MAX_DECK];
        int discard_copy[MAX_DECK];
        int discard_deck_treasures = 0;

        // Base conditions: set player, and clear hand, deck, etc
        state.whoseTurn = 0;
        state.phase = 0;
        state.handCount[0] = 0;
        memset(state.hand[0], -1, sizeof(state.hand[0]));
        state.deckCount[0] = 0;
        memset(state.deck[0], -1, sizeof(state.deck[0]));
        state.discardCount[0] = 0;
        memset(state.discard[0], -1, sizeof(state.discard[0]));
        state.playedCardCount = 0;

        // Add adventurer to hand
        state.hand[0][0] = smithy;
        hand_copy[0] = smithy;
        state.handCount[0] = 1;

        // Fill hand with up to six more random cards
        for (j = 0; j < rand() % 20; j++)
        {
            state.handCount[0]++;

            int temp = rand() % 17;

            if (temp < 10)
            {
                state.hand[0][j + 1] = k[temp];
                hand_copy[j + 1] = k[temp];
            }
            else if (temp == 10)
            {
                state.hand[0][j + 1] = copper;
                hand_copy[j + 1] = copper;
            }
            else if (temp == 11)
            {
                state.hand[0][j + 1] = silver;
                hand_copy[j + 1] = silver;
            }
            else if (temp == 12)
            {
                state.hand[0][j + 1] = gold;
                hand_copy[j + 1] = gold;
            }
            else if (temp == 13)
            {
                state.hand[0][j + 1] = estate;
                hand_copy[j + 1] = estate;
            }
            else if (temp == 14)
            {
                state.hand[0][j + 1] = duchy;
                hand_copy[j + 1] = duchy;
            }
            else if (temp == 15)
            {
                state.hand[0][j + 1] = province;
                hand_copy[j + 1] = province;
            }
            else if (temp == 16)
            {
                state.hand[0][j + 1] = curse;
                hand_copy[j + 1] = curse;
            }
        }

        // Fill discard with between 0 and 20 random cards
        for (j = 0; j < rand() % 21; j++)
        {
            state.discardCount[0]++;

            int temp = rand() % 17;

            if (temp < 10)
            {
                state.discard[0][j] = k[temp];
                discard_copy[j] = k[temp];
            }
            else if (temp == 10)
            {
                state.discard[0][j] = copper;
                discard_copy[j] = copper;
                discard_deck_treasures++;
            }
            else if (temp == 11)
            {
                state.discard[0][j] = silver;
                discard_copy[j] = silver;
                discard_deck_treasures++;
            }
            else if (temp == 12)
            {
                state.discard[0][j] = gold;
                discard_copy[j] = gold;
                discard_deck_treasures++;
            }
            else if (temp == 13)
            {
                state.discard[0][j] = estate;
                discard_copy[j] = estate;
            }
            else if (temp == 14)
            {
                state.discard[0][j] = duchy;
                discard_copy[j] = duchy;
            }
            else if (temp == 15)
            {
                state.discard[0][j] = province;
                discard_copy[j] = province;
            }
            else if (temp == 16)
            {
                state.discard[0][j] = curse;
                discard_copy[j] = curse;
            }
        }

        // Fill deck with between 0 and 20 random cards
        for (j = 0; j < rand() % 21; j++)
        {
            state.deckCount[0]++;

            int temp = rand() % 17;

            if (temp < 10)
            {
                state.deck[0][j] = k[temp];
                deck_copy[j] = k[temp];
            }
            else if (temp == 10)
            {
                state.deck[0][j] = copper;
                deck_copy[j] = copper;
                discard_deck_treasures++;
            }
            else if (temp == 11)
            {
                state.deck[0][j] = silver;
                deck_copy[j] = silver;
                discard_deck_treasures++;
            }
            else if (temp == 12)
            {
                state.deck[0][j] = gold;
                deck_copy[j] = gold;
                discard_deck_treasures++;
            }
            else if (temp == 13)
            {
                state.deck[0][j] = estate;
                deck_copy[j] = estate;
            }
            else if (temp == 14)
            {
                state.deck[0][j] = duchy;
                deck_copy[j] = duchy;
            }
            else if (temp == 15)
            {
                state.deck[0][j] = province;
                deck_copy[j] = province;
            }
            else if (temp == 16)
            {
                state.deck[0][j] = curse;
                deck_copy[j] = curse;
            }
        }

        if (discard_deck_treasures > 2)
            discard_deck_treasures = 2;

        // Randomize number of actions (between 1 and 3)
        // Not testing 0 because 0 is not playing smithy - it is testing playCard instead
        state.numActions = rand() % 3 + 1;

        updateCoins(0, &state, 0);

        // Get copy of state variables for testing
        int numPlayers = state.numPlayers;
        int whoseTurn = state.whoseTurn;
        int phase = state.phase;
        int numActions = state.numActions;
        int coins = state.coins;
        int numBuys = state.numBuys;
        int handCount = state.handCount[0];
        int deckCount = state.deckCount[0];
        int discardCount = state.discardCount[0];
        int playedCardCount = state.playedCardCount;

        if (DEBUG)
            printf("\nIteration %d\n\n", i + 1);

        int result = playCard(0, 0, 0, 0, &state);

        if (DEBUG)
        {
            printf("numPlayers: %d -> %d\n", numPlayers, state.numPlayers);
            printf("whoseTurn: %d -> %d\n", whoseTurn, state.whoseTurn);
            printf("phase: %d -> %d\n", phase, state.phase);
            printf("numActions: %d -> %d\n", numActions, state.numActions);
            printf("coins: %d -> %d\n", coins, state.coins);
            printf("numBuys: %d -> %d\n", numBuys, state.numBuys);
            printf("hand: ");
            for (j = 0; j < handCount; j++)
            {
                printf("%s ", getCardName(hand_copy[j]));
            }
            printf("-> ");
            for (j = 0; j < state.handCount[0]; j++)
            {
                printf("%s ", getCardName(state.hand[0][j]));
            }
            printf("\n");
            printf("handCount: %d -> %d\n", handCount, state.handCount[0]);
            printf("deck: ");
            for (j = 0; j < deckCount; j++)
            {
                printf("%s ", getCardName(deck_copy[j]));
            }
            printf("-> ");
            for (j = 0; j < state.deckCount[0]; j++)
            {
                printf("%s ", getCardName(state.deck[0][j]));
            }
            printf("\n");
            printf("deckCount: %d -> %d\n", deckCount, state.deckCount[0]);
            printf("discard: ");
            for (j = 0; j < discardCount; j++)
            {
                printf("%s ", getCardName(discard_copy[j]));
            }
            printf("-> ");
            for (j = 0; j < state.discardCount[0]; j++)
            {
                printf("%s ", getCardName(state.discard[0][j]));
            }
            printf("\n");
            printf("discardCount: %d -> %d\n", discardCount, state.discardCount[0]);
            if (state.playedCardCount > 0)
            {
                printf("played: -> %s\n", getCardName(state.playedCards[0]));
            }
            printf("playedCount: %d -> %d\n\n", playedCardCount, state.playedCardCount);
        }

        if (result != 0)
        {
            printf("%d - ERROR: playCard returned -1 (card play failure)\n", i + 1);
        }
        if (numPlayers != state.numPlayers)
        {
            printf("%d - ERROR: numPlayers changed during execution\n", i + 1);
        }
        if (whoseTurn != state.whoseTurn)
        {
            printf("%d - ERROR: turn changed during card play\n", i + 1);
        }
        if (phase != state.phase)
        {
            printf("%d - ERROR: phase changed when card was played\n", i + 1);
        }
        if (numActions - 1 != state.numActions)
        {
            printf("%d - ERROR: number of actions should change when card is played\n", i + 1);
        }

        if (discardCount + deckCount < 3)
        {
            // Draw he rest of the deck/discard, then subtract the one played card
            if (handCount + discardCount + deckCount - 1 != state.handCount[0])
            {
                {
                    printf("%d - ERROR: wrong number of cards drawn to hand\n", i + 1);
                }
            }
        }
        else {
            // Draw three cards, then subtract the one played card
            if (handCount + 2 != state.handCount[0])
            {
                {
                    printf("%d - ERROR: wrong number of cards drawn to hand\n", i + 1);
                }
            }
        }

        if (handCount + deckCount + discardCount != state.handCount[0] + state.deckCount[0] + state.discardCount[0] + state.playedCardCount)
        {
            printf("%d - ERROR: card(s) unaccounted for after card was played\n", i + 1);
        }
        if (numBuys != state.numBuys)
        {
            printf("%d - ERROR: number of buys should not change\n", i + 1);
        }
        if (state.playedCardCount > 0)
        {
            if (state.playedCards[0] != smithy)
            {
                printf("%d - ERROR: incorrect card in played pile\n", i + 1);
            }
        }

        if (state.playedCardCount != 1)
        {
            printf("%d - ERROR: incorrect number of cards in played pile\n", i + 1);
        }
    }

    return 0;
}