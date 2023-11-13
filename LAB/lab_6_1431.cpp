#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int state = 3, symbol = 2;
    int transitionTable[state][symbol];
    int modifiedTT[state][state] = {-1};

    fstream file;
    file.open("regex.txt", ios::in);
    if (!file)
    {
        cout << "File doesn't exist." << endl;
    }
    else
    {
        for (int i = 0; i < state; i++)
        {
            for (int j = 0; j < symbol; j++)
            {
                file >> transitionTable[i][j];
            }
        }
    }

    for (int i = 0; i < state; i++)
    {
        for (int j = 0; j < state; j++)
        {
            modifiedTT[i][j] = -1;
            modifiedTT[i][transitionTable[i][0]] = 0;
            modifiedTT[i][transitionTable[i][1]] = 1;
        }
    }

   

    string r[3][state][state];

    // for Rij(0)
    for (int i = 0; i < state; i++)
    {
        for (int j = 0; j < state; j++)
        {
            if (modifiedTT[i][j] != -1)
            {
                if (i == j)
                {
                    r[0][i][j] = modifiedTT[i][j] + '0';
                    r[0][i][j].append("+E");
                }
                else
                {
                    r[0][i][j] = modifiedTT[i][j] + '0';
                }
            }
            else
            {
                r[0][i][j] = "null";
            }
        }
    }


    for (int k = 1; k < 3; k++)
    {
        for (int i = 0; i < state; i++)
        {
            for (int j = 0; j < state; j++)
            {
                r[k][i][j] = r[k - 1][i][j] + " + " + r[k - 1][i][k] + "(" + r[k - 1][k][k] + ")" + " * " + r[k - 1][k][j];
            }
        }
    }

    for (int k = 0; k < 3; k++)
    {
        cout << "Regular expression of R" << k << " is: " << endl;
        cout << endl;
        for (int i = 0; i < state; i++)
        {
            for (int j = 0; j < state; j++)
            {
                cout << "R(" << k << ")" << i << j << " ||  ";
                cout << r[k][i][j] << endl;
            }
            cout << endl;
            cout << endl;
        }
        cout << endl;
    }
}