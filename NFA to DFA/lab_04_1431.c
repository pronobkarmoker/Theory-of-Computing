#include <stdio.h>
#include <string.h>
#include <math.h>

#define STATES 100
#define SYMBOLS 2

int ninputs;
int dfa[STATES][SYMBOLS][STATES] = {0};
int state[STATES] = {0};
char ch[10], str[1000];
int go[STATES][SYMBOLS] = {0};
int arr[STATES] = {0};

int main() {
    int st, fin, in;
    int f[10];
    int i, j = 3, s = 0, final = 0, flag = 0, curr1, curr2, k, l;
    int c;

    printf("\nFollow the one-based indexing\n");

    printf("\nEnter the number of states: ");
    scanf("%d", &st);

    printf("\nGive state numbers from 0 to %d", st - 1);

    for (i = 0; i < st; i++)
        state[(int)(pow(2, i))] = 1;

    printf("\nEnter number of final states: ");
    scanf("%d", &fin);

    printf("\nEnter final states: ");
    for (i = 0; i < fin; i++) {
        scanf("%d", &f[i]);
    }

    int p, q, r, rel;

    printf("\nEnter the number of rules according to NFA: ");
    scanf("%d", &rel);

    printf("\nDefine transition rule as \"initial state input symbol final state\"\n");

    for (i = 0; i < rel; i++) {
        scanf("%d%d%d", &p, &q, &r);
        dfa[p][q][r] = 1;
    }

    printf("\nEnter initial state: ");
    scanf("%d", &in);

    in = pow(2, in);

    printf("\nSolving according to DFA\n");

    int x = 0;
    for (i = 0; i < st; i++) {
        for (j = 0; j < SYMBOLS; j++) {
            int stf = 0;
            for (k = 0; k < st; k++) {
                if (dfa[i][j][k] == 1)
                    stf = stf + pow(2, k);
            }
            go[(int)(pow(2, i))][j] = stf;
            printf("%d-%d-->%d\n", (int)(pow(2, i)), j, stf);
            if (state[stf] == 0)
                arr[x++] = stf;
            state[stf] = 1;
        }
    }

    // For new states
    for (i = 0; i < x; i++) {
        printf("for %d ---- ", arr[x]);
        for (j = 0; j < SYMBOLS; j++) {
            int new = 0;
            for (k = 0; k < st; k++) {
                if (arr[i] & (1 << k)) {
                    int h = pow(2, k);

                    if (new == 0)
                        new = go[h][j];
                    new = new | (go[h][j]);
                }
            }

            if (state[new] == 0) {
                arr[x++] = new;
                state[new] = 1;
            }
        }
    }

    printf("\nThe total number of distinct states are:\n");

    printf("STATE ");
    for (i = 0; i < SYMBOLS; i++)
        printf("%d ", i);
    printf("\n");

    for (i = 0; i < STATES; i++) {
        if (state[i] == 1) {
            printf("q%d   ", i);
            for (j = 0; j < SYMBOLS; j++) {
                printf("%d   ", go[i][j]);
            }
            printf("\n");
        }
    }

    j = 3;
    while (j--) {
        printf("\nEnter string: ");
        scanf("%s", str);
        l = strlen(str);
        curr1 = in;
        flag = 0;
        printf("\nString takes the following path-->\n");
        printf("%d-", curr1);

        for (i = 0; i < l; i++) {
            curr1 = go[curr1][str[i] - '0'];
            printf("%d-", curr1);
        }

        printf("\nFinal state - %d\n", curr1);

        for (i = 0; i < fin; i++) {
            if (curr1 & (1 << f[i])) {
                flag = 1;
                break;
            }
        }

        if (flag)
            printf("\nString Accepted");
        else
            printf("\nString Rejected");
    }

    return 0;
}

