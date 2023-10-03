#include <iostream>
#include <string.h>
#define MAX 1000

using namespace std;

int a, m, b, n;
char expression[MAX];
char x[MAX], y[MAX], z[MAX];

bool pumping()
{
    // int k;
    // cout<<"Enter k:";
    // cin>>k;
    for (int k = 0; k < 200; k++)
    {
        int len = strlen(y);
        cout << "lengt of y:" << len << endl;
        char newY[MAX];
        for (int i = 0; i < k * len; i += len)
        {
            for (int j = 0; j < len; j++)
            {
                newY[i] = y[j];
            }
        }
        newY[k * len] = '\0';
        cout << newY << endl;

        char newExpr[MAX] = "\0";
        strcat(newExpr, x);
        strcat(newExpr, newY);
        strcat(newExpr, z);
        cout << "Regualar expression after pumping lemma: " << newExpr << endl;

        int newN = 0, newM = 0;
        for (int i = 0; i < strlen(newExpr); i++)
        {
            if (newExpr[i] == a)
                newN++;
            else
                newM++;
        }

        if ((float)newN / newM != ((float)n / m))
            return false;
    }
    return true;
}

void xyz()
{
    int random = (int)rand() % (m - 1);
    cout << "random: " << random << endl;
    for (int i = m - 1, j = 0; i > m - 1 - random; i--, j++)
    {
        y[j] = expression[i];
    }
    y[n] = '\0';
    cout << "y: " << y << endl;
    for (int i = 0, j = 0; i <= m - 1 - random; i++, j++)
    {
        x[j] = expression[i];
    }
    x[n] = '\0';
    cout << "x: " << x << endl;
    for (int i = m, j = 0; i < m + n; i++, j++)
    {
        z[j] = expression[i];
    }
    z[n] = '\0';
    cout << "Z: " << z << endl;

    if (pumping())
        cout << "Yes, Regular expression" << endl;
    else
        cout << "No, its not a regular expression" << endl;
}

int main()
{
    cout << "Enter a, num of a, b, num of b : " << endl;
    cin >> a >> m >> b >> n;

    for (int i = 0; i < m; i++)
    {
        expression[i] = (char)(a + 48);
    }
    for (int i = m; i < m + n; i++)
    {
        expression[i] = (char)(b + 48);
    }

    cout << "Expression :" << expression << endl;

    xyz();
}