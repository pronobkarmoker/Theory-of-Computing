#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char S[] = "A1B";
char A[] = "0A|EPS";
char B[] = "0B|1B|EPS";

void leftMost(char str[]);
void rightMost(char str[], int len);

int main() {
    char input[1000];
    printf("Enter a string: ");
    scanf("%s", input);

    printf("Here is the leftmost derivation: ");
    leftMost(input);

    printf("Here is the rightmost derivation: ");
    rightMost(input, strlen(input));

    return 0;
}

void leftMost(char str[]) {
    char ans[1000];
    int i = 0;
    int rotation = 0;
    char *p = str;
    int flag = 0;
    printf("A1B => ");
    while (*p) {
        i = rotation;
        ans[i + 1] = '\0';
        if (*p == '0' && !flag) {
            ans[i++] = '0';
            strcat(ans, "A1B => ");
            p++;
        } else if (*p == '1' && !flag) {
            ans[i++] = '1';
            strcat(ans, "B => ");
            flag++; // This is to determine the first encounter of '1'.
            p++;
        } else if (flag) {
            ans[i++] = *p;
            strcat(ans, "B => ");
            p++;
        }
        rotation++;
        printf("%s", ans);
    }
    printf("%s\n", str);
}

void rightMost(char str[], int len) {
    char ans[1000];
    int i = len - 1;
    char *p = str + len - 1;
    ans[i] = '\0';
    while (i >= 0) {
        ans[i - 1] = '\0';
        if (*p == '0' && i == len - 1) {
            ans[i--] = '0';
            strcat(ans, "A1B => ");
            p--;
        } else if (*p == '0') {
            ans[i--] = '0';
            strcat(ans, "0B => ");
            p--;
        } else if (*p == '1' && i == len - 1) {
            ans[i--] = '1';
            strcat(ans, "B => ");
            p--;
        } else if (*p == '1') {
            ans[i--] = '1';
            strcat(ans, "1B => ");
            p--;
        }
    }
    printf("%sS\n", ans);
}
