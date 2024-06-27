#include <bits/stdc++.h>

using namespace std;

void InsertSort(vector<int> &nums)
{
    int len = nums.size();
    for (int i = 1; i < len; i++)
    {
        int key = nums[i];
        int j = i - 1;
        while(j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
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

    InsertSort(nums);
    
    cout << "Sorted array: " << '\n';
    for (int num : nums) {cout << num << " ";}
  
    return 0;
}