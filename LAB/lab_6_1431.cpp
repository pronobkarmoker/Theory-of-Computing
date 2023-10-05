#include <bits/stdc++.h>
using namespace std;
#define mx 100

int main()
{
    // freopen("regex.txt", "r", stdin);

    char str[mx], state;
    int numState, numAlpha, i, j, k = 0, p, states[mx], alpha[mx];

    printf("Enter number of states: ");
    cin >> numState;

    printf("Enter states: ");
    for (i = 0; i < numState; i++)
        cin >> states[i];

    printf("Enter number of Alphabet: ");
    cin >> numAlpha;

    printf("Enter alphabets: ");

    for (i = 0; i < numAlpha; i++)
        cin >> alpha[i];

    int transit[numState][numAlpha];
    printf("Provide transition functions: \n");
    for (i = 0; i < numState; i++)
    {
        printf("Enter transition for state %d: \n", states[i]);
        for (j = 0; j < numAlpha; j++)
        {
            printf("Enter for alphabet %d: ", alpha[j]);
            cin >> transit[i][j];
        }
    }

    string R[3][numState + 1][numState + 1];

    for (i = 0; i < numState; i++)
    {
        for (j = i; j < numState; j++)
        {
            for (p = 0; p < numAlpha; p++)
            {
                if (transit[i][p] == j + 1)
                {
                    R[0][i + 1][j + 1] += to_string(p);
                    if (i == j)
                        R[0][i + 1][j + 1] += "+E";
                    break;
                }
            }
            if (p == numAlpha)
                R[0][i + 1][j + 1] += "N";
        }
    }

    for (k = 1; k < 3; k++)
    {
        for (i = 1; i < numState + 1; i++)
        {
            for (j = i; j < numState + 1; j++)
            {
                R[k][i][j] = R[k - 1][i][j] + "+" + R[k - 1][i][k] + "(" + R[k - 1][k][k] + ")*" + R[k - 1][k][j];
            }
        }
    }

    for (k = 0; k < 3; k++)
    {
        for (i = 1; i < numState + 1; i++)
        {
            for (j = i; j < numState + 1; j++)
                cout << "R"
                     << "(" << k << ")" << i << j << ": " << R[k][i][j] << endl;
        }
    }
    return 0;
}