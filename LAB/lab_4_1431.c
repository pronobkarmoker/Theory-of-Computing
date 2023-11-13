#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATES 100
#define MAX_ALPHABET 100

typedef struct
{

    int nos;
    int noa;
    int nos;
    int noa;

    int nof;

    int startState;
    int alphabet[MAX_ALPHABET];
    int finalStates[MAX_STATES];

    int trns[MAX_STATES][MAX_ALPHABET][MAX_STATES];
} NFA;

typedef struct
{

    int nos;
    int noa;
    int nof;
    int nos;
    int noa;
    int nof;

    int startState;
    int alphabet[MAX_ALPHABET];
    int finalStates[MAX_STATES];

    int trns[MAX_STATES][MAX_ALPHABET];
} DFA;

int states[MAX_STATES];
int newStates[MAX_STATES];
int numNewStates = 0;
DFA dfa;
NFA nfa;

void initNfa();
void initDfa();
void NfaToDfa();
void printDfa();

int main()
{

    initNfa();
    initDfa();
    NfaToDfa();
    printDfa();

    return 0;
}

void initNfa()
{

    int numEdge;
    char end[5];

    printf("How many states: ");
    scanf("%d", &nfa.nos);
    getchar();

    printf("How many Alphabets: ");
    scanf("%d", &nfa.noa);
    getchar();

    printf("How many final states: ");
    scanf("%d", &nfa.nof);
    getchar();

    printf("What is the starting state: ");
    scanf("%d", &nfa.startState);
    getchar();

    printf("Enter the alphabets:\n");
    for (int i = 0; i < nfa.noa; i++)
    {
        int firstElement;
        char temp;
        printf("Alphabet %d = ", i);
        scanf("%c", &temp);
        getchar();
        if (!i)
            firstElement = (int)temp;
        nfa.alphabet[i] = (int)temp - firstElement;
    }

    printf("Enter the final states:\n");
    for (int i = 0; i < nfa.nof; i++)
    {
        printf("final state %d = ", i);
        scanf("%d", &nfa.finalStates[i]);
        getchar();
    }

    for (int i = 0; i < nfa.nos; i++)
    {
        for (int j = 0; j < nfa.noa; j++)
        {
            for (int k = 0; k < nfa.nos; k++)
            {
                nfa.trns[i][j][k] = 0;
            }
        }
    }

    printf("How many edges: ");
    scanf("%d", &numEdge);
    getchar();

    printf("Enter the transition table (startState alphabet endState)\n");

    for (int i = 0; i < numEdge; i++)
    {
        int i, j, k;
        scanf("%d", &i);
        getchar();
        scanf("%d", &j);
        getchar();
        scanf("%s", end);
        getchar();

        if (!strcmp(end, "phi"))
        {
            k = i;
        }
        else
        {
            k = atoi(end);
        }

        nfa.trns[i][j][k] = 1;
    }
}

void initDfa()
{
    dfa.nos = nfa.nos;
    dfa.noa = nfa.noa;

    dfa.nof = 0;
    dfa.nof = 0;

    dfa.startState = nfa.startState;
    for (int i = 0; i < dfa.noa; i++)
    {
        dfa.alphabet[i] = nfa.alphabet[i];
    }

    for (int i = 0; i < dfa.nof; i++)
    {
        dfa.finalStates[i] = dfa.finalStates[i];
    }

    for (int i = 0; i < MAX_STATES; i++)
    {
        for (int j = 0; j < MAX_ALPHABET; j++)
        {
            dfa.trns[i][j] = 0;
        }
    }
}

void NfaToDfa()
{

    memset(states, 0, sizeof(states));

    for (int i = 0; i < nfa.nos; i++)
    {
        states[1 << i] = 1;
    }

    for (int i = 0; i < nfa.nos; i++)
    {
        for (int j = 0; j < nfa.noa; j++)
        {
            int state_union = 0;
            for (int k = 0; k < nfa.nos; k++)
            {
                if (nfa.trns[i][j][k])
                {
                    state_union |= 1 << k;
                }
            }
            if (!states[state_union])
            {
                newStates[numNewStates++] = state_union;
                states[state_union] = 1;
                dfa.nos++;
            }
            dfa.trns[1 << i][j] = state_union;
        }
    }
    for (int i = 0; i < numNewStates; i++)
    {
        for (int j = 0; j < nfa.noa; j++)
        {
            int state_union = 0;
            for (int k = 0; k < dfa.nos; k++)
            {
                if (newStates[i] & (1 << k))
                {
                    state_union |= dfa.trns[1 << k][j];
                }
            }
            dfa.trns[newStates[i]][j] = state_union;
            if (!states[state_union])
            {
                newStates[numNewStates++] = state_union;
                states[state_union] = 1;
                dfa.nos++;
            }
        }
    }

    for (int i = 0; i < MAX_STATES; i++)
    {
        if (states[i])
        {
            for (int j = 0; j < nfa.nof; j++)
            {
                if (i & (1 << nfa.finalStates[j]))
                {
                    dfa.finalStates[dfa.nof++] = i;
                }
            }
        }
    }
}

void printDfa()
{
    printf("Starting state: q%d\n", dfa.startState);
    printf("Number of final states: %d\n", dfa.nof);
    printf("Final states: \n");
    for (int i = 0; i < dfa.nof; i++)
    {
        for (int j = 0; j < nfa.nos; j++)
        {
            if (dfa.finalStates[i] & (1 << j))
            {
                printf("q%d ", j);
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("Number of states in the dfa : %d\n", dfa.nos);
    printf("Transition table:\n");
    printf("states:0      1\n");
    printf("---------------\n");
    for (int i = 0; i < MAX_STATES; i++)
    {
        if (states[i])
        {
            int flag = 0;
            for (int j = 0; j < nfa.nos; j++)
            {
                if (i & (1 << j))
                {
                    printf("q%d ", j);
                    flag++;
                }
            }
            if (flag == 1)
            {
                printf("    %d      %d\n", dfa.trns[i][0], dfa.trns[i][1]);
            }
            else if (flag == 2)
            {
                printf(" %d      %d\n", dfa.trns[i][0], dfa.trns[i][1]);
            }
        }
    }
}