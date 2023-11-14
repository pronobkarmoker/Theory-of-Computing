
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int nos;//number of states
    int delta[10][2];//transition table
    int start;
    int nof;//number of final states
    bool end[10];//if the state is final then true;
}DFA;

DFA init_dfa();
int** myhillNerode(DFA);
DFA mdfa(DFA,int**);

int main(){
    DFA dfa = init_dfa();
    printf("dfa transition table:\n");
    printf("d  A(0) A(1)\n");
    for(int i = 0; i < dfa.nos; i++){
        printf("q%d ",i);
        for(int j = 0; j < 2; j++){
            printf("%d   ",dfa.delta[i][j]);
        }
        printf("\n");
    }
    printf("Starting state: %d\n",dfa.start);
    printf("Ending states: ");
    for(int i = 0; i < dfa.nos; i++){
        if(dfa.end[i]){
            printf("%d, ",i);
        }
    }
    printf("\n");
    int **table = myhillNerode(dfa);
    printf("\n\nhere is the myhill table:\n");
    for(int i = 0; i < dfa.nos; i++){
        for(int j = 0; j < i; j++){
            printf("%s  ",(table[i][j]==1) ? "T ":"F ");
        }
        printf("\n");
    }
    //here starts minimized dfa calculation. 
    DFA mDFA = mdfa(dfa,table);
    printf("\n\ntransition table of minimized dfa:\n   a(0) a(1)\n");
    for(int i = 0; i < mDFA.nos; i++){
        printf("q%d",i);
        for(int j = 0; j < 2; j++){
            printf("  %d  ",mDFA.delta[i][j]);
        }
        printf("\n");
    }
    printf("\n\nStarting state of minimized dfa: %d\n",mDFA.start);
    printf("\n\nEnding states: ");
    for(int i = 0; i < mDFA.nos; i++){
        if(mDFA.end[i]){
            printf("%d, ",i);
        }
    }
    printf("\n\n\n");
    return 0;
}

DFA init_dfa(){
    DFA dfa;
    // printf("states: ");
    // scanf("%d",&dfa.nos);
    // printf("start: ");
    // scanf("%d",&dfa.start);
    // printf("number of end states: ");
    // scanf("%d",&dfa.nof);
    // printf("end states: ");
    // for(int i = 0; i < dfa.nof; i++){
        // int temp;
    //     scanf("%d",&temp);
    //      getchar();
    //      dfa.end[temp] = true;
    // }
    // printf("Transition table:\n");
    // for(int i = 0; i < dfa.nos; i++){
    //     for(int j = 0; j < 2; j++){
    //         printf("delta(q%d,a%d): ",i,j);
    //         scanf("%d",&dfa.delta[i][j]);
    //     }
    // }
    //the commented part are for custom dfa.
    dfa.nos = 8;
    dfa.start = 0;
    dfa.nof = 1;
    
    dfa.end[3] = true;
    
    dfa.delta[0][0] = 1;
    dfa.delta[0][1] = 0;
    dfa.delta[1][0] = 0;
    dfa.delta[1][1] = 2;
    dfa.delta[2][0] = 3;
    dfa.delta[2][1] = 1;
    dfa.delta[3][0] = 3;
    dfa.delta[3][1] = 0;
    dfa.delta[4][0] = 3;
    dfa.delta[4][1] = 5;
    dfa.delta[5][0] = 6;
    dfa.delta[5][1] = 4;
    dfa.delta[6][0] = 5;
    dfa.delta[6][1] = 6;
    dfa.delta[7][0] = 6;
    dfa.delta[7][1] = 3;
    return dfa;
}

int** myhillNerode(DFA dfa){
    bool changed;
    int **table = (int**)malloc(dfa.nos*sizeof(int*));
    for(int i = 0; i < dfa.nos; i++){
        table[i] = (int*)malloc(dfa.nos*sizeof(int));
        for(int j = 0; j < dfa.nos; j++){
            table[i][j] = 0;
        }
    }
    do {
        changed = false;
        for (int i = 0; i < dfa.nos; i++) {
            for (int j = 0; j < i; j++) {
                if(!table[i][j]){
                    if ((dfa.end[i] && !dfa.end[j]) || (dfa.end[j] && !dfa.end[i])) {
                        table[i][j] = 1;
                        changed = true;
                    }else{
                        for (int k = 0; k < 2; k++) {
                            if (table[dfa.delta[i][k]][dfa.delta[j][k]] == 1) {
                                table[i][j] = 1;
                                changed = true;
                            }
                        }
                    }
                }
            }
        }
    } while (changed);
    return table;
}

DFA mdfa(DFA dfa, int** table){
    DFA mDFA;
    mDFA.nos = 0;
    int stateMap[dfa.nos];
    memset(stateMap,-1,sizeof(stateMap));

    for(int i = 0; i < dfa.nos; i++){
        if(stateMap[i] == -1){
            stateMap[i] = mDFA.nos;
            mDFA.nos++;
            for(int j = i+1; j < dfa.nos; j++){
                if(table[j][i] == 0){
                    stateMap[j] = stateMap[i];
                }
            }
            mDFA.end[stateMap[i]] = dfa.end[i];
        }
    }
    printf("here equivalent states:\n");
    for(int i = 0; i < dfa.nos; i++){
        printf("%d is equal %d\n",i,stateMap[i]);
    }
    printf("\n");
    for(int i = 0; i < dfa.nos; i++){
        for(int j = 0; j < 2; j++){
            mDFA.delta[stateMap[i]][j] = stateMap[dfa.delta[i][j]];
        }
    }
    mDFA.start = stateMap[dfa.start];
    mDFA.nof = 0;
    for(int i = 0; i < mDFA.nos; i++){
        if(mDFA.end[i]){
            mDFA.nof++;
        }
    }
    return mDFA;
}