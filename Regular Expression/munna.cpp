#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"DFA information: "<<endl;
    int num_of_states,num_of_symbol;
    cout<<"Enter the number of states and number of symbol: ";
    cin>>num_of_states>>num_of_symbol;
    char states[num_of_states];
    int i,j,k;
    cout<<"Enter the states: ";
    for(i=0;i<num_of_states;i++)
    {
        cin>>states[i];
    }
    char start_state;
    cout<<"Enter the start state: ";
    cin>>start_state;
    int num_of_final_state;
    cout<<"Enter the number of final state: ";
    cin>>num_of_final_state;
    char final_states[num_of_final_state];
    cout<<"Enter the final states: ";
    for(i=0;i<num_of_final_state;i++)
    {
        cin>>final_states[i];
    }
    char dfa_transition[num_of_states][num_of_symbol];
    cout<<"Enter the dfa transition table: "<<endl;
    for(i=0;i<num_of_states;i++)
    {
        cout<<"From states "<<states[i]<<endl;
        for(j=0;j<num_of_symbol;j++)
        {
            cout<<" by "<<j<<" : ";
            cin>>dfa_transition[i][j];
            cout<<endl;
        }
    }
    char table_filling[num_of_states][num_of_states];
    char breaking_condition[num_of_states][num_of_states];
    for(i=0;i<num_of_states;i++)
    {
        for(j=0;j<num_of_states;j++)
        {
            table_filling[i][j]='=';
            breaking_condition[i][j]='=';
        }
    }
    for(i=0;i<num_of_final_state;i++)
    {
        for(j=0;j<num_of_states;j++)
        {
            int final_flag=0;
            for(k=0;k<num_of_final_state;k++)
            {
                if(states[j]==final_states[k])
                {
                    final_flag=1;
                }
            }
            if(final_states[i]!=states[j] && final_flag==0)
            {
                table_filling[final_states[i]-'a'][states[j]-'a']='x';
                table_filling[states[j]-'a'][final_states[i]-'a']='x';
                breaking_condition[final_states[i]-'a'][states[j]-'a']='x';
                breaking_condition[states[j]-'a'][final_states[i]-'a']='x';
            }
        }
    }
    while(1)
    {
        for(i=0;i<num_of_states;i++)
        {
            for(j=i+1;j<num_of_states;j++)
            {
                for(k=0;k<num_of_symbol;k++)
                {
                    if(table_filling[i][j]=='=')
                    {
                        table_filling[i][j]=table_filling[dfa_transition[i][k]-'a'][dfa_transition[j][k]-'a'];
                        table_filling[j][i]=table_filling[dfa_transition[i][k]-'a'][dfa_transition[j][k]-'a'];
                    }
                }
            }
        }
        int flag=0;
        for(i=0;i<num_of_states;i++)
        {
            for(j=0;j<num_of_states;j++)
            {
                if(breaking_condition[i][j]!=table_filling[i][j])
                {
                    flag=1;
                }
            }
        }
        if(flag==1)
        {
            for(i=0;i<num_of_states;i++)
            {
                for(j=0;j<num_of_states;j++)
                {
                    breaking_condition[i][j]=table_filling[i][j];
                }
            }
        }
        else if(flag==0)
        {
            break;
        }
    }
    cout<<"  ";
    for(i=0;i<num_of_states;i++)
    {
        cout<<states[i]<<" ";
    }
    cout<<endl;
    for(i=0;i<num_of_states;i++)
    {
        cout<<states[i]<<" ";
        for(j=0;j<num_of_states;j++)
        {
            if(i>=j)
            {
                cout<<table_filling[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    string minimized_dfa_states[num_of_states];
    int index=0;
    int already_added[num_of_states];
    for(i=0;i<num_of_states;i++)
    {
        already_added[i]=0;
    }
    for(j=0;j<num_of_states;j++)
    {
        if(already_added[j]==0)
        {
            for(i=j;i<num_of_states;i++)
            {
                if(table_filling[i][j]=='=')
                {
                    minimized_dfa_states[index]+=states[i];
                    already_added[i]=1;
                }
            }
            index++;
        }
    }
    //cout<<index<<endl;
    cout<<"minimized dfa states are: "<<endl;
    for(i=0;i<index;i++)
    {
        cout<<minimized_dfa_states[i]<<endl;
    }
    string minimized_dfa_table[index][num_of_symbol];
    for(i=0;i<index;i++)
    {
        for(j=0;j<num_of_symbol;j++)
        {
            for(k=0;k<index;k++)
            {
                if(minimized_dfa_states[k].find(dfa_transition[minimized_dfa_states[i][0]-'a'][j])<num_of_states)
                {
                    minimized_dfa_table[i][j]=minimized_dfa_states[k];
                    break;
                }
            }
        }
    }
    cout<<"minimized dfa table: "<<endl;
    for(i=0;i<index;i++)
    {
        for(j=0;j<num_of_symbol;j++)
        {
            cout<<minimized_dfa_table[i][j]<<" ";
        }
        cout<<endl;
    }
}