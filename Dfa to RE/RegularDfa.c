#include <stdio.h>
#include <stdlib.h>

int main()
{
    char transition[3][2];
    char alphabet[2] = {'0', '1'};
    freopen("input.txt", "r", stdin);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%c", &transition[i][j]);
        }
        getchar(); 
    }

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
            int temp = transition[j][k] - '0';
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