/*
The logic is based on the "take and not take" approach (also called include/exclude recursion).
For every index `i`, we check if it is greater than or equal to the size of the input vector.
If it is, that means we have formed one complete subset, so we check if sum is equal to the target sum then we push the current `vec` into the `ans` vector.
and return the ans.
If it's not, we have two choices:
1. Take the current element (nums[i]) — push it into the `vec` and recursively call the function with the next index.
2. Not take the current element — don't push anything, just move to the next index with another recursive call.

At each step, we go deeper by branching into these two choices, generating all possible subsets and we print all subsequences which is having sum is equal to k.
*/
// vs code sol
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> f(int i, int arr[], int n, vector<int> &vec, vector<vector<int>> &ans ,int sum ,int k)
{  
    if (i >= n){
    if(sum==k) ans.push_back(vec);
    return ans;
    }
    vec.push_back(arr[i]);
    sum+=arr[i];
    f(i + 1, arr, n, vec, ans ,sum ,k);
    vec.pop_back();
    sum-=arr[i];
    f(i + 1, arr, n, vec, ans,sum,k);
    return ans;
}
int main()
{
    vector<vector<int>> ans;
    vector<int> vec;
    int n = 5, i = 0;
    int sum=0,k=6;
    int arr[n] = {3, 1, 2, 4, 5};
    ans = f(i, arr, n, vec, ans ,sum ,k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size();j++)
        {
            cout << ans[i][j] <<" ";  
        }
        cout << "]";
        cout << " "<<endl;
    }
}