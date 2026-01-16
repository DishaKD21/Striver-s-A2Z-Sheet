//Max Sum without Adjacents
/*
Goal:
From the given array, select elements such that no two chosen elements are adjacent
and the total sum is maximum.

Core Decision at every index:
When I am at index i, I have two choices:
- Do not take arr[i] → the answer remains whatever was best till index i-1
- Take arr[i]        → then I must skip i-1, so I add arr[i] to the best till i-2
I always choose the maximum of these two options.

DP Meaning:
dp[i] represents the maximum sum that can be obtained from subarray [0..i].

How the solution was built:
1) Recursion:
   I try both choices at every index.
   This clearly shows the decision-making but is slow due to repeated calls.

2) Memoization:
   I store results for each index so the same subproblem is not solved again.
   This reduces time complexity to linear.

3) Tabulation:
   I build the solution iteratively from left to right using previously computed values.

4) Space Optimization:
   Since the answer at index i depends only on i-1 and i-2,
   I replace the dp array with two variables:
   - one for the best till previous index
   - one for the best till index-2

Edge Cases Handled:
- If the array has only one element, that element itself is the answer.
- If the array is empty, the maximum sum is zero.

Final Insight:
At each step, the problem reduces to choosing between
“skip the current element” or “take it and skip the previous one”.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int recursion(int i,vector<int> &arr){
    if(i==0) return arr[0];
    if(i<0) return 0;
    int left = 0 + recursion(i-1,arr);
    int right = arr[i] + recursion(i-2,arr);
    return max(left,right);
}
    int memo(int i, vector<int> &arr, vector<int> &dp){
    if(i==0) return arr[0];
    if(i<0) return 0;
    if(dp[i]!=-1)return dp[i];
    int left = 0 +memo(i-1,arr,dp);
    int right = arr[i] + memo(i-2,arr,dp);
    return dp[i]=max(left,right);
}
    int tabulation(vector<int> &arr, vector<int> &dp,int n){
      if(n==1)return arr[0];
      dp[0] = arr[0];
      dp[1] = max(arr[0], arr[1]);
    for(int i=2;i<n;i++){
       int left = 0 + dp[i-1];
       int right = arr[i] + dp[i-2];
       dp[i]=max(left,right);    
     } 
      return dp[n-1];   
    }
int spaceOptimized(vector<int> &arr,int n)
    {
    int prev,prev2,curr;
    if (n == 1) return arr[0];
    prev2 = arr[0];                 // dp[0]
    prev = max(arr[0], arr[1]);  //dp[1]
    for(int i=2;i<n;i++){
    int left = 0 + prev;
    int right = arr[i] + prev2;
    curr=max(left,right);
    prev2=prev; 
    prev=curr;   
    } 
    return prev;   
    }
   

    int findMaxSum(vector<int>& arr) {
    int n=arr.size();
    vector<int> dp(n,-1);
    //return recursion(n-1,arr); 
    //return memo(n-1,arr,dp); 
    //return tabulation(arr,dp,n);
    return spaceOptimized(arr,n);  
    }
};