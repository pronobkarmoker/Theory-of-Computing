#include<stdio.h>

int main(){
    char x[20], y[20], z[20];
    int i =0;
    int j =0;

    printf("enter the first string  \n");
    gets(x);

    printf("enter the second string  \n");
    gets(y);

    while (x[i] !=  '\0')
    {
        i++;
    }
    
    while (y[j] != '\0')
    {
        x[i] = y[j];
        j++;
        i++;
    }
    
    x[i]= '\0';

    printf("concatenated string %s \n", x);

    return 0;
}