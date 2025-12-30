// Check if there exists a subsequence with sum K
/*
The logic is based on the "take and not take" approach (also called include/exclude recursion).
For every index `i`, we check if it is greater than or equal to the size of the input vector.
If it is, that means we have formed one complete subset, so we check if sum is equal to the target sum.
If it is, we return true — as soon as we find any one valid subsequence with sum equal to k, we stop further calls and return true.
If not, we return false and backtrack.

If it's not the base case, we have two choices:
1. Take the current element (nums[i]) — push it into the `vec`, add it to `sum`, and make a recursive call with the next index.
   - After taking, we check if the recursive call returns true. If yes, we return true immediately and skip further processing.
2. Not take the current element — pop it from `vec`, subtract from `sum`, and again call recursively with the next index.
   - Similarly, if this recursive call returns true, we return true immediately.

At each step, we try both choices, and as soon as we find a valid subsequence whose sum is equal to k, we return true without checking remaining paths.
*/
//gfg sol
class Solution
{
public:
    bool checkSubsequenceSum(int n, vector<int> &arr, int k)
    {
        bool ans;
        vector<int> vec;
        int sum = 0;
        int i = 0;
        ans = f(i, arr, vec, n, sum, k);
        return ans;
    }
    bool f(int i, vector<int> &arr, vector<int> &vec, int n, int sum, int k)
    {
        if (sum > k)
        {
            return false;
        }
        if (i >= n)
        {
            if (sum == k)
                return true;
            return false;
        }
        vec.push_back(arr[i]);
        sum += arr[i];
        if (f(i + 1, arr, vec, n, sum, k) == true)
            return true;
        vec.pop_back();
        sum -= arr[i];
        if (f(i + 1, arr, vec, n, sum, k) == true)
            return true;
        return false;
    }
};

// vs code sol
#include <bits/stdc++.h>
using namespace std;
bool f(int i, int arr[], vector<int> &vec, int n, int sum, int k)
{
    if (i >= n)
    {
        if (sum == k)return true;
        return false;
    }
    vec.push_back(arr[i]);
    sum += arr[i];
    if (f(i + 1, arr, vec, n, sum, k) == true)
        return true;
    vec.pop_back();
    sum -= arr[i];
    if (f(i + 1, arr, vec, n, sum, k) == true)
        return true;
    return false;
}
int main(){
        bool ans;
        vector<int> vec;
        int n = 5;
        int k= 100;
        int arr[n] = {2, 3, 5, 7, 9};
        int sum = 0;
        int i = 0;
        ans = f(i, arr, vec, n, sum, k);
       if(ans==true){
        cout<<"yes";
       }
        cout<<"no";
        return 0;
}
