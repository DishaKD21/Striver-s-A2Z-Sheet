//Undirected Graph Cycle using dfs
/*
Approach: Cycle Detection in an Undirected Graph using DFS

We are given an undirected graph with V vertices and a list of edges.
The task is to determine whether the graph contains a cycle.

Key Idea:
In an undirected graph, a cycle exists if during DFS traversal we
encounter a visited node that is NOT the parent of the current node.

Algorithm:
1. Convert the edge list into an adjacency list representation
   because it allows efficient traversal of neighbors.
2. Maintain a visited array to track visited vertices.
3. For each vertex from 0 to V-1:
   - If the vertex is not visited, start a DFS from that vertex.
4. DFS function takes three parameters:
   - current node (src)
   - parent node (parent)
   - adjacency list and visited array
5. Inside DFS:
   - Mark the current node as visited.
   - For every adjacent node:
       a) If it is not visited, recursively call DFS.
          If DFS returns true, a cycle is detected.
       b) If it is already visited and is NOT the parent,
          then a back-edge exists, indicating a cycle.
6. If no cycle is found after checking all components,
   return false.

Why the parent check is important:
In an undirected graph, every edge is bidirectional.
So while traversing, we will always encounter the parent again.
Ignoring the parent prevents false cycle detection.

Time Complexity:
O(V + E)
- Each vertex is visited once.
- Each edge is processed once during DFS traversal.

Space Complexity:
O(V)
- Visited array takes O(V) space.
- Recursive DFS call stack can go up to O(V) in the worst case.
- Adjacency list takes O(V + E) space.
*/


class Solution {
  public:
    bool dfs(int src,int perent, vector<vector<int>>& adj_list, vector<bool>&visited){
     visited[src]=true;
     
     for(int e:adj_list[src]){
       if(visited[e]==false){
        if(dfs(e,src,adj_list,visited)==true)return true; 
      } 
      else if(visited[e]==true && perent!=e)return true;
     }
      return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj_list(V);
    for(vector<int> e:edges)
    {
        adj_list[e[0]].push_back(e[1]);
        adj_list[e[1]].push_back(e[0]);
    }
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
      if(visited[i]==false){
        if(dfs(i,-1,adj_list,visited)==true)return true; 
      } 
    }
    return false;
    }
};