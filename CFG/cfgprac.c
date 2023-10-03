#include <stdio.h>
#include <string.h>


int deriveString(char *input, int start, int end) {
    if (start == end) {
        printf("%c", input[start]);
        return 1; 
    }

    int isPalindrome = 0;

    if ((input[start] == '0' && input[end] == '0') || (input[start] == '1' && input[end] == '1')) {
        isPalindrome = deriveString(input, start + 1, end - 1);
    }

    if (isPalindrome) {
        printf("%c", input[start]);
    }

    return isPalindrome; 
}

int main() {
    char input1[] = "101";
    char input2[] = "10101";

    printf("Input: %s\n", input1);
    printf("Output: ");
    if (deriveString(input1, 0, strlen(input1) - 1)) {
        printf(" => %s\n", input1);
        printf("In this grammar\n\n");
    } else {
        printf(" => Not in this grammar\n");
    }

    printf("\nInput: %s\n", input2);
    printf("Output: ");
    if (deriveString(input2, 0, strlen(input2) - 1)) {
        printf(" => %s\n", input2);
        printf("In this grammar\n\n");
    } else {
        printf(" => Not in this grammar\n");
    }

    return 0;
}
