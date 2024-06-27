#include <bits/stdc++.h>

using namespace std;
void Merge(vector<int> &nums, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<int> left(n1);
    vector<int> right(n2);
    for (int i = 0; i < n1; i++) left[i] = nums[p + i];
    for (int i = 0; i < n2; i++) right[i] = nums[q + i + 1];
    left.push_back(INT_MAX);
    right.push_back(INT_MAX);
    int i = 0, j = 0;
    for (int k = p; k <= r; k++)
    {
        if (left[i] < right[j])
        {
            nums[k] = left[i];
            i++;
        }
        else
        {
            nums[k] = right[j];
            j++;
        }
    }
}

void MergeSort(vector<int> &nums, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        MergeSort(nums, p, q);
        MergeSort(nums, q + 1, r);
        Merge(nums, p, q, r);
    }
}

int main()
{
    vector<int> nums;
    int n = 0;
    cout << "Input array elements separated by space (press enter to finish):" << '\n';

    string input;
    getline(cin, input);
    istringstream iss(input);
    while (iss >> n) {nums.push_back(n);}

    MergeSort(nums, 0, nums.size() - 1);
    
    cout << "Sorted array: " << '\n';
    for (int num : nums) {cout << num << " ";}
  
    return 0;
}