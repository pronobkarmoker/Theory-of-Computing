#include <bits/stdc++.h>
using namespace std;

vector<string> prod = {"e", "0", "1", "0P0", "1P1"};
vector<string> soln;
bool check = true;
string input, ans = "";

void CFG(string p)
{
    if (ans == input)
        return;
    int i, j, k;
    string temp = "";
    bool check_temp = false;
    if (p.empty())
    {
        j = input.size();
        temp.push_back(input[0]);
        if (input.size() > 1)
            temp += "P";
        while (j > 0)
        {
            p += input.substr(1, j - 1);
            temp += input.substr(j);

            for (k = 0; k < prod.size(); k++)
            {
                if (prod[k] == temp)
                    break;
            }
            if (k == prod.size())
            {
                if (temp.size() == 2 && p.size() == 1 && p[0] == temp[0])
                    k--;
            }
            if (k < prod.size())
            {
                check_temp = true;
                break;
            }
            j--;
            // cout<<temp<<" "<<p<<endl;
            temp.clear();
            p.clear();
            temp.push_back(input[0]);
            temp += "P";
        }

        if (!check_temp)
            check = false;
        else
        {
            ans = temp;
            soln.push_back(ans);
            CFG(p);
        }
    }
    else
    {
        temp.push_back(p[0]);
        if (p.size() > 1)
            temp += "P";
        ;
        string tempP;
        j = p.size();
        while (j > 0)
        {
            tempP += p.substr(1, j - 1);
            temp += p.substr(j);

            for (k = 0; k < prod.size(); k++)
            {
                if (prod[k] == temp)
                    break;
            }
            if (k == prod.size())
            {
                if (temp.size() == 2 && tempP.size() == 1 && tempP[0] == temp[0])
                    k--;
            }

            if (k < prod.size())
            {
                check_temp = true;
                break;
            }
            else
            {
                j--;
                // cout<<temp<<" "<<p<<endl;
                temp.clear();
                tempP.clear();
                temp.push_back(p[0]);
                temp += "P";
            }
        }

        if (!check_temp)
            check = false;
        else
        {
            for (i = 0; i < ans.size(); i++)
            {
                if (ans[i] == 'P')
                {
                    ans.erase(i, 1);
                    break;
                }
            }
            ans.insert(i, temp);
            // cout<<ans<<endl;
            soln.push_back(ans);
            CFG(tempP);
        }
    }
    //  cout<<ans<<endl;
}
int main()
{
    cin >> input;
    soln.push_back("P");
    CFG("");
    if (check)
    {
        for (int i = 0; i < soln.size(); i++)
        {
            cout << soln[i] << endl;
        }
    }
    else
        cout << "Not in this grammar";
}