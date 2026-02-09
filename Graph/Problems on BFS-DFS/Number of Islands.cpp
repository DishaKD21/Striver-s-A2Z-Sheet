// 200. Number of Islands
/*
Approach:
- We traverse the entire grid.
- Whenever we find a cell with value '1' that has not been visited,
we start a Breadth-First Search (BFS) from that cell.
- Each BFS marks all connected '1's (land cells) as visited.
- Each BFS call corresponds to one complete island, so we increment
the island count.


BFS Details:
- A queue is used to explore neighboring land cells level by level.
- We only move in 4 directions (up, down, left, right), as required
by the problem.
- For each cell, we check:
1. The new cell is within grid boundaries.
2. The cell has not been visited before.
3. The cell contains land ('1').
- Valid neighboring cells are pushed into the queue and marked visited
to avoid revisiting.


Why visited matrix is used:
- To ensure each cell is processed only once.
- Prevents infinite loops and redundant BFS calls.


Time Complexity:
- O(m * n), where m = number of rows, n = number of columns.
- Each cell is visited at most once.


Space Complexity:
- O(m * n) in the worst case due to the visited matrix and BFS queue.
*/
class Solution {
public:
    void bfs(pair<int, int> ind, vector<vector<bool>>& visited,
             vector<vector<char>>& grid, int n, int m) {
        queue<pair<int, int>> q;
        q.push(ind);
        visited[ind.first][ind.second] = true;
        vector<int> row = {-1, 0, 0, 1};
        vector<int> col = {0, -1, 1, 0};
        while (!q.empty()) {
            pair<int, int> index = q.front();
            int i = index.first;
            int j = index.second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nrow = i + row[k];
                int ncol = j + col[k];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    visited[nrow][ncol] != true && grid[nrow][ncol] == '1') {
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        int count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    bfs({i, j}, visited, grid, n, m);
                    count++;
                }
            }
        }
        return count;
    }
};