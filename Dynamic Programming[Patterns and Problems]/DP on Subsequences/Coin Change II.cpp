//518. Coin Change II
/*
Problem:
Given an array of coins (infinite supply of each coin) and an amount,
return the number of different combinations that make up that amount.
Order of coins does NOT matter.

Core Idea (DP – Unbounded Knapsack, COUNT ways):
dp[i][j] = number of ways to make amount j using coins from index 0..i

At every state, we have two choices:
1) right (notTake):
   Do NOT use the current coin
   → dp[i-1][j]

2) left (take):
   Use the current coin at least once
   → dp[i][j - coins[i]]
   (same index because coins are unlimited)

Total ways:
dp[i][j] = left + right

Base Case:
If i == 0 (only one coin available):
- If amount % coins[0] == 0 → exactly 1 way (use only coin[0])
- Else → 0 ways

Approaches implemented:

1) Recursion:
   Directly tries all possibilities.
   Very slow due to overlapping subproblems.

2) Memoization (Top-Down DP):
   Stores results of dp[i][amount] to avoid recomputation.
   Time Complexity: O(n * amount)
   Space Complexity: O(n * amount)

3) Tabulation (Bottom-Up DP):
   Builds the dp table iteratively.
   dp[0][j] = 1 if j % coins[0] == 0 else 0
   Transition:
     right = dp[i-1][j]
     left  = dp[i][j - coins[i]]
     dp[i][j] = left + right

4) Space Optimization:
   Observations:
   - dp[i][j] depends only on:
     prev[j]        → dp[i-1][j]
     curr[j-coin]   → dp[i][j - coin] (same row, unlimited coins)

   So we use two 1D arrays:
   prev → previous row
   curr → current row

   This reduces space from O(n * amount) to O(amount).

Important Difference from Coin Change I:
- Coin Change I → MINIMUM number of coins → uses min()
- Coin Change II → COUNT number of ways → uses addition

Final Answer:
dp[n-1][amount] or prev[amount] gives total number of combinations.
*/

class Solution {
public:
    int recursion(int i,vector<int> &coins, int amount){
      if(i==0){
       if(amount%coins[i]==0){
        return 1;
       }
       else return 0;
      }
      int right= recursion(i-1,coins,amount);
      int left=0;
      if(amount>=coins[i]){
        left = recursion(i,coins,amount-coins[i]);
      }
      return left+right;
    }
    int memo(int i,vector<int> &coins, int amount,vector<vector<int>> &dp,int n){
       if(i==0){
       if(amount%coins[i]==0){
        return 1;
       }
       else return 0;
      }
      if(dp[i][amount]!=-1) return dp[i][amount];
      int right= memo(i-1,coins,amount,dp,n);
      int left=0;
      if(amount>=coins[i]){
        left = memo(i,coins,amount-coins[i],dp,n);
      }
      return dp[i][amount]=left+right; 
    }
    int tabulation(vector<int> &coins, int amount,vector<vector<int>> &dp,int n){
     for (int j = 0; j <= amount; j++) {
        dp[0][j] = (j % coins[0] == 0);
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=amount;j++){
        int right = dp[i-1][j];
        int left=0;
      if(j>=coins[i]){
        left = dp[i][j-coins[i]];
      }
      dp[i][j]=left+right; 
    }
    }
      return dp[n-1][amount];
    }
    int spaceOptimization(vector<int> &coins, int amount,int n){
    vector<int> prev(amount+1,0);
     for (int j = 0; j <= amount; j++) {
        prev[j] = (j % coins[0] == 0);
    }
    for(int i=1;i<n;i++){
        vector<int> curr(amount+1,0);
        for(int j=0;j<=amount;j++){
        int right = prev[j];
        int left=0;
      if(j>=coins[i]){
        left = curr[j-coins[i]];
      }
      curr[j]=left+right; 
    }
    prev=curr;
    }
      return prev[amount];
    }
    int change(int amount, vector<int>& coins) {
    int n=coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    //return recursion(n-1,coins,amount);
    //return memo(n-1,coins,amount,dp,n);
    return tabulation(coins,amount,dp,n);
    //return spaceOptimization(coins,amount,n);  
    } 
};