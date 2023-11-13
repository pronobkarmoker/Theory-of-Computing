#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Expression is: "
         << "0^" << n << " "
         << "1^" << n << endl;
    string input;

    for (int i = 0; i < n; ++i)
    {
        input += "0";
    }

    for (int i = 0; i < n; ++i)
    {
        input += "1";
    }

    cout << "String is: " << input << endl;
    string x;
    string y;
    string z;

    if (n > 1)
    {
        x = input.substr(0, n - 1);
        y = input.substr(n - 1, 1);
        z = input.substr(n);
    }
    else
    {
        y = input.substr(n - 1, 1);
        z = input.substr(n);
    }

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;

    for (int k = 1;; ++k)
    {
        string pumpedString = x;
        for (int i = 0; i < k; ++i)
        {
            pumpedString += y;
        }
        pumpedString += z;

        cout << "Pumped string for k = " << k << "--->"
             << " " << pumpedString << endl;

    
        string pumped_x;
        string pumped_y;
        string pumped_z;
        if (n != 1)
        {
            pumped_x = pumpedString.substr(0, n - 1);
        }

        pumped_y = pumpedString.substr(n - 1, k);

        pumped_z = pumpedString.substr(n + k - 1);

        cout << "string: " << pumped_x << " " << pumped_y << " " << pumped_z << " " << endl;

        if (pumped_x == x && pumped_y == y && pumped_z == z)
        {

            cout << "Pumped string is in the Language." << endl;
        }
        else
        {
            cout << "Language is not regular." << endl;
            break;
        }
    }

    return 0;
}