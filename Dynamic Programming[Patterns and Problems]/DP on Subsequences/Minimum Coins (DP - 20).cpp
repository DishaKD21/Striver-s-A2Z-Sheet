//Minimum Coins (DP - 20)
//322. Coin Change
/*
Problem:
Given coins[] with infinite supply and an amount,
find the minimum number of coins needed to make the amount.
Return -1 if it is not possible.

Core Idea (DP - Unbounded Knapsack):
dp[i][j] = minimum coins required to make amount j using coins[0..i]

At every state we have two choices:
1) notTake → skip current coin
   dp[i-1][j]

2) take → use current coin (since unlimited supply, stay on same index)
   1 + dp[i][j - coins[i]]

We take the minimum of both.

Base Case:
If i == 0 (only first coin available):
- If amount % coins[0] == 0 → amount / coins[0]
- Else → INT_MAX (not possible)

INT_MAX is used to represent an impossible state.
We always check sub != INT_MAX before doing (1 + sub) to avoid overflow.

Approaches implemented:
1) Recursion: Exponential time (TLE)
2) Memoization: Top-down DP, O(n * amount)
3) Tabulation: Bottom-up DP, O(n * amount)
4) Space Optimized: Uses only two 1D arrays (prev & curr), O(amount) space

Why space optimization works:
dp[i][j] depends only on:
- prev[j]      → dp[i-1][j]
- curr[j-coin] → dp[i][j - coin] (same row, unlimited coins)

Final Answer:
If result == INT_MAX → return -1
Else → return result
*/