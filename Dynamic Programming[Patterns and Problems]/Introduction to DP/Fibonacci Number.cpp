//Fibonacci Number
/*
Problem:
Find the nth Fibonacci number.
Fibonacci series:
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2)

--------------------------------------------------
Approach 1: Simple Recursion
--------------------------------------------------
- Directly follows the Fibonacci formula.
- For every n, it recursively calculates F(n-1) and F(n-2).
- This causes a lot of repeated calculations.

Time Complexity: O(2^n)
Space Complexity: O(n) (recursion stack)

--------------------------------------------------
Approach 2: Memoization (Top-Down DP)
--------------------------------------------------
- Uses a dp array to store already computed Fibonacci values.
- Before calculating F(n), we check if it is already stored in dp[n].
- This avoids repeated calculations.

Steps:
- If dp[n] != -1 → return dp[n]
- Otherwise, compute and store it

Time Complexity: O(n)
Space Complexity: O(n) (dp array + recursion stack)

--------------------------------------------------
Approach 3: Tabulation (Bottom-Up DP)
--------------------------------------------------
- Builds the solution iteratively from base cases.
- First store dp[0] and dp[1].
- Then compute dp[i] for i = 2 to n.

Time Complexity: O(n)
Space Complexity: O(n) (dp array)

--------------------------------------------------
Approach 4: Space Optimization
--------------------------------------------------
- Observes that only the last two Fibonacci values are needed.
- Instead of a dp array, we use two variables.

Steps:
- prev1 = F(i-2), prev2 = F(i-1)
- curr = prev1 + prev2
- Shift values for next iteration

Time Complexity: O(n)
Space Complexity: O(1)

--------------------------------------------------
Conclusion:
- Recursion is inefficient due to repeated work.
- Memoization and Tabulation optimize it using DP.
- Space Optimization is the best approach in terms of memory.
*/


class Solution {
public:
    int recursive(int n){
        if(n<=1) return n;
       return recursive(n-1)+ recursive(n-2); 
    }

    int dpMemo(int n,vector<int> &dp){
       if(n<=1) return n;
       if(dp[n]!=-1)return dp[n];
       return dp[n]=dpMemo(n-1,dp)+ dpMemo(n-2,dp); 
    }

    int tabulation(int n,vector<int> &dp){
        if (n == 0) return 0;
        dp[0]= 0;
        dp[1]= 1;
        for(int i=2;i<=n;i++){
          dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int spaceOptimization(int n){
        if(n <= 1) return n;
        int prev1 = 0;
        int prev2 = 1;
        for(int i=2;i<=n;i++){
          int curr = prev2 + prev1;
          prev1=prev2;
          prev2=curr;
        }
        return prev2;
    }

    int fib(int n) {
     vector<int> dp(n+1,-1);
     //recursion
     //return recursive(n);
     //for memoization
     //return dpMemo(n,dp);
     //for tabulation
     return tabulation(n,dp);
     //space optimization
     //return spaceOptimization(n);
    }
};