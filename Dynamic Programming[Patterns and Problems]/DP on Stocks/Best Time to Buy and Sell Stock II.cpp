//Best Time to Buy and Sell Stock II
/*
PROBLEM: Best Time to Buy and Sell Stock II
(You can perform unlimited transactions, but must sell before buying again)

--------------------------------------------------
STATE DEFINITION (Core DP Idea):
At any day i, I have two states:
- buy = 1 → I am allowed to buy a stock
- buy = 0 → I am holding a stock and can sell

The answer depends on:
(index i, whether I can buy or not)

--------------------------------------------------
RECURSION:
At each day i:
1) If buy == 1:
   - Buy the stock today → -prices[i] + solve(i+1, 0)
   - Skip today → solve(i+1, 1)
   Take the maximum of both.

2) If buy == 0:
   - Sell the stock today → prices[i] + solve(i+1, 1)
   - Skip today → solve(i+1, 0)
   Take the maximum of both.

Base case:
- If i == n (past last day), profit = 0.

This tries all possible buy/sell choices.
Time: O(2^n), Space: O(n) (recursion stack)

--------------------------------------------------
MEMOIZATION:
Same recursion, but store results in dp[i][buy]
to avoid recalculating overlapping subproblems.
Time: O(n × 2), Space: O(n × 2) + O(n) stack

--------------------------------------------------
TABULATION (Bottom-Up DP):
Base case:
- dp[n][0] = dp[n][1] = 0 (no days left → no profit)

Build the table from day n-1 down to 0:
- For each day, compute profit for both buy states
- dp[i][buy] is calculated using dp[i+1][*]

Final answer is dp[0][1].
Time: O(n × 2), Space: O(n × 2)

--------------------------------------------------
SPACE OPTIMIZATION:
Observation:
- dp[i] depends only on dp[i+1]
- So instead of full table, keep two arrays:
  - next → dp[i+1]
  - curr → dp[i]

For each day:
- Compute curr[buy] using next
- Move curr into next

Final answer is next[1].
Time: O(n × 2), Space: O(2) ≈ O(1)

--------------------------------------------------
SUMMARY:
Recursion → brute force idea
Memoization → optimized recursion
Tabulation → iterative DP
Space Optimization → best solution

FINAL COMPLEXITY:
Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int recursion(int i, int buy, int n, vector<int>& prices) {
        if (i == n)
            return 0;
        if (buy) {
            return max(-prices[i] + recursion(i + 1, 0, n, prices),
                       0 + recursion(i + 1, 1, n, prices));
        } else {
            return max(prices[i] + recursion(i + 1, 1, n, prices),
                       0 + recursion(i + 1, 0, n, prices));
        }
    }
    int memo(int i, int buy, int n, vector<int>& prices,
             vector<vector<int>>& dp) {
        if (i == n)
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        if (buy) {
            return dp[i][buy] = max(-prices[i] + memo(i + 1, 0, n, prices, dp),
                                    0 + memo(i + 1, 1, n, prices, dp));
        } else {
            return dp[i][buy] = max(prices[i] + memo(i + 1, 1, n, prices, dp),
                                    0 + memo(i + 1, 0, n, prices, dp));
        }
    }
    int tabulation(int ind, int buy, int n, vector<int>& prices,
                   vector<vector<int>>& dp) {
        dp[n][0] = 0;
        dp[n][1] = 0;
        for (int i = n - 1; i >= ind; i--) {
            for (int j = 0; j <= buy; j++) {
                if (j) {
                    dp[i][j] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                } else {
                    dp[i][j] = max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
                }
            }
        }
        return dp[ind][buy];
    }

    int spaceOptimization(int ind, int buy, int n, vector<int>& prices) {
        vector<int> next(2, -1);
        vector<int> curr(2, -1);
        next[0] = next[1] = 0;
        for (int i = n - 1; i >= ind; i--) {
            for (int j = 0; j <= buy; j++) {
                if (j) {
                    curr[j] = max(-prices[i] + next[0], 0 + next[1]);
                } else {
                    curr[j] = max(prices[i] + next[1], 0 + next[0]);
                }
            }
            next = curr;
        }
        return next[buy];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        // return recursion(0,1,prices.size(),prices);
        // return memo(0,1,n,prices,dp);
        // return tabulation(0,1,n,prices,dp);
        return spaceOptimization(0, 1, n, prices);
    }
};