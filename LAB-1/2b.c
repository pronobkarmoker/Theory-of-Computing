#include <stdio.h>

int length(char str[])
{
    int i = 0;
    for (;; i++)
    {
        if (str[i] == '\0')
        {
            break;
        }
    }
    return i;
}

int isPalindrome(char *w)
{
    int l = length(w);
    for (int i = 0; i < l / 2; i++)
    {
        if (w[i] != w[l - i - 1])
        {
            return 0;
        }

        return 1;
    }
}

int main()
{
    char w[20];
    printf("enter a string \n");
    gets(w);

    if (isPalindrome(w))
    {
        printf("palindrome");
    }
    else
    {
        printf("not palindrome");
    }

    return 0;
}