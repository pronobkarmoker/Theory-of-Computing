#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char> stack;
    string in;

    cout << "Enter a string: ";
    cin >> in;

    int state = 0;
    int flag =0 ;

    for (char sym : in)
    {
        if (state == 0)
        {
            if (sym == '0')
            {
                stack.push('0');
                if (stack.top() == 1)
                {
                    break;
                }
                
            }
            else if (sym == '1' && !stack.empty() && stack.top() == '0')
            {

                stack.pop();
            }
            
            else
            {
                cout << "Rejected" << endl;
                return 0;
            }
        }
        else
        {
            cout << "Rejected" << endl;
            return 0;
        }
    }

    if (stack.empty())
    {
        cout << "Accepted" << endl;
    }
    else
    {
        cout << "Rejected" << endl;
    }

    return 0;
}
