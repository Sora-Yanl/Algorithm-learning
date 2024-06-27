#include <bits/stdc++.h>

using namespace std;

void LCS(string X, string Y)
{
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> b(m + 1, vector<int>(n + 1));
    vector<vector<int>> c(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++) c[i][0] = 0;
    for (int i = 0; i <= n; i++) c[0][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'q';
            }
            else
            {
                if (c[i - 1][j] >= c[i][j - 1])
                {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = 'w';
                }
                else
                {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = 'a';
                }
            }
        }
    }

    int len = c[m][n];
    char *lcs = new char[len+1];
    lcs[len] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (b[i][j] == 'q')
        {
            lcs[--len] = X[i-1];
            i--;
            j--;
        }
        else if (b[i][j] == 'w') i--;
        else if (b[i][j] == 'a') j--;
    }

    cout << lcs;

    delete[] lcs;
}

int main()
{
    string X, Y;
    cout << "Input two lines of string:" << '\n';
    cin >> X >> Y;
    cout << "The longest common substring is: " << '\n';
    LCS(X, Y);
    return 0;
}