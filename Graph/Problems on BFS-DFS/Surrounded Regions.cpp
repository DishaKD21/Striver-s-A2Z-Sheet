//130. Surrounded Regions
/*
Approach:
---------
This solution solves the "Surrounded Regions" problem using Depth First Search (DFS).

Idea:
-----
Any 'O' that is connected to the boundary (first row, last row, first column, last column)
cannot be flipped to 'X'. Only the 'O's that are completely surrounded by 'X' should be flipped.

Steps:
------
1. Create a visited matrix to keep track of safe 'O' cells.
2. Traverse all boundary cells:
   - First row and last row
   - First column and last column
3. If a boundary cell contains 'O' and is not visited,
   run DFS from that cell.
4. DFS marks all connected 'O's as visited (these are safe and should not be flipped).
5. After marking boundary-connected 'O's, traverse the entire board:
   - If a cell contains 'O' and is NOT visited,
     it means it is surrounded, so flip it to 'X'.
6. Return the modified board.

DFS Logic:
----------
From a given cell, explore its 4 directions (up, down, left, right).
If the neighbor is inside bounds, contains 'O', and is not visited,
recursively call DFS on it.

Time Complexity:
----------------
O(m × n) — each cell is visited at most once.

Space Complexity:
-----------------
O(m × n) — for the visited matrix and recursion stack.

*/
class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<char>> &board,vector<vector<bool>> &visited,vector<int> &row ,vector<int> &col){
       visited[i][j]=true;
       for(int k=0;k<4;k++){
        int nrow = i + row[k];
        int ncol = j + col[k];
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]=='O' && visited[nrow][ncol]==false){
           dfs(nrow,ncol,m,n,board,visited,row,col);  
        }
       }
    }
    void solve(vector<vector<char>>& board)
    {
      int m = board.size();
      int n = board[0].size();
      vector<vector<bool>> visited(m,vector<bool>(n,false));
      vector<int> col = {-1, 1, 0, 0};
      vector<int> row = { 0, 0,-1, 1};
      for(int j=0;j<n;j++){
        if(!visited[0][j] && board[0][j]=='O'){
           dfs(0,j,m,n,board,visited,row,col);
        }
        if(!visited[m-1][j] && board[m-1][j]=='O'){
            dfs(m-1,j,m,n,board,visited,row,col);
        }
      }
      for(int i=0;i<m;i++){
        if(!visited[i][0] && board[i][0]=='O'){
           dfs(i,0,m,n,board,visited,row,col);
        }
        if(!visited[i][n-1] && board[i][n-1]=='O'){
            dfs(i,n-1,m,n,board,visited,row,col);
        }
      }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           if(visited[i][j]==false && board[i][j]=='O') {
            board[i][j] = 'X';
           }
        }
    }
    return;
    }
};