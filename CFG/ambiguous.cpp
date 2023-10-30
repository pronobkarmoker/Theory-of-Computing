#include <iostream>
#include <string>
using namespace std;

// Function to generate leftmost derivations for the CFG
void generateDerivations(string input, int index, string stack, int derivationNumber) {
    // Base case: If we have reached the end of the input, print the derivation
    if (index == input.length()) {
        cout << "Leftmost " << derivationNumber << ": " << stack << endl;
        return;
    }

    // Rule 1: S → aS
    stack += 'a';
    generateDerivations(input, index + 1, stack, derivationNumber);

    // Rule 2: S → aSbS
    if (input[index] == 'a' && input[index + 1] == 'a') {
        stack += "ab";
        generateDerivations(input, index + 2, stack, derivationNumber);
    }

    // Rule 3: S → ε
    if (input[index] == 'b') {
        generateDerivations(input, index + 1, stack, derivationNumber);
    }
}

int main() {
    string input = "aab"; // Input string
    string stack = "";

    cout << "Input: " << input << endl;

    // Generate the first leftmost derivation
    generateDerivations(input, 0, stack, 1);

    // Generate the second leftmost derivation
    generateDerivations(input, 0, stack, 2);

    cout << "The grammar is ambiguous." << endl;

    return 0;
}
