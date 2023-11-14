#include<bits/stdc++.h>
using namespace std;

bool pda(string s,stack<char>&st)
{
    bool b=false;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='a')
        {
            if(!b)
            st.push(s[i]);
            else
            return false;
        }
        else if(s[i]=='b')
        {
            b=true;
            if(!st.empty())
            st.pop();
        }
    }
    if(st.empty())
        return true;
    return false;
}

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

int main()
{
    string s;
    cin>>s;
    stack<char>st;

    pda(s,st) ? cout<<"Accepted" : cout<<"Rejected";
    cout<<endl;
    return 0;
}