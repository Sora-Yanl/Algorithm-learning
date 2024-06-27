#include <bits/stdc++.h>

using namespace std;

// The finish time is listed in order

void Activity_Select(vector<int> &start, vector<int> &finish, int n)
{
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (start[i] >= time)
        {
            time = finish[i];
            cout << i << ' ';
        }
        else continue;
    }
}

int main()
{
    cout << "Input the number of activities:" << '\n';
    int n; cin >> n;
    cout << "Input the start and end time for each activity:" << '\n';
    vector<int> start;
    vector<int> finish;
    for (int i = 0; i < n; i++)
    {
        int s, f; cin >> s >> f;
        start.push_back(s);
        finish.push_back(f);
    }
    Activity_Select(start, finish, n);

    return 0;
}