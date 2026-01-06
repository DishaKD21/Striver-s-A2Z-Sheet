//Count all subsequences with sum K && Perfect Sum Problem 
/*
here what we are doing is we are finding the all the subsequence with its sum with use
of recursive function using take not take approch and we are returning 1 when we found 
such subsequence which is giving us sum equal to the target otherwise we are returning 0.
so this 1 and 0 means each time we found such subsequence having sum equal to k our count
increases with 1.we return that left side & right side's count.

this recursive function will give you TLE because it's time complexity is going in 
exponential 2^n because each time we have two options either take or not take the 
element so now if you make the recursive tree for this you can see the overlapping 
subproblem so we can apply memoization over here to reduce the complexity

DP Explanation:
To avoid recomputing the same recursive states again and again, we use a 2D DP array.
dp[i][sum] stores the number of subsequences that can be formed starting from index i
with the current accumulated sum equal to sum.

If a state (i, sum) is already computed, we directly return its stored value instead of
recalculating it. This removes overlapping subproblems and optimizes the solution.

The DP table size is n x (target + 1) because the index ranges from 0 to n-1 and the sum
can vary from 0 to target. Using memoization reduces the time complexity from O(2^n)
to O(n * target).
*/

class Solution {
  public:
 int f(int i, vector<int> &arr, int n ,int sum ,int k,vector<vector<int>> &dp)
    {  
    if (i == n){
    if (sum == k){
        return 1;
       }
       return 0;
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    int r=f(i + 1, arr, n,sum, k,dp);
    int l=0;
    if(k>=sum+arr[i]){  //f(3,3) --> 3+10 is 13 fails if condition what it will return
    l=f(i + 1, arr, n,sum+arr[i],k,dp);
    }
    return dp[i][sum]=l+r;
}
    int perfectSum(vector<int>& arr, int target) {
    int ans=0,sum=0; 
    int n = arr.size(), i = 0;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    ans = f(i, arr, n, sum, target ,dp);
    return ans;
    }
};