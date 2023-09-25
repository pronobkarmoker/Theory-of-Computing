#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,ac;
    int state,symbol;
    freopen("input.txt","r",stdin);

    cout<<"Enter number of state:\n";
    cin>>state;
    cout<<"Enter the states:\n";
    int states[state];
    for(i=0; i<state; i++)
    {
        cin>>states[i];
    }
    cout<<"Enter number of input symbols:\n";
    cin>>symbol;
    cout<<"Enter input symbols:\n";
    string symbols[symbol];
    for(i=0; i<symbol; i++)
    {
        cin>>symbols[i];
    }
    cout<<"Enter Accepting State:";
    cin>>ac;
    int transtable[state+1][symbol];
    cout<<"Enter transition table:\n";

    for(i=1; i<=state; i++)
    {
        for(j=0; j<symbol; j++)
        {
            cin>>transtable[i][j];
        }
    }

    int table[state+1][state+1]={0};

    for(int row=1;row<=state;row++){
        for(int col=1;col<=state;col++){
            if(row==ac && col<ac){
                table[row][col]=-1;
            }
            if(row>ac && col==ac){
                table[row][col]=-1;
            }
            if(row==col) table[row][col]=1;

        }
    }

    //first check
    for(int row=2;row<=state;row++){
        int tempState1=transtable[row][0];
        int tempState2=transtable[row][1];

        for(int col=1;col<state;col++){
            if(table[col][row]==-1 || table[row][col]==-1 || table[col][row]==1 || table[row][col]==1){
                continue;
            }

            int tempState3=transtable[col][0];
            int tempState4=transtable[col][1];

            if(tempState1==ac && ac==tempState3){

                table[col][row]=1;
                table[row][col]=1;
            }else if(tempState2==ac && ac==tempState4){
                table[col][row]=1;
                table[row][col]=1;
            }else if(tempState1==ac && tempState3!=ac){
                table[col][row]=-1;
                table[row][col]=-1;
            }else if(tempState2==ac && tempState4!=ac){
                table[col][row]=-1;
                table[row][col]=-1;
            }else if(tempState1!=ac && tempState3==ac){
                table[col][row]=-1;
                table[row][col]=-1;
            }else if(tempState2!=ac && tempState4==ac){
                table[col][row]=-1;
                table[row][col]=-1;
            }

        }
    }

    //second check
    for(int row=2;row<=state;row++){
        int tempState1=transtable[row][0];
        int tempState2=transtable[tempState1][0];

        int tempState3=transtable[row][0];
        int tempState4=transtable[tempState3][1];

        int tempState5=transtable[row][1];
        int tempState6=transtable[tempState5][0];

        int tempState7=transtable[row][1];
        int tempState8=transtable[tempState7][1];



        for(int col=1;col<state;col++){
            if(table[col][row]==-1 || table[row][col]==-1 || table[col][row]==1 || table[row][col]==1){
                continue;
            }

            int tempState9=transtable[col][0];
            int tempState10=transtable[tempState9][0];

            int tempState11=transtable[col][0];
            int tempState12=transtable[tempState11][1];

            int tempState13=transtable[col][1];
            int tempState14=transtable[tempState13][0];

            int tempState15=transtable[col][1];
            int tempState16=transtable[tempState15][1];

            if(tempState2==ac && tempState10==ac){
                table[col][row]=1;
                table[row][col]=1;
            }else if(tempState6==ac && tempState14==ac){
                table[col][row]=1;
                table[row][col]=1;
            }else if(tempState4==ac && tempState12==ac){
                table[col][row]=1;
                table[row][col]=1;
            }else if(tempState8==ac && tempState16==ac){
                table[col][row]=1;
                table[row][col]=1;
            }

        }
    }

    //third check
    for(int row=2;row<=state;row++){
        int tempState1=transtable[row][0];
        int tempState2=transtable[tempState1][0];
        int tempState3=transtable[tempState2][0];

        int tempState4=transtable[row][0];
        int tempState5=transtable[tempState4][0];
        int tempState6=transtable[tempState5][1];

        int tempState7=transtable[row][0];
        int tempState8=transtable[tempState7][1];
        int tempState9=transtable[tempState8][0];

        int tempState10=transtable[row][0];
        int tempState11=transtable[tempState10][1];
        int tempState12=transtable[tempState11][1];

        int tempState13=transtable[row][1];
        int tempState14=transtable[tempState13][1];
        int tempState15=transtable[tempState14][1];

        int tempState16=transtable[row][1];
        int tempState17=transtable[tempState16][1];
        int tempState18=transtable[tempState17][0];

        int tempState19=transtable[row][1];
        int tempState20=transtable[tempState19][0];
        int tempState21=transtable[tempState20][1];

        int tempState22=transtable[row][1];
        int tempState23=transtable[tempState22][0];
        int tempState24=transtable[tempState23][0];

        for(int col=1;col<state;col++){
            if(table[col][row]==-1 || table[row][col]==-1 || table[col][row]==1 || table[row][col]==1){
                continue;
            }

            int tempState25=transtable[col][0];
            int tempState26=transtable[tempState25][0];
            int tempState27=transtable[tempState26][0];

            int tempState28=transtable[col][0];
            int tempState29=transtable[tempState28][0];
            int tempState30=transtable[tempState29][1];

            int tempState31=transtable[col][0];
            int tempState32=transtable[tempState31][1];
            int tempState33=transtable[tempState32][0];

            int tempState34=transtable[col][0];
            int tempState35=transtable[tempState34][1];
            int tempState36=transtable[tempState35][1];

            int tempState37=transtable[col][1];
            int tempState38=transtable[tempState37][1];
            int tempState39=transtable[tempState38][1];

            int tempState40=transtable[col][1];
            int tempState41=transtable[tempState40][1];
            int tempState42=transtable[tempState41][0];

            int tempState43=transtable[col][1];
            int tempState44=transtable[tempState43][0];
            int tempState45=transtable[tempState44][1];

            int tempState46=transtable[col][1];
            int tempState47=transtable[tempState46][0];
            int tempState48=transtable[tempState47][0];

            if(tempState3==ac && tempState27==ac){
                table[col][row]=1;
                table[row][col]=1;
            }else if(tempState6==ac && tempState30==ac){
                table[col][row]=1;
                table[row][col]=1;
            }else if(tempState9==ac && tempState33==ac){
                table[col][row]=1;
                table[row][col]=1;
            }else if(tempState12==ac && tempState36==ac){
                table[col][row]=1;
                table[row][col]=1;
            }else if(tempState15==ac && tempState39==ac){
                table[col][row]=1;
                table[row][col]=1;
            }else if(tempState18==ac && tempState42==ac){
                table[col][row]=1;
                table[row][col]=1;
            }else if(tempState21==ac && tempState45==ac){
                table[col][row]=1;
                table[row][col]=1;
            }else if(tempState24==ac && tempState48==ac){
                table[col][row]=1;
                table[row][col]=1;
            }else{
                table[col][row]=-1;
                table[row][col]=-1;
            }

        }
    }


    //print
    cout<<"\t";
    for(i=0;i<state;i++) printf(" %c\t",65+i);
    cout<<endl<<endl;
    i=0;
    for(int row=1;row<=state;row++){
        printf(" %c\t",65+i);
        i++;
        for(int col=1;col<=state;col++){
            if(col<=row) {
               if(table[row][col]!=-1) cout<<" "<<table[row][col]<<"\t";
               else cout<<table[row][col]<<"\t";
            }
        }
        cout<<endl;
    }
    cout<<endl;

    vector<int>eq1,eq2;
    cout<<"Equivalent States: ";
    for(int row=1;row<=state;row++){
        for(int col=1;col<=state;col++){
            if(col<row) {
               if(table[row][col]==1){
                printf("{%c = %c} ",64+row,64+col);
                eq1.push_back(row);
                eq2.push_back(col);
               }
            }
        }
    }
    cout<<endl;

    //ii

    j=0;
    for(j=0;j<eq1.size();j++)
    for(i=1; i<=state; i++)
    {   
        int temp=eq1[j];
        for(k=0; k<symbol; k++){
            if(transtable[i][k]==temp){
                transtable[i][k]=eq2[j];
                
            }
        }

        
    }
    int newTransTable[state+1][symbol]={0};
    k=0;
    for(i=1;i<=state;i++){
        int temp;
        if(k<eq1.size()) temp=eq1[k];
        if(temp==i){
            k++;
            continue;
        }
        for(j=0;j<symbol;j++){
            newTransTable[i][j]=transtable[i][j];
        }
    }
    cout<<"New Transition Table:"<<endl;
    for(i=1; i<=state; i++){
        for(j=0; j<symbol; j++){
           if(newTransTable[i][j]!=0) cout<<newTransTable[i][j]<<" ";
        }
        if(newTransTable[i][j]!=0)cout<<endl;
    }

    cout<<endl;


}