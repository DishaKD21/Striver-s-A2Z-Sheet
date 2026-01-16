//714. Best Time to Buy and Sell Stock with Transaction Fee
/*
second problem we solved where we can do transaction unlimited times this is that only its just in each transactio we have to pay some fees so every time you sell one stock you deduct some fees from profit 
TIME & SPACE COMPLEXITY:

1) Recursion:
We try all possible choices (buy, sell, or skip) for every day.

Time Complexity: O(2^n)
Space Complexity: O(n)   (recursion stack)

------------------------------------------------------------

2) Memoization:
We store the result of each (day, buy) state to avoid
repeated calculations.

Time Complexity: O(n * 2) ≈ O(n)
Space Complexity: O(n * 2) + O(n) recursion stack

------------------------------------------------------------

3) Tabulation:
We build the DP table from the last day to the first day
without using recursion.

Time Complexity: O(n * 2) ≈ O(n)
Space Complexity: O(n * 2)

------------------------------------------------------------

4) Space Optimization:
We only store values of the next day instead of the full DP table.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int recursion(int i, int buy, int n, vector<int>& prices,int fee) {
        if (i == n)
            return 0;
        if (buy) {
            return max(-prices[i] + recursion(i + 1, 0, n, prices,fee),
                       0 + recursion(i + 1, 1, n, prices,fee));
        } else {
            return max(prices[i]-fee + recursion(i + 1, 1, n, prices,fee),
                       0 + recursion(i + 1, 0, n, prices,fee));
        }
    }
    int memo(int i, int buy, int n, vector<int>& prices,
             vector<vector<int>>& dp,int fee) {
        if (i == n)
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        if (buy) {
            return dp[i][buy] = max(-prices[i] + memo(i + 1, 0, n, prices, dp,fee),
                                    0 + memo(i + 1, 1, n, prices, dp,fee));
        } else {
            return dp[i][buy] = max(prices[i]-fee + memo(i + 1, 1, n, prices, dp,fee),
                                    0 + memo(i + 1, 0, n, prices, dp,fee));
        }
    }
    int tabulation(int ind, int buy, int n, vector<int>& prices,
                   vector<vector<int>>& dp,int fee) {
        dp[n][0] = 0;
        dp[n][1] = 0;
        for (int i = n - 1; i >= ind; i--) {
            for (int j = 0; j <= buy; j++) {
                if (j) {
                    dp[i][j] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                } else {
                    dp[i][j] = max(prices[i]-fee + dp[i + 1][1], 0 + dp[i + 1][0]);
                }
            }
        }
        return dp[ind][buy];
    }

    int spaceOptimization(int ind, int buy, int n, vector<int>& prices, int fee) {
        vector<int> next(2, -1);
        vector<int> curr(2, -1);
        next[0] = next[1] = 0;
        for (int i = n - 1; i >= ind; i--) {
            for (int j = 0; j <= buy; j++) {
                if (j) {
                    curr[j] = max(-prices[i] + next[0], 0 + next[1]);
                } else {
                    curr[j] = max(prices[i]-fee + next[1], 0 + next[0]);
                }
            }
            next = curr;
        }
        return next[buy];
    }

    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        //return recursion(0,1,n,prices,fee);
        return memo(0,1,n,prices,dp,fee);
        // return tabulation(0,1,n,prices,dp,fee);
        //return spaceOptimization(0, 1, n, prices,fee);
    }
};