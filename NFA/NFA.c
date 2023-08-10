#include <stdio.h>
#include <string.h>

#define MAX_STATES 100
#define MAX_SYMBOLS 10

int nfaTraversal(int trans[MAX_STATES][MAX_SYMBOLS][MAX_STATES], int a, int state, char *input, int pos, int endState) {
   if (input[pos] == '\0') {
        if (state == endState) {
            //printf("%d ", state);
            //printf("\nAccepted.\n");
            return 1;
        } else {
            //printf("%d ", state);
            //printf("\nRejected.\n");
            return 0;
        }
    }

    //printf("%d ", state);
    int alpha = input[pos] - '0';
    int flag = 0;

    for (int i = 0; i < a; i++) {
    if (trans[state][alpha][i] != -1) {
        int result = nfaTraversal(trans, a, trans[state][alpha][i], input, pos + 1, endState);
        if (result != 0) {
            flag = 1;
        }
    }
}

    return flag;
}

int main() {
    int a, b, startState, endState;

    printf("Enter the number of states : ");
    scanf("%d", &a);

    printf("Enter the number of symbols : ");
    scanf("%d", &b);

    char smbl[b];
    printf("Enter the symbols : ");
    scanf("%s", smbl);

    int trans[MAX_STATES][MAX_SYMBOLS][MAX_STATES];
    FILE *fp = fopen("nfa.txt", "r");

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < a; k++) {
                fscanf(fp, "%d", &trans[i][j][k]);
            }
        }
    }
    
    printf("Enter Starting State: ");
    scanf("%d", &startState);
    
    printf("Enter Ending State: ");
    scanf("%d", &endState);

    char str[100];

    while (1) {
        printf("Enter the String to check OR 'E' : ");
        scanf("%s", str);

        if (strcmp(str, "E") == 0) {
            break;
        }

        if (nfaTraversal(trans, a, startState, str, 0, endState)) {
            printf(" accepted.\n");
        } else {
            printf(" rejected.\n");
        }
    }

    return 0;
}

