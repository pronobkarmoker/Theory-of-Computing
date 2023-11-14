#include<bits/stdc++.h>
using namespace std;

stack<char> PDAstack;
vector<string> states;
vector<string> stackState;

void printStack(stack<char> s){
    stack<char> temp;
    while(!s.empty()){
        cout << s.top() << " ";
        temp.push(s.top());
        s.pop();
    }
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
}


int main(){
    PDAstack.push('Z');
    states.push_back("q0");
    states.push_back("q1");
    states.push_back("qf");

    string input;
    cout << "Enter a string: ";
    cin >> input;

    char start = input[0];
    
    int i=0;
    while(input[i]==start){
        cout << "Stack: ";
        printStack(PDAstack);
        cout << endl;
        PDAstack.push(input[i]);
        i++;
    }

    char last = input[i];
    while(input[i]==last){
        cout << "Stack: ";
        printStack(PDAstack);
        cout << endl;
        if(i>=input.size() || PDAstack.size()==1){
            cout << "This is not accepted by the PDA" << endl;
            return 0;
        }
        PDAstack.pop();
        i++;
    }

    if(PDAstack.top() == 'Z' && i==input.size()+1){
        cout << "Stack: ";
        printStack(PDAstack);
        cout << endl;
        cout << "This is accepted by the PDA" << endl;
    }
    else{
        cout << "This is not accepted by the PDA" << endl;
    }
    
    
}