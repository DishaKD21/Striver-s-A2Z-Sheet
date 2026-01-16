//188. Best Time to Buy and Sell Stock IV
/*
Earlier, we were allowed to do at most 2 transactions.
In this problem, we are allowed to do at most k transactions.
So the approach remains the same as the previous stock problems.
We just replace the fixed value 2 with k.

We use the DP state (day, buy, transactions left).
A transaction is counted only when we sell the stock.
If buy = 1, we can buy or skip.
If buy = 0, we can sell or skip.
When we sell, the transaction count is reduced by 1.

------------------------------------------------------------

Recursion:
We try all possible choices for every day.

Time Complexity: O(2^n)
Space Complexity: O(n)  (recursion stack)

------------------------------------------------------------

Memoization:
We store the result of each (day, buy, transactions left) state
to avoid repeated calculations.

Time Complexity: O(n * 2 * k)
Space Complexity: O(n * 2 * k) + O(n) recursion stack

------------------------------------------------------------

Tabulation:
We build the DP table from the last day to the first day
using the same transitions.

Time Complexity: O(n * 2 * k)
Space Complexity: O(n * 2 * k)

------------------------------------------------------------

Space Optimization:
Instead of storing the full DP table, we store only the
current day and next day values.

Time Complexity: O(n * k)
Space Complexity: O(2 * k) ≈ O(k)
*/

class Solution {
public:
    int recursion(int i, int buy, int n,int count, vector<int>& prices) {
        if (i == n || count==0)
            return 0;
        if (buy) {
            return max(-prices[i] + recursion(i + 1, 0, n,count, prices),
                       0 + recursion(i + 1, 1, n,count, prices));
        } else {
            return max(prices[i] + recursion(i + 1, 1, n, count-1,prices),
                       0 + recursion(i + 1, 0, n,count, prices));
        }
    }
    int memo(int i, int buy, int n, int count ,vector<int>& prices,
             vector<vector<vector<int>>> &dp) {
        if (i == n || count==0)
            return 0;
        if (dp[i][buy][count] != -1) return dp[i][buy][count];
        if (buy) {
            return dp[i][buy][count] = max(-prices[i] + memo(i + 1, 0, n,count ,prices, dp),
                                    0 + memo(i + 1, 1, n,count, prices, dp));
        } else {
            return dp[i][buy][count] = max(prices[i] + memo(i + 1, 1, n, count-1,prices, dp),
                                    0 + memo(i + 1, 0, n, count,prices, dp));
        }
    }
    int tabulation(int ind, int buy, int n,int count, vector<int>& prices,
                   vector<vector<vector<int>>> &dp1) {
        // dp[n][0][count] = 0;
        // dp[n][1][count] = 0;
        for (int i = n - 1; i >= ind; i--) {
            for (int j = 0; j <= buy; j++) {
                for(int k=1;k<=count;k++){
                if (j) {
                    dp1[i][j][k] = max(-prices[i] + dp1[i + 1][0][k], 0 + dp1[i + 1][1][k]);
                } else {
                    dp1[i][j][k] = max(prices[i] + dp1[i + 1][1][k-1], 0 + dp1[i + 1][0][k]);
                }
            }
            }
        }
        return dp1[0][buy][count];
    }

    int spaceOptimization(int ind, int buy, int n,int count, vector<int>& prices) {
       vector<vector<int>> next(2, vector<int>(count+1, 0));
       vector<vector<int>> curr(2, vector<int>(count+1, 0));
        for (int i = n - 1; i >= ind; i--) {
            for (int j = 0; j <= buy; j++) {
                for(int k=1;k<=count;k++){
                if (j) {
                    curr[j][k] = max(-prices[i] + next[0][k], 0 + next[1][k]);
                } else {
                    curr[j][k] = max(prices[i] + next[1][k-1], 0 + next[0][k]);
                }
            }
            }
            next=curr;
        }
        return next[1][count];
    }

    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        vector<vector<vector<int>>> dp1(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        //return recursion(0,1,n,k,prices);
        //return memo(0,1,n,k,prices,dp);
        return tabulation(0,1,n,k,prices,dp1);
        //return spaceOptimization(0, 1, n,k, prices);
    }
};