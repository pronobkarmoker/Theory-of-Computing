#include <stdio.h>
#include <stdbool.h>

int get_state_index(char state, char set_state[], int num_states)
{
    for (int i = 0; i < num_states; i++)
    {
        if (set_state[i] == state)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int alpha, state, transition;
    char str[50], start, end;

    printf("Enter no of alphabet, state, and transition:");
    scanf("%d %d %d", &alpha, &state, &transition);

    char matrix[state][alpha], set_state[state], set_alphabet[alpha];

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

    for (int i = 0; i < state; i++)
    {
        printf("State %c:\n", set_state[i]);
        for (int j = 0; j < alpha; j++)
        {
            printf("If %c -?:", set_alphabet[j]);
            scanf(" %c", &matrix[i][j]);
        }
    }

    printf("HOw many strings you want to cheack: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter string:");
        scanf("%s", str);
        printf("Enter starting state:");
        scanf(" %c", &start);
        printf("Enter finishing state:");
        scanf(" %c", &end);

        int i = 0;
        char cur = start;
        while (str[i] != '\0')
        {
            int r = get_state_index(cur, set_state, state);
            printf("%c - ", cur);
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
                printf("Invalid character '%c'\n", c);
                return 1;
            }
            cur = matrix[r][alphabet_index];
            i++;
        }
        printf("%c - ", cur);
        if (cur == end)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}
