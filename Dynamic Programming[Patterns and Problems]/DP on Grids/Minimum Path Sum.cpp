// 64. Minimum Path Sum
/*
Approach Explanation:

This problem is solved using Dynamic Programming by moving
from the top-left cell (0,0) to the bottom-right cell (row-1,col-1),
where at each cell we are allowed to move only RIGHT or DOWN.

The goal is to find the minimum sum path.

1) Recursion:
   - Start from (row-1, col-1) and move backwards.
   - At each cell, choose the minimum of:
       a) coming from the left cell
       b) coming from the upper cell
   - Base case:
       • When at (0,0), return grid[0][0]
       • If index goes out of bounds, return a very large value (INT_MAX)
   - This approach has exponential time complexity.

2) Memoization:
   - Optimizes recursion by storing already computed results in a DP array.
   - Prevents repeated calculations of the same subproblems.
   - Time complexity becomes O(row * col).
   - Space complexity is O(row * col) for the DP table + recursion stack.

3) Tabulation (Bottom-Up DP):
   - Builds the solution iteratively from top-left to bottom-right.
   - dp[i][j] stores the minimum path sum to reach cell (i,j).
   - Transition:
       dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
   - Special handling for first row and first column using boundary checks.
   - Time complexity: O(row * col)
   - Space complexity: O(row * col)

4) Space Optimization:
   - Instead of a full 2D DP table, only two 1D arrays are used:
       • prev[] -> stores the previous row
       • curr[] -> stores the current row
   - Since each cell depends only on the top and left values,
     previous row data is sufficient.
   - After completing a row, curr becomes prev.
   - This reduces space complexity to O(col).

Final Choice:
   - The space optimized approach is used in minPathSum()
     because it provides optimal time and space efficiency.

Time Complexity:  O(row * col)
Space Complexity: O(col)
*/

class Solution {
public:
long long recursion(int row,int col,vector<vector<int>> & grid){
       if(row==0 && col==0) return grid[row][col];
       if(row<0 || col<0) return INT_MAX;
       long long left = grid[row][col] + recursion(row,col-1,grid);
       long long up =  grid[row][col] + recursion(row-1,col,grid);
       return min(left, up);
    }

long long memo(int row,int col,vector<vector<int>> & grid,vector<vector<int>> &dp){
       if(row==0 && col==0) return grid[row][col];
       if(row<0 || col<0) return INT_MAX;
       if(dp[row][col]!=-1) return dp[row][col];
       long long left = grid[row][col] + memo(row,col-1,grid,dp);
       long long up =  grid[row][col] + memo(row-1,col,grid,dp);
       return dp[row][col]= min(left, up);
    }

int tabulation(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp1) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {

            if (i == 0 && j == 0) {
                dp1[i][j] = grid[i][j];
            } 
            else {
                int up = (i > 0) ? dp1[i - 1][j] : INT_MAX;
                int left = (j > 0) ? dp1[i][j - 1] : INT_MAX;

                dp1[i][j] = grid[i][j] + min(up, left);
            }
        }
    }
    return dp1[row - 1][col - 1];
}
int SpaceOptimization(int row, int col, vector<vector<int>> &grid) {
    vector<int> prev(col,0);
    vector<int> curr(col,0);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 && j == 0) {
                curr[j] = grid[i][j];
            } 
            else {
                int up = (i > 0) ? prev[j] : INT_MAX;
                int left = (j > 0) ? curr[j - 1] : INT_MAX;
                curr[j] = grid[i][j] + min(up, left);
            }
        }
        prev=curr;
    }
    return prev[col-1];
}
int minPathSum(vector<vector<int>>& grid) {
    int row=grid.size();
    int col=grid[0].size();
    vector<vector<int>> dp(row,vector<int>(col,-1));
    vector<vector<int>> dp1(row+1, vector<int>(col+1, 0));
    //return recursion(row-1,col-1,grid);   
    //return memo(row-1,col-1,grid,dp);
    //return tabulation(row,col,grid,dp1);
    return SpaceOptimization(row,col,grid);
    }
};