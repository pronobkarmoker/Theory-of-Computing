#include <string.h>

typedef struct NFA {
    int delta[10][2][10];
    int no_of_transitions[10][2];
    int nos;
    int start_state;
    int final_states[10];
    int nof;
} NFA;

int main() {
    NFA nfa;
    printf("Enter the number of states: ");
    scanf("%d", &nfa.nos);
    printf("Enter the start state: ");
    scanf("%d", &nfa.start_state);
    printf("Enter the number of final states: ");
    scanf("%d", &nfa.nof);
    for (int i = 0; i < nfa.nof; i++) {
        printf("Enter final state no %d: ", i + 1);
        scanf("%d", &nfa.final_states[i]);
    }
    
    
    for(int i = 0; i < nfa.nos; i++) {
        for(int j = 0; j < 2; j++) {
            printf("Enter number of transitions for state q%d on input %d: ", i, j);
            scanf("%d", &nfa.no_of_transitions[i][j]);
            for(int k = 0; k < nfa.no_of_transitions[i][j]; k++) {
                printf("Enter next state for transition %d: ", k + 1);
                scanf("%d", &nfa.delta[i][j][k]);
            }
        }
    }

    char input_string[100];
    printf("Enter the input string (only 0's and 1's): ");
    scanf("%s", input_string);
    int states[10] = {0};
    states[nfa.start_state] = 1;
    int newStates[10];
    char path[1000] = "";

    for(int i = 0; i < strlen(input_string); i++) {
        int sym = input_string[i] - '0';
        if(sym < 0 || sym > 1) {
            printf("Rejected\n");
            return 0;
        }

        memset(newStates, 0, sizeof(newStates));
        for(int j = 0; j < nfa.nos; j++) {
            if(states[j]) {
                for(int k = 0; k < nfa.no_of_transitions[j][sym]; k++) {
                    int next = nfa.delta[j][sym][k];
                    newStates[next] = 1;
                    char transition[50];
                    sprintf(transition, "q%d -(%d)-> q%d\n", j, sym, next);
                    strcat(path, transition);
                }
            }
        }
        memcpy(states, newStates, sizeof(newStates));
    }

    int accepted = 0;
    for(int i = 0; i < nfa.nof; i++) {
        if(states[nfa.final_states[i]]) {
            accepted = 1;
            break;
        }
    }

    if(accepted) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    printf("Path of transition:\n%s", path);

    return 0;
} 