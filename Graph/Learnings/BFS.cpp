//BFS of graph
/*
This code performs Breadth First Search (BFS) on a graph using a queue. 
The approach starts from a given node (node 0) and visits all its neighbors 
level by level. First, the starting node is marked as visited, added to the 
answer list, and pushed into the queue. Then, while the queue is not empty, 
the front node is taken out and all its unvisited neighbors are visited: each 
neighbor is marked as visited, added to the answer list, and pushed into the queue.
This ensures that nodes are visited in breadth-wise order (all neighbors first,
then their neighbors). After completing BFS from the starting node, the code 
checks if there are any unvisited nodes. If found, it calls BFS again from 
that node. This helps cover disconnected components of the graph.

The time complexity (TC) is O(V + E), where V is the number of vertices and E 
is the number of edges, because each vertex is visited once and each edge is 
checked once. The space complexity (SC) is O(V), due to the queue, visited array,
and result array storing up to all vertices.
*/
class Solution {
  public:
    void bfs(int n,vector<vector<int>> &adj, vector<bool> &visited,vector<int> &ans) {
     queue<int> q1;
     ans.push_back(n);
     visited[n]=true;
     q1.push(n);
    while(!q1.empty()){
      int ind = q1.front();
    for(int neighbour:adj[ind]){
        if(visited[neighbour]==false)
       {ans.push_back(neighbour);
        q1.push(neighbour);
        visited[neighbour]=true;
        }
    }
    q1.pop();
    }
     for(int i=0;i<visited.size();i++)
     {
       if(!visited[i]){
        bfs(i,adj,visited,ans);
       } 
     }
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
      int n=adj.size(); 
      vector<bool> visited(n,false);
      vector<int> ans;
      bfs(0,adj,visited,ans);
      return ans;
    }
};