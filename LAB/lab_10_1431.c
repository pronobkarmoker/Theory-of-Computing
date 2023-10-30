#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leftMost(char str[]);

int main()
{
    char input[1000];
    printf("Enter a string: ");
    scanf("%s", input);

    printf("Leftmost derivation: ");
    leftMost(input);
    return 0;
}

void leftMost(char str[])
{
    char ans[1000];
    int i = 0;
    int rotation = 0;
    char *p = str;
    int flag = 0;
    printf("A1B => ");
    while (*p)
    {
        i = rotation;
        ans[i + 1] = '\0';
        if (*p == '0' && !flag)
        {
            ans[i++] = '0';
            strcat(ans, "A1B => ");
            p++;
        }
        else if (*p == '1' && !flag)
        {
            ans[i++] = '1';
            strcat(ans, "B => ");
            flag++; 
            p++;
        }
        else if (flag)
        {
            ans[i++] = *p;
            strcat(ans, "B => ");
            p++;
        }
        rotation++;
        printf("%s", ans);
    }
    printf("%s\n", str);
}
