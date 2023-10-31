#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<char> stack;
    string input;
    char currentSymbol;

    cout << "Enter a string: ";
    cin >> input;

    char currentState = 'q0';
    stack.push('$');

    for (int i = 0; i < input.length(); i++)
    {
        currentSymbol = input[i];
        if (currentState == 'q0')
        {
            if (currentSymbol == '0')
            {
                stack.push('S');
            }
            else if (currentSymbol == '1' && stack.top() == 'S')
            {

                stack.pop();
                currentState = 'q1';
            }
            else
            {
                cout << "Rejected" << endl;
                return 0;
            }
        }
        else if (currentState == 'q1')
        {
            if (currentSymbol == '1' && stack.top() == 'S')
            {
                stack.pop();
            }
            else
            {
                cout << "Rejected" << endl;
                return 0;
            }
        }
    }

    if (currentState == 'q1' && stack.top() == '$')
    {
        cout << "Accepted" << endl;
    }
    else
    {
        cout << "Rejected" << endl;
    }

    return 0;
}
