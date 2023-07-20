#include <stdio.h>
#include <stdlib.h>

int length(char str[])
{
    int i = 0;
    for (;; i++)
    {
        if (str[i] == '\0'){
            break;
        }
    }
    return i;
}

int isAlphabet(char *w)
{
    for (int i = 0; i < length(w); i++)
    {
        if (w[i] != '0' && w[i] != '1')
        {
            return 0;
        }
        return 1;
    }
}

int main()
{
    char w[20];

    printf("Enter a string \n");
    scanf("%s", w);

    if (isAlphabet(w))
    {
        printf("alphabet\n");
    }
    else
    {
        printf("not alphabet");
    }

    return 0;
}