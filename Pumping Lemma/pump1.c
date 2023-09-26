#include <stdio.h>
#include <string.h>


void pumpString(char *str, char *x, char *y, char *z, int k) {
    strcpy(str, x);
    for (int i = 0; i < k; i++) {
        strcat(str, y);
    }
    strcat(str, z);
}


int isInLanguageA(char *str) {
    int n = strlen(str) / 2;
    for (int i = 0; i < n; i++) {
        if (str[i] != '0' || str[i + n] != '1') {
            return 0; 
        }
    }
    return 1; 
}


int isInLanguageB(char *str) {
    int n = strlen(str) / 3;
    for (int i = 0; i < n; i++) {
        if (str[i] != '0' || str[i + 2 * n] != '1' || str[i + n] != '1') {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    char input[100];
    printf("Enter input string in the format '0^n1^n' or '0^n1^2n': ");
    scanf("%s", input);

    int len = strlen(input);
    int n = len / 2; 

    
    char pumpedStringA[100];
    pumpString(pumpedStringA, "0", "1", "", n);

    if (!isInLanguageA(pumpedStringA)) {
        printf("Language A is not regular.\n");
        return 0;
    }

    
    char pumpedStringB[100];
    pumpString(pumpedStringB, "0", "1", "1", n);

    if (!isInLanguageB(pumpedStringB)) {
        printf("Language B is not regular.\n");
        return 0;
    }

    printf("YESSSSSSSSSS regular.\n");

    return 0;
}
