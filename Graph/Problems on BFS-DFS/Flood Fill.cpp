//733. Flood Fill
/*
1. The problem asks us to change the color of a starting pixel (sr, sc)
   and all pixels connected to it (4-directionally) that have the same color.

2. First, we store the original color of the starting pixel
   as oldColor = image[sr][sc].

3. If oldColor is already equal to the new color,
   we return the image immediately to avoid unnecessary traversal
   and infinite looping.

4. We use Breadth First Search (BFS) starting from (sr, sc):
   - Initialize a queue and push the starting cell.
   - Mark the starting cell as visited.
   - Change its color to the new color.

5. While the queue is not empty:
   - Pop the front cell (i, j).
   - Explore its 4-directional neighbors
     (up, left, right, down).

6. For each neighboring cell:
   - Check if it lies within the grid boundaries.
   - Check if its color is equal to oldColor.
   - Check if it has not been visited yet.
   - If all conditions are satisfied,
     push the cell into the queue,
     mark it visited,
     and update its color.

7. BFS ensures that all connected pixels having the same original color
   are visited and recolored level by level.

8. Finally, return the updated image.

Time Complexity:
- O(n × m), in the worst case when all pixels are visited once.

Space Complexity:
- O(n × m) for the visited matrix and the BFS queue.

This approach correctly performs flood fill
by replacing the connected component of pixels
with the given new color.
*/
class Solution {
public:
    void bfs(int sr,int sc,int n,int m,vector<vector<int>> &image,vector<vector<bool>> &visited,int color,int oldcolor){
       queue<pair<int,int>> q;
       q.push({sr,sc});
       image[sr][sc]=color;
       visited[sr][sc]=true;
       vector<int> row = {-1,0,0,1};
       vector<int> col = {0,-1,1,0};
       while(!q.empty()){
        pair<int,int> index = q.front();
        int i = index.first;
        int j = index.second;
        q.pop();
        for(int k=0;k<4;k++){
        int nr = row[k] + i;
        int nc = col[k] + j;
        if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==oldcolor &&
         visited[nr][nc]!=true) {     
            q.push({nr,nc});
            image[nr][nc]=color;
            visited[nr][nc]=true;
        }
        }
       }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n=image.size();
    int m=image[0].size();
    int oldcolor=image[sr][sc];
    if (oldcolor == color) return image;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    bfs(sr,sc,n,m,image,visited,color,oldcolor);  
    return image;
    }
};
