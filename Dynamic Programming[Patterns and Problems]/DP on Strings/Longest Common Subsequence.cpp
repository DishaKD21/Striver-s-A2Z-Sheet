//1143. Longest Common Subsequence
/*
Given two strings text1 and text2, return the length
of their longest common subsequence.
A subsequence:
- Maintains relative order
- Characters need NOT be contiguous

We define a function f(i, j) which represents:
→ LCS length between text1 starting at index i
  and text2 starting at index j.

At every position (i, j), we have two cases:

1) If text1[i] == text2[j]:
   - This character can be part of the LCS
   - So we include it and move both pointers
   - Answer = 1 + f(i+1, j+1)

2) If text1[i] != text2[j]:
   - We have a choice:
     a) Skip current char from text1 → f(i+1, j)
     b) Skip current char from text2 → f(i, j+1)
   - We take the maximum of both choices

Base Case:
- If either string is exhausted (i == len(text1) or j == len(text2))
  → No subsequence possible, return 0

-----------------------------------------------------
1) RECURSION (TOP-DOWN)
Function:
recursion(i, j)
Time Complexity:
O(2^(n + m))  => (Exponential, TLE)

Space Complexity:
O(n + m)     => (Recursive call stack)

Reason:
- Each state branches into two recursive calls
- Many overlapping subproblems

-----------------------------------------------------
2) MEMOIZATION (TOP-DOWN DP)
Idea:
- Store results of f(i, j) in a DP table
- If dp[i][j] already computed, reuse it
DP State:
dp[i][j] = LCS length for text1[i:], text2[j:]
Time Complexity:
O(n * m)
Space Complexity:
O(n * m)  (DP table)
O(n + m)  (Recursion stack)
Benefit:
- Eliminates recomputation of overlapping states
-----------------------------------------------------
3) TABULATION (BOTTOM-UP DP)
Idea:
- Build the solution iteratively from the end
- No recursion used
DP Table:
dp[i][j] = LCS of text1[i:], text2[j:]
Transition:
If text1[i] == text2[j]:
    dp[i][j] = 1 + dp[i+1][j+1]
Else:
    dp[i][j] = max(dp[i+1][j], dp[i][j+1])
Base:
Last row and last column initialized to 0
Final Answer:
dp[0][0]
Time Complexity:
O(n * m)
Space Complexity:
O(n * m)
-----------------------------------------------------
4) SPACE OPTIMIZATION (BEST SOLUTION)
Observation:
- dp[i][j] depends only on:
  dp[i+1][j], dp[i][j+1], dp[i+1][j+1]
So we only need:
- current row
- next row
Implementation:
- Use two 1D arrays: curr and next
Time Complexity:
O(n * m)
Space Complexity:
O(m)    (Optimized)
*/

class Solution {
public:
    int recursion(int i, int j, string& text1, string& text2, int l1, int l2) {
        if (i == l1 || j == l2)
            return 0;
        if (text1[i] == text2[j]) {
            // cout<<text1[i]<<text2[j];
            return 1 + recursion(i + 1, j + 1, text1, text2, l1, l2);
        } else {
            return max(recursion(i + 1, j, text1, text2, l1, l2),
                       recursion(i, j + 1, text1, text2, l1, l2));
        }
    }
    int memo(int i, int j, string& text1, string& text2, int l1, int l2,
             vector<vector<int>> dp) {
        if (i == l1 || j == l2)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (text1[i] == text2[j]) {
            // cout<<text1[i]<<text2[j];
            return dp[i][j] = 1 + memo(i + 1, j + 1, text1, text2, l1, l2, dp);
        } else {
            return dp[i][j] = max(memo(i + 1, j, text1, text2, l1, l2, dp),
                                  memo(i, j + 1, text1, text2, l1, l2, dp));
        }
    }
    int tabulation(int i, int j, string& text1, string& text2, int l1, int l2,
                   vector<vector<int>> dp1) {
        for (int i = l1 - 1; i >= 0; i--) {
            for (int j = l2 - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp1[i][j] = 1 + dp1[i + 1][j + 1];
                } else {
                    dp1[i][j] = max(dp1[i + 1][j], dp1[i][j + 1]);
                }
            }
        }
        return dp1[0][0];
    }

    int spaceOptimization(int i, int j, string& text1, string& text2, int l1,
                          int l2) {
        vector<int> next(l2 + 1, 0);
        vector<int> curr(l2 + 1, 0);
        for (int i = l1 - 1; i >= 0; i--) {
            for (int j = l2 - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    curr[j] = 1 + next[j + 1];
                } else {
                    curr[j] = max(next[j], curr[j + 1]);
                }
            }
            next = curr;
        }
        return curr[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();
        vector<vector<int>> dp(l1, vector<int>(l2, -1));
        vector<vector<int>> dp1(l1 + 1, vector<int>(l2 + 1, 0));
        // return recursion(0,0,text1,text2,l1,l2);
        // return memo(0,0,text1,text2,l1,l2,dp);
        // return tabulation(0,0,text1,text2,l1,l2,dp1);
        return spaceOptimization(0, 0, text1, text2, l1, l2);
    }
};