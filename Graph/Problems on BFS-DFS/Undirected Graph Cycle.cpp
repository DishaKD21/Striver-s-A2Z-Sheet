//Undirected Graph Cycle
/*
Approach: Cycle Detection in Undirected Graph using BFS

1. Since the graph is undirected, we use BFS along with parent tracking
   to detect cycles.

2. First, we convert the given edge list into an adjacency list
   because BFS traversal is easier and more efficient using adjacency lists.

3. We maintain a visited array to keep track of nodes that are already explored,
   which helps in avoiding repeated processing.

4. For each unvisited node (to handle disconnected graphs),
   we start a BFS traversal:
   - Push the source node into the queue along with its parent as -1.
   - Mark the source node as visited.

5. During BFS:
   - Pop a node and its parent from the queue.
   - Traverse all its adjacent neighbors.
     a) If a neighbor is not visited:
        - Mark it as visited.
        - Push it into the queue with the current node as its parent.
     b) If a neighbor is already visited and it is NOT the parent:
        - This means there is a back-edge in the undirected graph,
          which confirms the presence of a cycle.
        - Return true immediately.

6. If BFS completes for all components without detecting any cycle,
   then the graph does not contain a cycle.

Time Complexity:
- O(V + E), where V is the number of vertices and E is the number of edges.

Space Complexity:
- O(V) for the visited array and BFS queue.

This approach correctly detects cycles in an undirected graph,
even when the graph is disconnected.
*/


class Solution {
  public:
    bool bfs(int src, vector<vector<int>>& edges, vector<bool>& visited){
      queue<pair<int,int>> q;
      q.push({src,-1});
      visited[src]=true;
      while(!q.empty()){
        pair<int,int> ind = q.front();
        int curr = ind.first;
        int perent = ind.second;
        q.pop();
        for(int nb:edges[curr]){
            if(!visited[nb])
            {
            q.push({nb,curr});
            visited[nb]=true;
            }
            else if(nb!=perent)return true;
        }
      }
      return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);

    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<bool> visited(V,false);
    bool ans;
     for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(bfs(i, adj, visited))
                    return true;
            }
        }
        return false;
    }
};