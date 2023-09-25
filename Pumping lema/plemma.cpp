#include <iostream>
using namespace std;

bool isInLang(const string &str);
void testPumpingLemma(const string &str);

int main()
{
    string input;
    cout << "Input format: 0^n1^n" << endl;
    cin >> input;

    int count0 = 0, count1 = 0;
    
    // Count the number of '0's and '1's in the input.
    for (char c : input)
    {
        if (c == '0')
            count0++;
        else if (c == '1')
            count1++;
    }

    if (count0 == count1 && isInLang(input))
    {
        testPumpingLemma(input);
    }
    else
    {
        cout << "Incorrect Format" << endl;
    }
}

bool isInLang(const string &str)
{
    int n = str.size();
    
    // Check if the length is even and the first half is '0's and the second half is '1's.
    int mid = n / 2;
    for (int i = 0; i < mid; i++)
    {
        if (str[i] != '0' || str[i + mid] != '1')
        {
            return false;
        }
    }

    return true;
}

void testPumpingLemma(const string &str)
{
    int n = str.length();

    for (int len = 1; len <= n / 2; len++)
    {
        string x = str.substr(0, len);
        string y = str.substr(len, len);
        string z = str.substr(2 * len);
        string pumpedString = x + y + y + z;

        if (!isInLang(pumpedString))
        {
            cout << "The string " << pumpedString << " is not in the language." << endl;
            return;
        }
    }

    cout << "The input string is in the language." << endl;
}
