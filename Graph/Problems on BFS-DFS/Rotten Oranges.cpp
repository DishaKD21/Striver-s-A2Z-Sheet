// 994. Rotting Oranges
/*
Approach:
The problem is solved using a multi-source Breadth First Search (BFS). First, all 
initially rotten oranges are pushed into a queue with time 0, and the total number of 
fresh oranges is counted. BFS is then performed level by level, where each rotten orange 
spreads the rot to its adjacent fresh oranges (up, down, left, right). When a fresh orange 
becomes rotten, it is marked as visited, added to the queue with an increased time, and 
counted. During the BFS traversal, the maximum time taken is tracked. After BFS completes, 
if the number of freshly rotted oranges is less than the initial fresh count, it means 
some oranges could not be reached and the answer is -1; otherwise, the maximum time 
represents the minimum time required to rot all oranges.

Time Complexity (TC):
O(m × n)
Each cell in the grid is processed at most once during the BFS traversal.
Checking all 4 directions for every cell is constant work, so the overall
time complexity remains O(m × n), where m is the number of rows and n is
the number of columns.

Space Complexity (SC):
O(m × n)
Extra space is used for the visited matrix and the BFS queue, which in the
worst case can store all cells of the grid.
*/
class Solution {
public:
    int rotting(vector<vector<int>>& visited, vector<vector<int>>& grid, int m,
                int n) {
        queue<pair<pair<int, int>, int>> q1;
        int countfresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q1.push({{i, j}, 0});
                    visited[i][j] = 2;
                } else if (grid[i][j] == 1) {
                    countfresh++;
                }
            }
        }
        int count = 0;
        int maxi = 0;
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, 1, -1};
        while (!q1.empty()) {
            pair<pair<int, int>, int> ind = q1.front();
            int row = ind.first.first;
            int col = ind.first.second;
            int time = ind.second;
            q1.pop();
            maxi = max(maxi, time);
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    visited[nrow][ncol] = 2;
                    q1.push({{nrow, ncol}, time + 1});
                    count++;
                }
            }
        }
        if (count != countfresh)
            return -1;
        return maxi;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        return rotting(visited, grid, m, n);
    }
};