#include <bits/stdc++.h>

using namespace std;

double Optimal_BST(vector<double> &p, vector<double> &q)
{
    int n = p.size();
    vector<vector<double>> e(n + 2, vector<double>(n + 1));
    vector<vector<double>> w(n + 2, vector<double>(n + 1));
    for (int i = 1; i <= n + 1; i++)
    {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }
    for (int l = 1; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            e[i][j] = INT_MAX;
            w[i][j] = w[i][j - 1] + p[j - 1] + q[j];
            for (int r = i; r <= j; r++)
            {
                double t = e[i][r - 1] + w[i][j] + e[r + 1][j];
                e[i][j] = min(e[i][j], t);
            }
        }
    }
    return e[1][n];
}

int main()
{
    cout << "Input the number of p:" << '\n';
    int n; cin >> n;
    cout << "Input a row of values for p and a row of values for q:" << '\n';
    vector<double> p(n);
    vector<double> q(n + 1);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n + 1; i++) cin >> q[i];
    cout << "value of Optimal-BST: " << '\n';
    cout << Optimal_BST(p, q);
  
    return 0;
}