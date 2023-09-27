#include <stdio.h>
#include <string.h>

void cfg(const char *in) {
    int len = strlen(in);
    int i = 0, j = len - 1;
    int flag = 1;

    while (i < j) {
        if (in[i] != in[j]) {
            flag = 0;
            break;
        }
        i++;
        j--;
    }

        // printf("%d", flag);
    if (flag) {
        printf("P");
        for (i = 0; i < len; i++) {
            if (in[i] == '0') {
                printf(" => 0P0");
            } else if (in[i] == '1') {
                printf(" => 1P1");
            }
        }
        printf(" => %s\n", in);
        printf("In this grammar\n\n");
    } else {
        printf("Not in this grammar\n");
    }
}

int main() {
    const char *in1 = "101";
    const char *in2 = "10101";
    const char *in3 = "101010";

    printf("Input: %s\n", in1);
    cfg(in1);

    printf("\nInput: %s\n", in2);
    cfg(in2);

    printf("\nInput: %s\n", in3);
    cfg(in3);

    return 0;
}
