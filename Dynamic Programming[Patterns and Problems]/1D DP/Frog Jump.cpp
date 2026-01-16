//Frog Jump
/*
Problem:
A frog is standing at index 0 and wants to reach the last index (n-1).
Each index has a height given in the array `height`.

From index i, the frog can:
- Jump to i+1 (1 step)
- Jump to i+2 (2 steps)

The cost of a jump from index j to i is:
abs(height[i] - height[j])

Goal:
Find the minimum total cost required for the frog to reach the last index.

--------------------------------------------------
Observation:
--------------------------------------------------
To reach index i, the frog can come from:
- index i-1 (1-step jump)
- index i-2 (2-step jump)

So, the minimum cost to reach index i is:
dp[i] = min(
    abs(height[i] - height[i-1]) + dp[i-1],
    abs(height[i] - height[i-2]) + dp[i-2]
)

--------------------------------------------------
Base Cases:
--------------------------------------------------
- dp[0] = 0 (starting point, no cost)
- dp[1] = abs(height[1] - height[0])

--------------------------------------------------
Approaches Used:
--------------------------------------------------
1) Pure Recursion:
   - Directly applies the recurrence relation.
   - Causes repeated calculations.

   Time Complexity: O(2^n)
   Space Complexity: O(n)

2) Memoization (Top-Down DP):
   - Stores results of overlapping subproblems in a dp array.
   - Avoids repeated recursive calls.

   Time Complexity: O(n)
   Space Complexity: O(n)

3) Tabulation (Bottom-Up DP):
   - Builds the dp array iteratively from base cases.
   - Computes the minimum cost for each index from 0 to n-1.

   Time Complexity: O(n)
   Space Complexity: O(n)

4) Space Optimization:
   - Observes that only the previous two dp values are required.
   - Uses two variables instead of a dp array.

   Time Complexity: O(n)
   Space Complexity: O(1)

--------------------------------------------------
Conclusion:
--------------------------------------------------
The problem is a classic dynamic programming problem where the optimal
solution for each index depends on the previous one or two indices.
The space-optimized approach is the most efficient in practice.
*/


class Solution{
  public:
    // -------------------- 1. Pure Recursion --------------------
    int mincosting(vector<int>& height, int i) {
        if (i == 0) return 0;
        if (i == 1) return abs(height[1] - height[0]);

        int one_gap = abs(height[i] - height[i-1]) + mincosting(height, i-1);
        int two_gap = abs(height[i] - height[i-2]) + mincosting(height, i-2);

        return min(one_gap, two_gap);
    }
    
    // -------------------- 2. Memoization --------------------
    int mincost_dp(vector<int>& height, int i, vector<int>& memo) {
        if (i == 0) return 0;
        if (i == 1) return abs(height[1] - height[0]);

        if (memo[i] != -1) return memo[i];

        int one_gap = abs(height[i] - height[i-1]) + mincost_dp(height, i-1, memo);
        int two_gap = abs(height[i] - height[i-2]) + mincost_dp(height, i-2, memo);

        return memo[i] = min(one_gap, two_gap);
    }
    
    // -------------------- 3. Tabulation --------------------
    int mincost_tab(vector<int>& height, vector<int>& memo) {
        int n = height.size();
        if (n == 1) return 0;

        memo[0] = 0;
        memo[1] = abs(height[1] - height[0]);

        for (int i = 2; i < n; i++) {
            memo[i] = min(
                abs(height[i] - height[i-1]) + memo[i-1],
                abs(height[i] - height[i-2]) + memo[i-2]
            );
        }
        return memo[n - 1];
    }
    
    // -------------------- 4. Space Optimization --------------------
    int mincost_mostopt(vector<int>& height) {
        int n = height.size();
        if (n == 1) return 0;

        int prev2 = 0;                              // dp[0]
        int prev = abs(height[1] - height[0]);     // dp[1]

        for (int i = 2; i < n; i++) {
            int curr = min(
                abs(height[i] - height[i-1]) + prev,
                abs(height[i] - height[i-2]) + prev2
            );
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    // -------------------- Final Function --------------------
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> memo(n, -1);
        //return mincosting(height, n - 1);
        //return mincost_dp(height, n - 1, memo);
        // return mincost_tab(height, memo);
        return mincost_mostopt(height); 
    }
};
