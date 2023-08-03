#include <stdio.h>
#include <stdlib.h>

int get_state_index(char state, char set_state[], int num_states) {
    for (int i = 0; i < num_states; i++) {
        if (set_state[i] == state) {
            return i;
        }
    }
    return -1; // State not found
}

int main()
{
    int alpha, state, transition;

    printf("Enter no of alphabet, state, and transition:");
    scanf("%d ", &alpha);
    scanf("%d ", &state);
    scanf("%d ", &transition);

    char set_state[state], set_alphabet[alpha];
    for (int i = 0; i < state; i++)
    {
        printf("Enter state:");
        scanf(" %c", &set_state[i]);
        getchar();
    }
    for (int i = 0; i < alpha; i++)
    {
        printf("Enter alphabet:");
        scanf(" %c", &set_alphabet[i]);
        getchar();
    }

    char matrix[state][alpha];

    for (int i = 0; i < state; i++)
    {
        printf("State %c:\n", set_state[i]);
        for (int j = 0; j < alpha; j++)
        {
            printf("If %c then:", set_alphabet[j]);
            scanf(" %c", &matrix[i][j]);
        }
    }

    char str[50], start, end;

    printf("Enter string:");
    scanf("%s", str);
    printf("Enter starting state:");
    scanf(" %c", &start);
    printf("Enter finishing state:");
    scanf(" %c", &end);

    int i = 0;
    char curr = start;
    while (str[i] != '\0')
    {
        int r = get_state_index(curr, set_state, state);
        printf("%c - ", curr);
        int c = str[i];
        int alphabet_index = -1;
        for (int j = 0; j < alpha; j++)
        {
            if (set_alphabet[j] == c)
            {
                alphabet_index = j;
                break;
            }
        }
        if (alphabet_index == -1)
        {
            printf("Invalid input character '%c'\n", c);
            return 1;
        }
        curr = matrix[r][alphabet_index];
        i++;
    }

    printf("%c - ", curr);
    if (curr == end)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}