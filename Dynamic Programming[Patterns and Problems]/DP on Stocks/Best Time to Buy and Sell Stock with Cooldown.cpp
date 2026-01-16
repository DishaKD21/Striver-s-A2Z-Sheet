//309. Best Time to Buy and Sell Stock with Cooldown
/*
in this there is nothing more new than previous problem just waiting for cooldown period means moving to next's next index because we have to wait for cooldown period we cannot buy another stock on next day if we sold today so we can buy after skipping 1 day so in this we are just skipping 1 index after selling stock 

TIME & SPACE COMPLEXITY:

1) Recursion:
We try all possible choices (buy, sell, or skip) for every day.
This leads to many repeated calls.

Time Complexity: O(2^n)
Space Complexity: O(n)  (recursion stack)

------------------------------------------------------------

2) Memoization (Top-Down DP):
We store results of states (day, buy) so each state is solved only once.

Time Complexity: O(n * 2) ≈ O(n)
Space Complexity: O(n * 2) + O(n) recursion stack

------------------------------------------------------------

3) Tabulation (Bottom-Up DP):
We build the DP table from the last day to the first day.
No recursion is used.

Time Complexity: O(n * 2) ≈ O(n)
Space Complexity: O(n * 2)

------------------------------------------------------------

4) Space Optimization:
We only store values of the next day and the day after next
because of the cooldown condition.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int recursion(int i, int buy, int n, vector<int>& prices) {
        if (i >= n) return 0;
        if (buy) {
            return max(-prices[i] + recursion(i + 1, 0, n, prices),
                       0 + recursion(i + 1, 1, n, prices));
        } else {
            return max(prices[i] + recursion(i + 2, 1, n, prices),
                       0 + recursion(i + 1, 0, n, prices));
        }
    }
    int memo(int i, int buy, int n, vector<int>& prices,
             vector<vector<int>>& dp) {
        if (i >= n)
            return 0;
        if (dp[i][buy] != -1)return dp[i][buy];
        if (buy) {
            return dp[i][buy] = max(-prices[i] + memo(i + 1, 0, n, prices, dp),
                                    0 + memo(i + 1, 1, n, prices, dp));
        } else {
            return dp[i][buy] = max(prices[i] + memo(i + 2, 1, n, prices, dp),
                                    0 + memo(i + 1, 0, n, prices, dp));
        }
    }
    int tabulation(int ind, int buy, int n, vector<int>& prices,
                   vector<vector<int>>& dp1) {
        for(int i = n - 1; i >= ind; i--) {
            for (int j = 0; j <= buy; j++) {
                if (j) {
                    dp1[i][j] = max(-prices[i] + dp1[i + 1][0], 0 + dp1[i + 1][1]);
                } else {
                    dp1[i][j] = max(prices[i] + dp1[i + 2][1], 0 + dp1[i + 1][0]);
                }
            }
        }
        return dp1[ind][buy];
    }

    int spaceOptimization(int ind, int buy, int n, vector<int>& prices) {
        vector<int> next1(2, 0);
        vector<int> curr(2, 0);
        vector<int> next2(2, 0);
        for(int i = n - 1; i >= ind; i--) {
            for (int j = 0; j <= buy; j++) {
                if (j) {
                    curr[j] = max(-prices[i] + next1[0], 0 + next1[1]);
                } else {
                    curr[j] = max(prices[i] + next2[1], 0 + next1[0]);
                }
            }
        next2=next1;
        next1=curr;
        }
        return curr[buy];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2, -1));
        vector<vector<int>> dp1(n + 2 , vector<int>(2, 0));
        //return recursion(0,1,prices.size(),prices);
        return memo(0,1,n,prices,dp);
        //return tabulation(0,1,n,prices,dp1);
        //return spaceOptimization(0, 1, n, prices);
    }
};