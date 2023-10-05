#include <bits/stdc++.h>
using namespace std;

bool found = false;
string path;
void cfg(vector<string> &base, string output, string target, string currpath)
{
    if (found)
        return;

    if (output.size() > target.size() + 1)
        return;

    if (output.find('P') == string::npos && output != " ")
    {
        if (output.find('E') != string::npos)
        {
            string temp = output.substr(0, output.find('E'));
            temp += output.substr(output.find('E') + 1);
            output = temp;
        }
        if (output == target)
        {
            found = true;
            path = currpath;
        }
        return;
    }

    for (string x : base)
    {
        if (output.find('P') != string::npos)
        {
            string temp = output.substr(0, output.find('P'));
            temp += x;
            temp += output.substr(output.find('P') + 1);
            x = temp;
        }
        cfg(base, x, target, currpath + "->" + x);
        if (found)
            return;
    }
}

int main()
{
    vector<string> base = {"E", "0", "1", "0P0", "1P1"};
    string s;
    cin >> s;
    cfg(base, " ", s, path);
    found ? cout << "Yes" : cout << "no";
    cout << endl;
    if (found)
    {
        if (path.find('E') != string::npos)
        {
            string temp = path.substr(0, path.find('E'));
            temp += path.substr(path.find('E') + 1);
            path = temp;
        }

        cout << "P" + path << endl;
    }
    return 0;
}