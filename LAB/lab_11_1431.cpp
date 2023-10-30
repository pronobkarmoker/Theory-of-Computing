#include <bits/stdc++.h>
using namespace std;

int found = 0, found2 = 0;
string path;
vector<string> paths, paths2;

void cfg(vector<string> &base, string output, string target, string currpath)
{
    if (found >= 2)
        return;

    if (output.size() > target.size() + 2)
        return;

    if (output.find('S') == string::npos && output != " ")
    {
        if (output == target)
        {
            found++;
            path = currpath;
            paths.push_back(path);
        }
        return;
    }

    for (string x : base)
    {
        if (output.find('S') != string::npos)
        {
            string temp = output.substr(0, output.find('S'));
            temp += x;
            temp += output.substr(output.find('S') + 1);
            x = temp;
        }
        cfg(base, x, target, currpath + "->" + x);
        if (found >= 2)
            return;
    }
}

void cfg2(vector<string> &base, string output, string target, string currpath)
{
    if (found2 >= 2)
        return;

    if (output.size() > target.size() + 2)
        return;

    if (output.find('S') == string::npos && output != " ")
    {
        if (output == target)
        {
            found2++;
            path = currpath;
            paths2.push_back(path);
        }
        return;
    }

    for (string x : base)
    {
        if (output.find('S') != string::npos)
        {
            string temp = output.substr(0, output.find_last_of('S'));
            temp += x;
            temp += output.substr(output.find_last_of('S') + 1);
            x = temp;
        }
        cfg2(base, x, target, currpath + "->" + x);
        if (found2 >= 2)
            return;
    }
}

int main()
{
    vector<string> base = {"aS", "aSbS", ""};
    string s;
    cin >> s;
    cfg(base, " ", s, path);

    if (found == 2)
    {
        for (string x : paths)
            cout << "Letfmost : S" + x << endl;
        cout << "The grammar is ambiguous" << endl;
    }
    else
        cout << "May not be ambiguous" << endl;

    // RightMost derivation test for ambiguous grammar
    //  path.clear();

    // cfg2(base, " ", s, path);

    // if(found2==2)
    // {
    //     for(string x : paths2)
    //     cout<<"Rightmost: S"+x<<endl;
    //     cout<<"The grammar is ambiguous"<<endl;
    // }
    // else
    // cout<<"May not be ambiguous"<<endl;
    return 0;
}