#include <iostream>
#include <string>
using namespace std;

// Function to generate leftmost derivations for the CFG
void leftmostDerivation(string input) {
    string S = "S";
    string A = "A";
    string B = "B";

    cout << "Leftmost: " << S;

    for (char c : input) {
        if (c == '0') {
            cout << " => " << A << "0";
        } else if (c == '1') {
            cout << " => " << B << "1";
        }
    }

    cout << endl;
}

// Function to generate rightmost derivations for the CFG
void rightmostDerivation(string input) {
    string S = "S";
    string A = "A";
    string B = "B";

    cout << "Rightmost: " << S;

    for (char c : input) {
        if (c == '0') {
            cout << " => " << A << "0";
        } else if (c == '1') {
            cout << " => " << B << "1";
        }
    }

    cout << endl;
}

int main() {
    string input = "00101"; // Input string

    cout << "Input: " << input << endl;

    leftmostDerivation(input);
    rightmostDerivation(input);

    return 0;
}
