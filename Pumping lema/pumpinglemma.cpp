#include <iostream>
#include <string>

using namespace std;

// Function to check if a string is in L = {0^n1^2n | n >= 1}
bool isInLanguage(const string &str)
{
    int n = str.length();

    if (n % 3 != 0)
    {
        return false; // The length of the string must be a multiple of 3.
    }

    int n0 = 0;
    int n1 = 0;

    for (char c : str)
    {
        if (c == '0')
        {
            n0++;
        }
        else if (c == '1')
        {
            n1++;
        }
        else
        {
            return false; // The string contains characters other than '0' and '1'.
        }
    }

    return n0 == n1 / 2;
}

// Function to generate and test strings using pumping lemma
bool testPumpingLemma(const string &str)
{
    int n = str.length();

    for (int len = 1; len <= n / 3; len++)
    {
        string x = str.substr(0, len);
        string y = str.substr(len, len);
        string z = str.substr(2 * len);
        string pumpedString = x + y + y + z;

        if (!isInLanguage(pumpedString))
        {
            cout << "The string " << pumpedString << " is not in the language." << endl;
            return false;
        }
    }

    return true;
}

int main()
{
    string input;
    cout << "Enter a string in the format '0^n1^2n': ";
    cin >> input;

    if (isInLanguage(input))
    {
        if (testPumpingLemma(input))
        {
            cout << "The language L = {0^n1^2n | n >= 1} is not regular using the pumping lemma." << endl;
        }
        else
        {
            cout << "The language L = {0^n1^2n | n >= 1} might still be regular." << endl;
        }
    }
    else
    {
        cout << "The input string is not in the required format." << endl;
    }

    return 0;
}