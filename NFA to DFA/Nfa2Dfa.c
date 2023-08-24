#include <stdio.h>
#include <string.h>

#define MAX_STATES 100
#define MAX_SYMBOLS 10

// Input Variables
char transition_table[MAX_STATES][MAX_SYMBOLS][MAX_STATES];
char states[MAX_STATES][10];     // Assuming states are represented as strings
char alphabets[MAX_SYMBOLS][10]; // Assuming alphabets are represented as strings
char start_state[10];

// Output Variables
char dfa_table[MAX_STATES][MAX_SYMBOLS][MAX_STATES][10]; // 4D array to store DFA transitions
char completed[MAX_STATES][10];                          // Array to track completed states

// Function Prototypes
void take_input();
void print_output();
void create_state_transitions(char *state);
void unite(char store_state[MAX_STATES][10], int store_state_size, char *new_state);
char *fetch(char c, int alphabet);
int isCompleted(char *state);
void print_dfa();

int main()
{
    take_input();
    print_output();
    create_state_transitions(start_state);
    print_dfa();
    return 0;
}

void take_input()
{
    int number_of_states, number_of_alphabets;
    char state[10];

    printf("Number of states: ");
    scanf("%d", &number_of_states);
    printf("Enter states: ");
    for (int i = 0; i < number_of_states; i++)
    {
        scanf("%s", state);
        strcpy(states[i], state);
    }

    printf("Number of alphabets: ");
    scanf("%d", &number_of_alphabets);
    printf("Enter alphabets: ");
    char alphabet[10];
    for (int i = 0; i < number_of_alphabets; i++)
    {
        scanf("%s", alphabet);
        strcpy(alphabets[i], alphabet);
    }

    printf("Enter NFA transition table:\n");
    for (int i = 0; i < number_of_states; i++)
    {
        for (int j = 0; j < number_of_alphabets; j++)
        {
            scanf("%s", transition_table[i][j]);
        }
    }

    printf("Enter start state: ");
    scanf("%s", start_state);
}

void print_output()
{
    printf("States are: ");
    for (int i = 0; i < MAX_STATES; i++)
    {
        if (states[i][0] == '\0')
            break;
        printf("%s ", states[i]);
    }
    printf("\n");

    printf("Alphabets are: ");
    for (int i = 0; i < MAX_SYMBOLS; i++)
    {
        if (alphabets[i][0] == '\0')
            break;
        printf("%s ", alphabets[i]);
    }
    printf("\n");

    printf("Transition table is:\n");
    for (int i = 0; i < MAX_STATES; i++)
    {
        if (states[i][0] == '\0')
            break;
        printf("%s: ", states[i]);
        for (int j = 0; j < MAX_SYMBOLS; j++)
        {
            if (alphabets[j][0] == '\0')
                break;
            printf("%s ", transition_table[i][j]);
        }
        printf("\n");
    }
    printf("Start state: %s\n", start_state);
}

int isCompleted(char *state)
{
    for (int i = 0; i < MAX_STATES; i++)
    {
        if (strcmp(completed[i], state) == 0)
            return 1;
        if (completed[i][0] == '\0')
            break;
    }
    return 0; // the state has not been created yet.
}

char *fetch(char c, int alphabet)
{
    char s[2] = {c, '\0'};
    for (int i = 0; i < MAX_STATES; i++)
    {
        if (strcmp(states[i], s) == 0)
        {
            return transition_table[i][alphabet];
        }
        if (states[i][0] == '\0')
            break;
    }
    return NULL;
}

void unite(char store_state[MAX_STATES][10], int store_state_size, char *new_state)
{
    // Splitting all combined states into characters
    int split_s[MAX_STATES] = {0};
    for (int i = 0; i < store_state_size; i++)
    {
        if (store_state[i][0] == '\0')
            continue;
        for (int j = 0; store_state[i][j] != '\0'; j++)
        {
            split_s[store_state[i][j] - 'A'] = 1;
        }
    }

    // Building the new state
    int idx = 0;
    for (int i = 0; i < MAX_STATES; i++)
    {
        if (split_s[i] == 1)
        {
            new_state[idx++] = 'A' + i;
        }
    }
    new_state[idx] = '\0';
}

void create_state_transitions(char *state)
{
    if (isCompleted(state))
        return;

    char dfa_row[MAX_SYMBOLS][10];
    for (int a = 0; a < MAX_SYMBOLS; a++)
    {
        char store_state[MAX_STATES][10];
        int store_state_size = 0;
        for (int w = 0; state[w] != '\0'; w++)
        {
            strcpy(store_state[store_state_size], fetch(state[w], a));
            store_state_size++;
        }
        char new_state[MAX_STATES];
        unite(store_state, store_state_size, new_state);
        strcpy(dfa_row[a], new_state);
    }

    for (int i = 0; i < MAX_STATES; i++)
    {
        if (completed[i][0] == '\0')
        {
            strcpy(completed[i], state);
            break;
        }
    }

    // Now recursively call new states
    for (int i = 0; i < MAX_SYMBOLS; i++)
    {
        if (dfa_row[i][0] != '\0' && strcmp(dfa_row[i], "NULL") != 0)
        {
            create_state_transitions(dfa_row[i]);
        }
    }
}

void print_dfa()
{
    printf("DFA transition table:\n");
    for (int i = 0; i < MAX_STATES; i++)
    {
        if (dfa_table[i][0][0] == '\0')
            break;
        printf("%s: ", dfa_table[i][0]);
        for (int j = 0; j < MAX_SYMBOLS; j++)
        {
            if (dfa_table[i][j + 1][0] == '\0')
                break;
            printf("%s ", dfa_table[i][j + 1]);
        }
        printf("\n");
    }
    printf("\n");
}
