#include <stdio.h>

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

void generateStrings(char* alphabet, int k, char* prefix) {
    if (k == 0) {
        printf("%s\n", prefix);
        return;
    }

    int len = length(alphabet);
    for (int i = 0; i < len; i++) {
        prefix[k - 1] = alphabet[i];
        generateStrings(alphabet, k - 1, prefix);
    }
}

int main() {
    char alphabet[] = "01";
    int k;

    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (k < 0) {
        printf("Error: k should be a non-negative integer.\n");
        return 1;
    }

    char prefix[k + 1];
    prefix[k] = '\0';

    generateStrings(alphabet, k, prefix);

    return 0;
}
