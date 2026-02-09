//63. Unique Paths II
/*
This code solves the "Unique Paths II" problem where a robot starts at the
top-left cell (0,0) of a grid and wants to reach the bottom-right cell.
The robot can move only in two directions: right or down.
Some cells contain obstacles (marked as 1), and the robot cannot pass through them.

Approach Used:
----------------
The solution demonstrates multiple Dynamic Programming approaches
to calculate the number of unique paths while avoiding obstacles.

1. Recursive Approach:
   - The function `recursion()` calculates paths by exploring all possible
     ways to reach the destination using recursion.
   - Base cases:
       • If the current cell is (0,0) and it is not an obstacle, return 1.
       • If indices go out of bounds or the cell has an obstacle, return 0.
   - It recursively calculates paths from the top cell and the left cell.
   - This approach is not efficient due to overlapping subproblems.

2. Memoization (Top-Down DP):
   - The function `memo()` improves recursion by storing already computed
     results in a DP table.
   - If a cell’s value is already computed, it is reused instead of
     recalculating.
   - This avoids repeated work and reduces time complexity.

3. Tabulation (Bottom-Up DP):
   - The function `tabulation()` builds the solution iteratively using a 2D DP array.
   - dp1[i][j] stores the number of unique paths to reach cell (i,j).
   - If a cell contains an obstacle, dp1[i][j] is set to 0.
   - Otherwise, paths are calculated as:
       dp1[i][j] = paths from top + paths from left
   - The final answer is stored in dp1[row-1][col-1].

4. Space Optimization:
   - The function `SpaceOptimization()` reduces space usage by using two
     1D arrays instead of a full 2D DP table.
   - `prev` represents the previous row and `curr` represents the current row.
   - This approach gives the same result as tabulation but uses less memory.

Final Execution:
----------------
The `uniquePathsWithObstacles()` function initializes required variables
and calls the tabulation approach to compute the result efficiently.

Time Complexity:
----------------
• Recursive approach: O(2^(row*col)) (Exponential, not efficient)
• Memoization: O(row * col)
• Tabulation: O(row * col)
• Space Optimized DP: O(row * col)

Space Complexity:
-----------------
• Recursive approach: O(row * col) (recursion stack)
• Memoization: O(row * col)
• Tabulation: O(row * col)
• Space Optimization: O(col)

*/
class Solution {
public:
    int recursion(int row, int col, vector<vector<int>>& obstacleGrid) {
        if (row == 0 && col == 0 && obstacleGrid[0][0] == 0)
            return 1;
        if (row < 0 || col < 0)
            return 0;
        if (obstacleGrid[row][col] == 1)
            return 0;
        int left = recursion(row, col - 1, obstacleGrid);
        int up = recursion(row - 1, col, obstacleGrid);
        return left + up;
    }

    int memo(int row, int col, vector<vector<int>>& dp,
             vector<vector<int>>& obstacleGrid) {
        if (row == 0 && col == 0 && obstacleGrid[0][0] == 0)
            return 1;
        if (row < 0 || col < 0)
            return 0;
        if (obstacleGrid[row][col] == 1)
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];
        int left = memo(row, col - 1, dp, obstacleGrid);
        int up = memo(row - 1, col, dp, obstacleGrid);
        return dp[row][col] = left + up;
    }

    int tabulation(int row, int col, vector<vector<int>>& obstacleGrid,
                   vector<vector<int>>& dp1) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 && j == 0 && obstacleGrid[0][0] == 0) {
                    dp1[0][0] = 1;
                } else {
                    if (obstacleGrid[i][j] == 1) {
                        dp1[i][j] = 0;
                        continue;
                    }
                    int up = (i > 0) ? dp1[i - 1][j] : 0;
                    int left = (j > 0) ? dp1[i][j - 1] : 0;
                    dp1[i][j] = up + left;
                }
            }
        }
        return dp1[row - 1][col - 1];
    }
    int SpaceOptimization(int row, int col ,vector<vector<int>>& obstacleGrid) {
        vector<int> prev(col, 0);
        vector<int> curr(col, 0);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) {
                    curr[j] = 1;
                } else {
                    int up = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? curr[j - 1] : 0;
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[col - 1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        vector<vector<int>> dp1(row + 1, vector<int>(col + 1, 0));
        // return recursion(row-1,col-1,obstacleGrid);
        // return memo(row-1,col-1,dp,obstacleGrid);
        return tabulation(row, col, obstacleGrid, dp1);
        //return SpaceOptimization(row,col,obstacleGrid);
    }
};