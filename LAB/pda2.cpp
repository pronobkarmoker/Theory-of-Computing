#include<bits/stdc++.h>
using namespace std;

bool pda(string s,stack<char>&st)
{
    bool one=false;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='0')
        {
            if(!one)
            st.push(s[i]);
            else
            return false;
        }
        else if(s[i]=='1')
        {
            one=true;
            if(!st.empty())
            st.pop();
        }
    }
    if(st.empty())
    return true;
    return false;
}
int main()
{
    string s;
    cin>>s;
    stack<char>st;

    pda(s,st) ? cout<<"YES" : cout<<"NO";
    cout<<endl;
    return 0;
}