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

int main()
{
    char arr[] = {'0', '1'};

    for (int j = 0; j < 5; j++)
    {

        int lent = rand() % 10 + 2;
        char str[lent];

        for (int i = 0; i < lent; i++)
        {
            str[i] = '0';
            int index = rand() % 2;
            str[i] = arr[index];
        }

        str[lent] = '\0';
        printf("%s\n", str);
        printf("Length of this string is : %d\n\n", length(str));
    }

    return 0;
}