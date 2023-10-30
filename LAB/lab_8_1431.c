#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void division(char *, int, char);
bool isLanguage(char *, char *, char *, int, char);

int main()
{
    char choice;
    int n;
    char w[100];
    printf("Which Language do you choose?\n\n");
    printf("a) 0^n 1^n.\n");
    printf("b) 0^n 1^2n.\n\nchoose : ");

    scanf("%c", &choice);
    getchar();

    printf("\nPlease enter the value of n : ");
    scanf("%d", &n);
    getchar();
    printf("\n");

    if (choice == 'a')
    {
        for (int i = 0; i < n; i++)
        {
            w[i] = '0';
            w[n + i] = '1';
        }
        w[2 * n] = '\0';
    }
    else if (choice == 'b')
    {
        for (int i = 0; i < 3 * n; i++)
        {
            if (i < n)
            {
                w[i] = '0';
            }
            else if (i >= n && i < 3 * n)
            {
                w[i] = '1';
            }
            w[3 * n] = '\0';
        }
    }
    printf("w = %s\n\n", w);
    division(w, strlen(w), choice);
    return 0;
}

void division(char *w, int n, char choice)
{
    srand(time(NULL));
    int sizeOfX = rand() % (n - 2) + 1; //|xy| <= n && |y| >= 1;
    int maxSizeOfY = n - sizeOfX;
    int sizeOfY = rand() % maxSizeOfY + 1;

    // printf("x[%d],y[%d],z[%d]\n",sizeOfX,sizeOfY,n-sizeOfX-sizeOfY);

    char *x;
    char *y;
    char *z;

    x = malloc(sizeof(char) * (sizeOfX + 1));
    y = malloc(sizeof(char) * (sizeOfY + 1));
    z = malloc(sizeof(char) * (n - sizeOfX - sizeOfY + 1));

    // loading of x y and z
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < n; i++)
    {
        if (i < sizeOfX)
        {
            x[i] = w[i];
        }
        else if (j < sizeOfY)
        {
            y[j++] = w[i];
        }
        else
        {
            z[k++] = w[i];
        }
    }
    x[sizeOfX] = '\0';
    y[j] = '\0';
    z[k] = '\0';
    printf("x = %s >> y = %s >> z = %s\n\n", x, y, z);

    if (isLanguage(x, y, z, n, choice))
    {
        printf("Not sure if regular or not! (passed pumping lemma test)\n\n");
    }
    else
    {
        printf("Not regular! (failed pumping lemma test)\n\n");
    }
}

bool isLanguage(char *x, char *y, char *z, int n, char choice)
{
    for (int i = 1; i <= n; i++)
    {
        char xyz[100];
        char yy[100] = "";
        int numOf1 = 0;
        int numOf0 = 0;

        for (int j = 0; j <= i; j++)
        {
            strcat(yy, y);
        }

        sprintf(xyz, "%s%s%s", x, yy, z);

        bool flag = false;

        for (int i = 0; i < strlen(xyz); i++)
        {
            if (xyz[i] == '0' && !flag)
            {
                numOf0++;
            }
            else if (xyz[i] == '1')
            {
                flag = true;
                numOf1++;
            }
        }

        printf("After pumping :\nNumber of 0's : %d && Number of 1's : %d\n\n", numOf0, numOf1);

        if (choice == 'a' && numOf0 != numOf1)
        {
            printf("%s is not a language of the regular expression : 0^n 1^n\n\n", xyz);
            return false;
        }
        else if (choice == 'b' && numOf1 != 2 * numOf0)
        {
            printf("%s is not a language of the regular expression : 0^n 1^2n\n\n", xyz);
            return false;
        }
    }
    return true; // sadly
}