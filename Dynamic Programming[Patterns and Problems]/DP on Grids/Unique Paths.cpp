//62. Unique Paths
/*
Approach Explanation:

This problem asks for the total number of unique paths from the
top-left cell (0,0) to the bottom-right cell (m-1,n-1) in a grid,
where movement is allowed only to the RIGHT or DOWN.

The solution is built step-by-step using Dynamic Programming,
starting from a naive recursive approach and then optimizing it
for time and space.

1) Recursion:
   - Start from the destination cell (row-1, col-1) and move backwards.
   - From each cell, we can reach it either from:
       a) the cell on the left
       b) the cell above
   - Base cases:
       • If we reach (0,0), there is exactly 1 valid path.
       • If row or column becomes negative, return 0 (invalid path).
   - The total paths for a cell is the sum of paths from left and up.
   - This approach has exponential time complexity and is not efficient.

2) Memoization (Top-Down DP):
   - Improves recursion by storing results of subproblems in a DP array.
   - If a cell’s value is already computed, it is reused.
   - This avoids repeated recursive calls.
   - Time complexity reduces to O(m × n).
   - Space complexity is O(m × n) for the DP table plus recursion stack.

3) Tabulation (Bottom-Up DP):
   - Builds the solution iteratively from the starting cell (0,0).
   - dp[i][j] represents the number of unique paths to reach cell (i,j).
   - Transition:
       dp[i][j] = dp[i-1][j] + dp[i][j-1]
   - Boundary conditions:
       • First row can only be reached from the left.
       • First column can only be reached from above.
   - Time complexity: O(m × n)
   - Space complexity: O(m × n)

4) Space Optimization:
   - Observes that each row depends only on the previous row.
   - Uses two 1D arrays:
       • prev[] for the previous row
       • curr[] for the current row
   - After processing each row, curr becomes prev.
   - This reduces space complexity to O(n), where n is the number of columns.

Final Decision:
   - Any of the approaches can solve the problem, but memoization,
     tabulation, or space optimization are preferred due to efficiency.
   - The final implementation uses memoization for clarity and optimal performance.

Time Complexity:  O(m × n)
Space Complexity: O(m × n) (memoization) or O(n) (space optimized)
*/

class Solution {
public:
int recursion(int row,int col){
       if(row==0 && col==0) return 1;
       if(row<0 || col<0) return 0;
       int left = recursion(row,col-1);
       int up = recursion(row-1,col);
       return left + up;
    }

int memo(int row,int col,vector<vector<int>> &dp){
       if(row==0 && col==0) return 1;
       if(row<0 || col<0) return 0;
       if(dp[row][col]!=-1) return dp[row][col];
       int left = memo(row,col-1,dp);
       int up =  memo(row-1,col,dp);
       return dp[row][col]= left+up;
    }

int tabulation(int row, int col, vector<vector<int>> &dp1) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            if (i == 0 && j == 0) {
                dp1[i][j] = 1;
            } 
            else {
                int up = (i > 0) ? dp1[i - 1][j] : 0;
                int left = (j > 0) ? dp1[i][j - 1] : 0;

                dp1[i][j] =  up + left;
            }
        }
    }
    return dp1[row - 1][col - 1];
}
int SpaceOptimization(int row, int col) {
    vector<int> prev(col,0);
    vector<int> curr(col,0);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 && j == 0) {
                curr[j] = 1;
            } 
            else {
                int up = (i > 0) ? prev[j] : 0;
                int left = (j > 0) ? curr[j - 1] : 0;
                curr[j] = up + left;
            }
        }
        prev=curr;
    }
    return prev[col-1];
}
    int uniquePaths(int m, int n){
    int row=m;
    int col=n;
    vector<vector<int>> dp(row,vector<int>(col,-1));
    vector<vector<int>> dp1(row+1, vector<int>(col+1, 0));
    //return recursion(row-1,col-1);   
    return memo(row-1,col-1,dp);
    //return tabulation(row,col,dp1);
    //return SpaceOptimization(row,col);
    }
};