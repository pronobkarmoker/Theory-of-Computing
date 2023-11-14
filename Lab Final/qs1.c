#include <stdio.h>
#include<string.h>

int main()
{
    int state = 3;
    printf("enter number of state :\n");
    scanf("%d", &state);
    int alpha;
    printf("Enter the number of alpha:");
    scanf("%d", &alpha);
   
    char Alpha[alpha];
    printf("Enter the alphabet \n");
    scanf("%s", Alpha);

  
    printf("enter the table value: \n");
    int transation_table[state][alpha];
    for (int i = 0; i < state; i++)
    {
        for (int j = 0; j < alpha; j++)
        {
            scanf("%d", &transation_table[i][j]);
        }
    }
    

    int start, end;
    printf("Enter starting state\n");
    scanf("%d", &start);
    printf("Enter ending state\n");
    scanf("%d", &end);

    char string[100];
    printf("Enter string : \n");
    scanf("%s", &string);

    int current = start;
    // printf("%d ->", current);

    for (int i = 0; string[i] != '\0'; i++)
    {
        printf("%d ->", current);
        current = transation_table[current][string[i] - 48];
    }
    printf("%d ", current);

    if (current == end)
    {
        printf("\n");
        printf("Accepted");
        printf("\n");
    }
    else
    {
        printf("Rejected");
        printf("\n");
    }

    return 0;
}