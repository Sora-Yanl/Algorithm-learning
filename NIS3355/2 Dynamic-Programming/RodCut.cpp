#include <bits/stdc++.h>

using namespace std;

int CutRod(vector<int> &price)
{
    int len = price.size();
    vector<int> dp(len + 1);
    dp[0] = 0;
    for (int i = 1; i <= len; i++)
    {
        int q = INT_MIN;
        for (int j = 1; j <= i; j++)
        {
            q = max(q, price[j - 1] + dp[i - j]);
        }
        dp[i] = q;
    }
    return dp[len];
}

int main()
{
    vector<int> price;
    int n = 0;
    cout << "Input the price of steel bars of length 0 to n by space (press enter to finish):" << '\n';

    string input;
    getline(cin, input);
    istringstream iss(input);
    while (iss >> n) {price.push_back(n);}

    cout << "The biggest price is: " << '\n';
    cout << CutRod(price);
    return 0;
}