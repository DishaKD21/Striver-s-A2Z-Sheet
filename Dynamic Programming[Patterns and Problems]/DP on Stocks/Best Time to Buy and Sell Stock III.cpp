//Best Time to Buy and Sell Stock III
/*
1) Recursion:
We start from day 0 and at each day we decide whether to buy, sell, or skip.
We keep three things in mind:
- current day index
- whether we can buy or must sell
- how many transactions are left (max 2)
If we buy, we subtract the price.
If we sell, we add the price and reduce the transaction count.
The recursion stops when days are over or no transactions are left.

Time Complexity: O(2^n)  (because of all possible choices)
Space Complexity: O(n)   (recursive call stack)

------------------------------------------------------------

2) Memoization (Top-Down DP):
In recursion, many states repeat. So we store the result of each state
defined by (day, buy, transactions left) in a 3D DP array.
Whenever the same state appears again, we reuse the stored result
instead of recalculating it.

Time Complexity: O(n * 2 * 3) ≈ O(n)
Space Complexity: O(n * 2 * 3) + O(n) recursion stack

------------------------------------------------------------

3) Tabulation (Bottom-Up DP):
Instead of recursion, we build the DP table from the last day to the first day.
We fill dp[i][buy][cap] using values from dp[i+1].
This avoids recursion and directly gives the answer at dp[0][1][2].

Time Complexity: O(n * 2 * 3) ≈ O(n)
Space Complexity: O(n * 2 * 3)

------------------------------------------------------------

4) Space Optimization:
We observe that the DP value of day i only depends on day i+1.
So instead of storing the whole DP table, we keep only two 2×3 arrays:
one for the current day and one for the next day.
This reduces the space usage significantly.

Time Complexity: O(n)
Space Complexity: O(2 * 3) ≈ O(1)

------------------------------------------------------------

Final Answer:
The maximum profit is obtained starting from day 0,
with permission to buy and 2 transactions available.
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
       vector<vector<int>> next(2, vector<int>(3, 0));
       vector<vector<int>> curr(2, vector<int>(3, 0));
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
        return curr[buy][count];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        vector<vector<vector<int>>> dp1(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        //return recursion(0,1,n,2,prices);
        //return memo(0,1,n,2,prices,dp);
        //return tabulation(0,1,n,2,prices,dp1);
        return spaceOptimization(0, 1, n,2, prices);
    }
};