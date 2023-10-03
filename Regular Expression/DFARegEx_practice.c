#include <stdio.h>

int main()
{

    int state = 3;
    printf("enter number of state :\n");
    scanf("%d", &state);
    int alpha;
    printf("Enter the number of alpha:");
    scanf("%d", &alpha);
    // char alpha[2]={'0','1'};
    char Alpha[alpha];
    printf("Enter the alphabet \n");
    scanf("%s", Alpha);

    // int transation_table[3][2]={{1,0},{2,0},{2,0}};
    printf("enter the table value: \n");
    int transation_table[state][alpha];
    for (int i = 0; i < state; i++)
    {
        for (int j = 0; j < alpha; j++)
        {
            scanf("%d", &transation_table[i][j]);
        }
    }
    // int start = 0;
    // int end = 2;

    int start, end;
    printf("Enter starting state\n");
    scanf("%d", &start);
    printf("Enter ending state\n");
    scanf("%d", &end);

    typedef struct
    {
        int data[4];
    } State;

    State v;

    for (int j = 0; j < 3; j++)
    {
        for (int s = 0; s < 4; s++)
        {
            v.data[s] = -1;
        }

        for (int k = 0; k < 2; k++)
        {
            int temp = transation_table[j][k] - '0';
            v.data[temp] = k;
        }

        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        printf("R(%d,%d,%d): ", i + 1, 1, 0);
        if (v.data[i] != -1)
        {
            printf("eps+%d\n", v.data[i]);
        }
        else
        {
            printf("eps\n");
        }

        for (int j = 1; j < 4; j++)
        {
            printf("R(%d,%d,%d): ", i + 1, j, 0);
            if (v.data[j] != -1)
            {
                printf("%d\n", v.data[j]);
            }
            else
            {
                printf("eps\n");
            }
        }

        printf("\n");
    }

    return 0;
}