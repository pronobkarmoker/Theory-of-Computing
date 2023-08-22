#include <stdio.h>
#include <string.h>

#define MAX_STATES 100
#define MAX_SYMBOLS 10

typedef struct
{
    int states[MAX_STATES];
    int numStates;
} StateSet;

typedef struct
{
    StateSet states[MAX_STATES];
    int numSets;
} PowerSet;

int main()
{
   int numStates, numSymbols, startState, endState;

    printf("Enter the number of states: ");
    scanf("%d", &numStates);

    printf("Enter the number of symbols: ");
    scanf("%d", &numSymbols);

    char symbols[MAX_SYMBOLS];
    printf("Enter the symbols: ");
    scanf("%s", symbols);

    int transitions[MAX_STATES][MAX_SYMBOLS][MAX_STATES];
    FILE *file = fopen("nfa-to-dfa.txt", "r");

    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numSymbols; j++) {
            for (int k = 0; k < numStates; k++) {
                fscanf(file, "%d", &transitions[i][j][k]);
            }
        }
    }
    printf("Enter Starting State: ");
    scanf("%d", &startState);

    printf("Enter Ending State: ");
    scanf("%d", &endState);

    PowerSet dfaStates;
    StateSet initSet;
    initSet.states[0] = startState;
    initSet.numStates = 1;
    dfaStates.states[0] = initSet;
    dfaStates.numSets = 1;

    int dfaTrans[MAX_STATES][MAX_SYMBOLS];

    for (int i = 0; i < dfaStates.numSets; i++)
    {
        for (int j = 0; j < numSymbols; j++)
        {
            StateSet moveRes;
            moveRes.numStates = 0;

            for (int k = 0; k < dfaStates.states[i].numStates; k++)
            {
                int state = dfaStates.states[i].states[k];
                for (int l = 0; l < numStates; l++)
                {
                    if (transitions[state][j][l] != -1)
                    {
                        moveRes.states[moveRes.numStates++] = transitions[state][j][l];
                    }
                }
            }

            StateSet nextSet;
            nextSet.numStates = 0;

            for (int k = 0; k < moveRes.numStates; k++)
            {
                int stateToAdd = moveRes.states[k];
                int isDuplicate = 0;
                for (int l = 0; l < nextSet.numStates; l++)
                {
                    if (nextSet.states[l] == stateToAdd)
                    {
                        isDuplicate = 1;
                        break;
                    }
                }
                if (!isDuplicate)
                {
                    nextSet.states[nextSet.numStates++] = stateToAdd;
                }
            }

            int duplicate = 0;
            for (int k = 0; k < dfaStates.numSets; k++)
            {
                int same = 1;
                if (nextSet.numStates == dfaStates.states[k].numStates)
                {
                    for (int l = 0; l < nextSet.numStates; l++)
                    {
                        if (nextSet.states[l] != dfaStates.states[k].states[l])
                        {
                            same = 0;
                            break;
                        }
                    }
                    if (same)
                    {
                        duplicate = 1;
                        dfaTrans[i][j] = k;
                        break;
                    }
                }
            }

            if (!duplicate)
            {
                dfaStates.states[dfaStates.numSets] = nextSet;
                dfaTrans[i][j] = dfaStates.numSets;
                dfaStates.numSets++;
            }
        }
    }

    // Print DFA states and transition state table
    printf("DFA States:\n");
    for (int i = 0; i < dfaStates.numSets; i++)
    {
        printf("DFA State %d:", i);
        for (int j = 0; j < dfaStates.states[i].numStates; j++)
        {
            printf(" %d", dfaStates.states[i].states[j]);
        }
        printf("\n");
    }

    printf("\nTransition State Table:\n");
    printf("    ");
    for (int j = 0; j < numSymbols; j++)
    {
        printf(" %c ", symbols[j]);
    }
    printf("\n");

    for (int i = 0; i < dfaStates.numSets; i++)
    {
        printf("DFA State %d:", i);
        for (int j = 0; j < numSymbols; j++)
        {
            printf(" %d ", dfaTrans[i][j]);
        }
        printf("\n");
    }

    // Print starting state
    printf("\nStarting State: %d\n", 0); // Change 0 to your actual starting state index

    // Print final states
    printf("Final States:\n");
    for (int i = 0; i < dfaStates.numSets; i++)
    {
        int isFinal = 0;
        for (int j = 0; j < dfaStates.states[i].numStates; j++)
        {
            if (dfaStates.states[i].states[j] == endState)
            {
                isFinal = 1;
                break;
            }
        }
        if (isFinal)
        {
            printf("DFA State %d:", i);
            for (int j = 0; j < dfaStates.states[i].numStates; j++)
            {
                printf(" %d", dfaStates.states[i].states[j]);
            }
            printf("\n");
        }
    }

    return 0;
}