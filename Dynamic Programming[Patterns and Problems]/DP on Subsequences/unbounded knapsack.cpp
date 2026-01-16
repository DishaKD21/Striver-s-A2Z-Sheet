//unbounded knapsack
//Knapsack with Duplicate Items
/*
Problem:
Given weights[] and values[] of items and a knapsack capacity,
find the maximum total value you can obtain.
You are allowed to take each item any number of times (duplicates allowed).

Core Idea (DP – Unbounded Knapsack):
dp[i][j] = maximum value achievable using items from index 0..i
           with knapsack capacity j

At every state, we have two choices:
1) right (notTake):
   Do NOT take the current item
   → dp[i-1][j]

2) left (take):
   Take the current item and stay at the same index
   → val[i] + dp[i][j - wt[i]]
   (same index because items can be taken unlimited times)

We take the maximum of both:
dp[i][j] = max(left, right)

Base Case:
If i == 0 (only item 0 available):
- We can take item 0 as many times as possible
- Number of times = j / wt[0]
- dp[0][j] = (j / wt[0]) * val[0]

Approaches implemented:

1) Recursion:
   Tries both choices (take / notTake) at each step.
   Very slow due to repeated subproblems.

2) Memoization (Top-Down DP):
   Stores results of dp[i][capacity] to avoid recomputation.
   Time Complexity: O(n * capacity)
   Space Complexity: O(n * capacity)

3) Tabulation (Bottom-Up DP):
   Builds the DP table iteratively.
   Transition:
     right = dp[i-1][j]
     left  = val[i] + dp[i][j - wt[i]]
   dp[i][j] = max(left, right)

4) Space Optimization:
   Observation:
   dp[i][j] depends only on:
   - prev[j]        → dp[i-1][j]
   - curr[j-wt[i]]  → dp[i][j - wt[i]] (same row, unlimited usage)

   So we use two 1D arrays:
   prev → previous row
   curr → current row

Difference from 0/1 Knapsack:
- 0/1 Knapsack → item can be taken at most once (i-1 used after take)
- Unbounded Knapsack → item can be taken unlimited times (i remains same)

Final Answer:
dp[n-1][capacity] or prev[capacity] gives the maximum obtainable value.
*/

class Solution {
  public:
    int recursion(int i,int capacity, vector<int> &val, vector<int> &wt){
       if(i==0){
       if(wt[0]<=capacity)return ((capacity/wt[0])*val[0]);
       else return 0;
       } 
       int right=recursion(i-1,capacity,val,wt);
       int left=INT_MIN;
       if (capacity >= wt[i]) {
        left = val[i] + recursion(i, capacity - wt[i], val, wt);
        }
       return max(left,right);
    }
    int memo(int i,int capacity, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
       if(i==0){
        if(wt[0]<=capacity)return ((capacity/wt[0])*val[0]);
        else return 0;
       }
       if(dp[i][capacity]!=-1) return dp[i][capacity];
       int right=memo(i-1,capacity,val,wt,dp);
       int left=INT_MIN;
       if(capacity>=wt[i]){
        left=val[i]+memo(i,capacity-wt[i],val,wt,dp);   
       }
       return dp[i][capacity]=max(left,right);
    }
    int tabulation(int n,int capacity, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        for (int j = 0; j <= capacity; j++) {
        if (wt[0] <= j)
            dp[0][j] = ((j/wt[0])*val[0]);
        else
            dp[0][j] = 0;
        }

      for(int i=1;i<n;i++){
          for(int j=0;j<=capacity;j++){
        int right=dp[i-1][j];
       int left=INT_MIN;
       if(j>=wt[i]){
        left=val[i]+dp[i][j-wt[i]];   
       }
       dp[i][j]=max(left,right);  
         }
      }
      return dp[n-1][capacity];
    }
    
    int spaceOptimization(int n,int capacity, vector<int> &val, vector<int> &wt){
        vector<int> prev(capacity+1,-1);
        vector<int> curr(capacity+1,-1);
        for (int j = 0; j <= capacity; j++) {
        if (wt[0] <= j)
            prev[j] = ((j/wt[0])*val[0]);
        else
            prev[j] = 0;
        }
    
      for(int i=1;i<n;i++){
          for(int j=0;j<=capacity;j++){
        int right=prev[j];
       int left=INT_MIN;
       if(j>=wt[i]){
        left=val[i]+curr[j-wt[i]];   
       }
       curr[j]=max(left,right);  
         }
        prev=curr;
      }
      return prev[capacity];
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    int n=val.size();
    vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
    //return recursion(n-1,capacity,val,wt);
    //return memo(n-1,capacity,val,wt,dp);
    return tabulation(n,capacity,val,wt,dp);  
    //return spaceOptimization(n,capacity,val,wt);   
    }
};