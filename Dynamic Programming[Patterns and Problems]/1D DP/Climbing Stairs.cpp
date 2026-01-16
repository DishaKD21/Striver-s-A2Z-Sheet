//70. Climbing Stairs
/*
Problem:
You are climbing a staircase with `n` steps.
Each time, you can climb either:
- 1 step
- 2 steps

Return the number of distinct ways to reach the top.

--------------------------------------------------
Key Observation:
--------------------------------------------------
To reach step `n`:
- You can come from step `n-1` by taking 1 step
- You can come from step `n-2` by taking 2 steps

So the total number of ways to reach step `n` is:
ways(n) = ways(n-1) + ways(n-2)

This is why the problem looks similar to Fibonacci.

--------------------------------------------------
Base Cases:
--------------------------------------------------
- ways(0) = 1   → one way to stay at the ground
- ways(1) = 1   → one way: take 1 step

--------------------------------------------------
Approach 1: Simple Recursion
--------------------------------------------------
- Recursively count ways to reach `n-1` and `n-2`
- This causes repeated calculations

Time Complexity: O(2^n)
Space Complexity: O(n)

--------------------------------------------------
Approach 2: Memoization (Top-Down DP)
--------------------------------------------------
- Store results of already solved subproblems
- Avoids repeated recursive calls

Steps:
- If dp[n] already computed → return it
- Else compute dp[n] = dp[n-1] + dp[n-2]

Time Complexity: O(n)
Space Complexity: O(n)

--------------------------------------------------
Approach 3: Tabulation (Bottom-Up DP)
--------------------------------------------------
- Build the solution iteratively from base cases
- dp[i] = number of ways to reach step i

Initialization:
- dp[0] = 1
- dp[1] = 1

Transition:
- dp[i] = dp[i-1] + dp[i-2]

Time Complexity: O(n)
Space Complexity: O(n)

--------------------------------------------------
Approach 4: Space Optimization
--------------------------------------------------
- Only last two values are needed
- Use two variables instead of dp array

Time Complexity: O(n)
Space Complexity: O(1)

--------------------------------------------------
Conclusion:
--------------------------------------------------
Climbing Stairs is a counting problem, not a Fibonacci problem.
It only *resembles* Fibonacci due to similar recurrence.
*/

class Solution {
public:
    int recursive(int n){
        if(n <= 1) return 1;
        return recursive(n-1) + recursive(n-2);
    }

    int dpMemo(int n, vector<int>& dp){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = dpMemo(n-1, dp) + dpMemo(n-2, dp);
    }

    int tabulation(int n, vector<int>& dp){
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int spaceOptimization(int n){
        if(n <= 1) return 1;
        int prev1 = 1, prev2 = 1;
        for(int i = 2; i <= n; i++){
            int curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        //return recursive(n);
        //return dpMemo(n, dp);
        //return tabulation(n, dp);
        return spaceOptimization(n);
    }
};