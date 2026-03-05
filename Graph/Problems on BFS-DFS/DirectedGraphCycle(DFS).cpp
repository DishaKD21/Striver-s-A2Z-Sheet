//Directed Graph Cycle
/*
Approach:
---------
We detect a cycle in a Directed Graph using DFS and recursion stack tracking.

Key Idea:
---------
In a directed graph, a cycle exists if during DFS traversal,
we reach a node that is already present in the current recursion path.

To track this, we use two arrays:

1. visited[] → marks nodes that have been fully processed.
2. path[]    → marks nodes currently in the DFS recursion stack.

Algorithm Steps:
----------------
1. Convert the given edge list into an adjacency list.

2. Initialize:
   visited[V] = false
   path[V] = false

3. For each unvisited node:
   - Start DFS from that node.

4. Inside DFS:
   - Mark current node as visited.
   - Mark current node in path (recursion stack).

   - For each neighbor:
       a) If neighbor is not visited:
            → Recursively call DFS.
            → If recursion returns true, cycle exists.
       b) If neighbor is already in path:
            → Cycle detected (back edge found).
            → Return true.

   - After exploring all neighbors,
     remove current node from path (backtracking).

5. If no cycle found in any component → return false.

Why This Works:
---------------
In a directed graph, a cycle exists if we find a back edge.
A back edge is when we visit a node that is already in
the current recursion stack (path array).

Time Complexity:
O(V + E)

Space Complexity:
O(V)
  - visited array
  - path array
  - recursion stack
*/

class Solution {
  public:
    bool dfs(int src, vector<bool>&path, vector<bool> &visited, vector<vector<int>>&adj_list){
       visited[src]=true ;
       path[src]=true;
       for(int nb:adj_list[src]){
        if(visited[nb]==false){
         if(dfs(nb,path,visited,adj_list)==true)return true;
        }
        else if(path[nb]==true){
          return true;   
        }
       }
    path[src]=false;
     return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges){
    vector<vector<int>> adj_list(V);
    for(vector<int> edge:edges){
        int u=edge[0],v=edge[1];
        adj_list[u].push_back(v);
    } 
    vector<bool> path(V,false);
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
    if(visited[i]==false){
       if(dfs(i,path,visited,adj_list)==true)return true;
    }
    }
    return false;
    }
};
