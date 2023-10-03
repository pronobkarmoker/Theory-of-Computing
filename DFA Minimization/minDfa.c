#include <stdio.h>
#include <stdlib.h>

#define NUM_STATES 8
#define NUM_SYMBOLS 2

char transitions[NUM_STATES][NUM_SYMBOLS] = {
    {'B', 'A'},
    {'A', 'C'},
    {'D', 'B'},
    {'D', 'A'},
    {'D', 'F'},
    {'G', 'E'},
    {'F', 'G'},
    {'G', 'D'},
};

void initializeTable(int table[NUM_STATES][NUM_STATES])
{
    for (int i = 0; i < NUM_STATES; i++)
    {
        for (int j = 0; j < NUM_STATES; j++)
        {
            table[i][j] = 0;
        }
    }
}

void markNonEquivalent(int table[NUM_STATES][NUM_STATES], int state1, int state2)
{
    table[state1][state2] = 1;
    table[state2][state1] = 1;
}

void tableFillingAlgorithm(int table[NUM_STATES][NUM_STATES])
{

    initializeTable(table);

    int finalStates[] = {3};
    for (int i = 0; i < NUM_STATES; i++)
    {
        for (int j = i + 1; j < NUM_STATES; j++)
        {
            int isFinalState1 = 0;
            int isFinalState2 = 0;
            for (int k = 0; k < sizeof(finalStates) / sizeof(finalStates[0]); k++)
            {
                if (i == finalStates[k])
                {
                    isFinalState1 = 1;
                }
                if (j == finalStates[k])
                {
                    isFinalState2 = 1;
                }
            }
            if ((isFinalState1 && !isFinalState2) || (!isFinalState1 && isFinalState2))
            {
                markNonEquivalent(table, i, j);
            }
        }
    }

    int changed = 1;
    while (changed)
    {
        changed = 0;
        for (int i = 0; i < NUM_STATES; i++)
        {
            for (int j = i + 1; j < NUM_STATES; j++)
            {
                if (!table[i][j])
                {
                    for (int k = 0; k < NUM_SYMBOLS; k++)
                    {
                        int nextState1 = transitions[i][k] - 'A';
                        int nextState2 = transitions[j][k] - 'A';
                        if (table[nextState1][nextState2])
                        {
                            markNonEquivalent(table, i, j);
                            changed = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int distinguishabilityTable[NUM_STATES][NUM_STATES];

    tableFillingAlgorithm(distinguishabilityTable);

    printf("Distinguishability Table:\n");
    for (int i = 0; i < NUM_STATES; i++)
    {
        for (int j = 0; j < NUM_STATES; j++)
        {
            printf("%d ", distinguishabilityTable[i][j]);
        }
        printf("\n");
    }

    printf("Equivalent State Pairs:\n");
    for (int i = 0; i < NUM_STATES; i++)
    {
        for (int j = i + 1; j < NUM_STATES; j++)
        {
            if (!distinguishabilityTable[i][j])
            {
                printf("(%c, %c) ", 'A' + i, 'A' + j);
            }
        }
    }
    printf("\n");

    return 0;
}
