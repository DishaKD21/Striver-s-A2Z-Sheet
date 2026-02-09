//547. Number of Provinces
/*
1. The given input is an adjacency matrix `isConnected`,
   where isConnected[i][j] = 1 means city i is directly connected to city j.

2. Since graph traversal (DFS/BFS) is easier with an adjacency list,
   we first convert the adjacency matrix into an adjacency list.
  - If isConnected[i][j] == 1 and i != j,
    then add an undirected edge between i and j.

3. We maintain a visited array to keep track of cities
   that are already included in some province.

4. We iterate through all cities:
   - If a city is not visited, it means we found a new province.
   - We start a DFS from that city and mark all cities
     reachable from it as visited.
   - Increment the province count by 1.

5. The DFS function recursively visits all directly
   or indirectly connected cities, ensuring that
   each connected component is counted as one province.

6. Finally, the count of DFS calls gives the number of provinces.

Time Complexity:
- O(n²) due to traversal of the adjacency matrix.

Space Complexity:
- O(n) for visited array and recursion stack.

This approach correctly counts the number of connected components
(provinces) in an undirected graph.
*/

class Solution {
public:
    void adjlist(vector<vector<int>>& isConnected, vector<vector<int>> &adj){
       for(int i=0;i<isConnected.size();i++){
        for(int j=0;j<isConnected[0].size();j++){
          if(isConnected[i][j]==1 && i!=j){
            adj[i].push_back(j);
            adj[j].push_back(i);
          }  
        }
       } 
    }
    void f(int n,vector<vector<int>>& adj,vector<bool>& visited) {
        visited[n] = true;
        for (int i : adj[n]) {
            if (!visited[i]) {
                f(i, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> visited(n);
        vector<vector<int>> adj(n);
        adjlist(isConnected,adj);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                f(i, adj, visited);
                count++;
            }
        }
        return count;
    }
};