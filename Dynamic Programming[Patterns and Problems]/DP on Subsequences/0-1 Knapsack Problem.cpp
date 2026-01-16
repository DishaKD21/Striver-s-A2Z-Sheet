//0-1 Knapsack Problem
/*
This solution solves the 0–1 Knapsack problem step by step in a simple way. First, recursion is used to understand
the problem. In recursion, for every item we have only two choices: either take the item or do not take it. If we
take the item, we add its value and reduce the remaining capacity by its weight, then move to the previous item.
If we do not take the item, we simply move to the previous item with the same capacity. The base case happens when
we reach the first item. At that time, we check if it can fit in the remaining capacity; if yes, we take it,
otherwise we return 0. This approach works but is slow because the same calculations are repeated many times.

To make it faster, memoization is used. The logic remains the same as recursion, but we store the result of every
state (item index and remaining capacity) in a DP table. Before calculating a state, we check if it is already
computed and reuse it. This avoids repeated work and makes the solution efficient.

After understanding recursion and memoization, tabulation is applied. In tabulation, we build the DP table from
the bottom. First, we initialize the base case for the first item by checking for each capacity whether the item
can be taken or not. Then, for each remaining item and each capacity, we again choose the better option between
taking the item and not taking it. The table is filled step by step, and the last cell of the table gives the
maximum value that can be achieved.

The spaceOptimized function follows the same idea as tabulation and shows how the solution can later be improved to
use less memory. Finally, the knapsack function initializes the DP table and calls the most suitable method to get
the final answer.
*/

class Solution {
  public:
    int recursion(int i,int W, vector<int> &val, vector<int> &wt){
       if(i==0){
       if(wt[0]<=W)return val[0];
       else return 0;
       } 
       int right=recursion(i-1,W,val,wt);
       int left=INT_MIN;
       if(W>=wt[i]){
        left=val[i]+recursion(i-1,W-wt[i],val,wt);   
       }
       return max(left,right);
    }
    int memo(int i,int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
       if(i==0){
        if(wt[0]<=W)return val[0];
        else return 0;
       }
       if(dp[i][W]!=-1) return dp[i][W];
       int right=memo(i-1,W,val,wt,dp);
       int left=INT_MIN;
       if(W>=wt[i]){
        left=val[i]+memo(i-1,W-wt[i],val,wt,dp);   
       }
       return dp[i][W]=max(left,right);
    }
    int tabulation(int n,int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        for (int j = 0; j <= W; j++) {
        if (wt[0] <= j)
            dp[0][j] = val[0];
        else
            dp[0][j] = 0;
        }

      for(int i=1;i<n;i++){
        for(int j=0;j<=W;j++){
        int right=dp[i-1][j];
       int left=INT_MIN;
       if(j>=wt[i]){
        left=val[i]+dp[i-1][j-wt[i]];   
       }
       dp[i][j]=max(left,right);  
         }
      }
      return dp[n-1][W];
    }

    int spaceOptimized(int n,int W, vector<int> &val, vector<int> &wt){
      vector<int> prev(W+1,-1);
      for (int j = 0; j <= W; j++) {
        if (wt[0] <= j)
            prev[j] = val[0];
        else
            prev[j] = 0;
        }
      for(int i=1;i<n;i++){
         vector<int> curr(W+1,-1); 
        for(int j=0;j<=W;j++){
        int right=prev[j];
       int left=INT_MIN;
       if(j>=wt[i]){
        left=val[i]+prev[j-wt[i]];   
       }
       curr[j]=max(left,right);  
        }
        prev=curr;
      }
      return prev[W];
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n=val.size();
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    //return memo(n-1,W,val,wt,dp);
    //return tabulation(n,W,val,wt,dp);
    return spaceOptimized(n,W,val,wt);
    
    }
};