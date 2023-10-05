#include <bits/stdc++.h>
using namespace std;

bool checkStr(string x, string y, string z, int powerZero, int powerOne)
{
    int k = 0, i;
    string temp = x;
    while (1)
    {
        string tempY = "";
        for (i = 0; i < k; i++)
            tempY += y;
        temp += tempY + z;

        int zero = 0, one = 0;
        for (i = 0; i < temp.size(); i++)
        {
            if (temp[i] == '0')
            {
                if (one == 0)
                    zero++;
                else
                    return false;
            }
            else
                one++;
        }
        if (zero * powerZero != one * powerOne)
        {
            cout << temp << endl;
            return false;
        }
        k++;
    }
    return true;
}
int main()
{
    string input;
    cin >> input;
    int powerZero, powerOne, i, n, j;

    for (i = 0; i < input.size(); i++)
    {
        if (input[i] == '^' && input[i - 1] == '0')
        {
            string temp = "";
            i++;
            while (input[i] != 'n')
            {
                temp.push_back(input[i]);
                i++;
            }
            temp.empty() ? powerZero = 1 : powerZero = stoi(temp);
        }
        else if (input[i] == '^' && input[i - 1] == '1')
        {
            string temp = "";
            i++;
            while (input[i] != 'n')
            {
                temp.push_back(input[i]);
                i++;
            }
            temp.empty() ? powerOne = 1 : powerOne = stoi(temp);
        }
    }
    // cout<<powerZero<<" "<<powerOne<<endl;

    n = 3;
    string test = "";
    for (i = 0; i < n * powerZero; i++)
        test += '0';
    for (i = 0; i < n * powerOne; i++)
        test += '1';

    cout << "Test String: " << test << endl;
    for (i = 0; i < 2 * n; i++)
    {
        for (j = i + 1; j < 2 * n; j++)
        {
            string x = test.substr(0, i);
            string y = test.substr(i + 1, j - i);
            string z = test.substr(j);

            cout << "Check for X= " << x << " Y= " << y << " Z= " << z << endl;

            bool ans = checkStr(x, y, z, powerZero, powerOne);
            if (!ans)
            {
                cout << "NO" << endl;
                return 0;
            }
            else
                cout << "YES" << endl;
        }
    }
}