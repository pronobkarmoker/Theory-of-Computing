#include <bits/stdc++.h>
using namespace std;

int main()
{
    char transition[3][2];
    char alphabet[2] = {'0', '1'};
    freopen("input.txt","r",stdin);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin>>transition[i][j];
        }
    }
    
    map<int, vector<int>> mp;

    vector<int>v(4);
    
    for (int j = 0; j < 3; j++)
    {   
        for(int s=0;s<v.size();s++) v[s]=-1;

        for (int k = 0; k < 2; k++)
        {
            int temp=transition[j][k]-'0';
            v[temp]=k;
            
        }

        cout<<endl;
        mp.insert(make_pair(j+1,v));
        
    }

    // for(auto x:mp){
    //     cout<<x.first<<" -> ";
    //     for(auto ele:x.second){
    //         cout<<ele<<" ";
    //     }
    //     cout<<endl;
    // }


    for(auto x:mp){
        for(int i=1;i<x.second.size();i++){
            if(x.first==i && x.second[i]!=-1){
                cout<<"R("<<x.first<<","<<i<<","<<"0):"<<"eps+"<<x.second[i]<<endl;
            }
            else if(x.first==i && x.second[i]==-1){
                cout<<"R("<<x.first<<","<<i<<","<<"0):"<<"eps"<<endl;
            }
            else{
                cout<<"R("<<x.first<<","<<i<<","<<"0):"<<x.second[i]<<endl;
            }
        }
        cout<<endl;
    }

    return 0;
}
