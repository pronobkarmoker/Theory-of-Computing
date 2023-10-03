#include <stdio.h>
#include <string.h>


void deriveString(const char *input, int start, int end) {
    if (start == end) {
        printf("%c", input[start]);
    } else if (start < end) {
        printf("%c => ", input[start]);
        deriveString(input, start + 1, end - 1);
        printf("%c", input[start]);
    }
}

int main() {
    const char *input1 = "101";
    const char *input2 = "10101";
    const char *input3 = "101010";

    printf("Input: %s\n", input1);
    printf("P => %c", input1[0]);
    deriveString(input1, 1, strlen(input1) - 2);
    printf("%c => %s\n", input1[strlen(input1) - 1], input1);
    printf("In this grammar\n\n");

    printf("Input: %s\n", input2);
    printf("P => %c", input2[0]);
    deriveString(input2, 1, strlen(input2) - 2);
    printf("%c => %s\n", input2[strlen(input2) - 1], input2);
    printf("In this grammar\n\n");

    printf("Input: %s\n", input3);
    printf("Not in this grammar\n");

    return 0;
}
