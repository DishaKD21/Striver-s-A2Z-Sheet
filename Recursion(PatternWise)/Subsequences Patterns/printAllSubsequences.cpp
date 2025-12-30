// leetcode sol
// 78. Subsets
/*
The logic is based on the "take and not take" approach (also called include/exclude recursion).
For every index `i`, we check if it is greater than or equal to the size of the input vector.
If it is, that means we have formed one complete subset, so we push the current `vec` into the `ans` vector.

If it's not, we have two choices:
1. Take the current element (nums[i]) — push it into the `vec` and recursively call the function with the next index.
2. Not take the current element — don't push anything, just move to the next index with another recursive call.

At each step, we go deeper by branching into these two choices, generating all possible subsets.
*/

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> vec;
        int n = nums.size(), i = 0;
        ans = f(i, nums, n, vec, ans);
        return ans;
    }
    vector<vector<int>> f(int i, vector<int> &nums, int n, vector<int> &vec, vector<vector<int>> &ans)
    {
        if (i >= n)
        {
            ans.push_back(vec);
            return ans;
        }
        vec.push_back(nums[i]);
        f(i + 1, nums, n, vec, ans);
        vec.pop_back();
        f(i + 1, nums, n, vec, ans);
        return ans;
    }
};

// vs code sol
//  vs code sol
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> f(int i, int arr[], int n, vector<int> &vec, vector<vector<int>> &ans)
{
    if (i >= n)
    {
        ans.push_back(vec);
        return ans;
    }
    vec.push_back(arr[i]);
    f(i + 1, arr, n, vec, ans);
    vec.pop_back();
    f(i + 1, arr, n, vec, ans);
    return ans;
}
int main()
{
    vector<vector<int>> ans;
    vector<int> vec;
    int n = 3, i = 0;
    int arr[n] = {3, 1, 2};
    ans = f(i, arr, n, vec, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size();j++)
        {
            cout << ans[i][j] <<" ";
        }
        cout <<"]";
        cout <<" "<< endl;
    }
}