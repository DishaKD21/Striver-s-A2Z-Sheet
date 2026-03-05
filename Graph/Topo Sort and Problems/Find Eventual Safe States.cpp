//802. Find Eventual Safe States
/*
Approach: DFS + Cycle Detection (Graph Coloring Concept)

This problem asks to find all "eventual safe nodes".
A node is safe if starting from it, we never reach a cycle.

Idea:
- If a node is part of a cycle OR can reach a cycle, it is NOT safe.
- If a node eventually leads to a terminal node (no outgoing edges),
  then it is safe.

What I did in this code:

1. Used Depth First Search (DFS) to detect cycles.
2. Maintained three boolean arrays:
   - visited[]  → Marks if a node has been visited before.
   - path[]     → Marks nodes in the current DFS recursion stack.
                  (Used to detect cycles)
   - checked[]  → Marks whether a node is safe.

DFS Logic:
- Mark current node as visited and part of current path.
- Traverse all neighbors:
    • If neighbor is not visited → recursively call DFS.
    • If neighbor is already in current path → cycle detected.
      → return true (means cycle found).
- If any neighbor leads to a cycle → current node is unsafe.
- If no cycle found through this node:
    • Mark checked[src] = true (safe node).
- Remove node from current path before returning.

Main Function:
- Run DFS for every unvisited node.
- After DFS completion, collect all nodes where checked[i] == true.
- Return those nodes as eventual safe nodes.

Time Complexity: O(V + E)
Space Complexity: O(V)
*/

class Solution {
public:
    bool dfs(int src, vector<bool>& path, vector<bool>& visited,
             vector<vector<int>>& adj_list,vector<bool> &checked) {
        visited[src] = true;
        path[src] = true;

        for (int nb : adj_list[src]) {
            if (visited[nb] == false) {
                if(dfs(nb, path, visited, adj_list,checked))
                 { 
                    checked[nb]=0;
                    return true;
                 }
            } else if (path[nb] == true) {
                return true;
            }
        }
        checked[src]=true;
        path[src] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<bool> path(V, false);
        vector<bool> visited(V, false);
        vector<bool> checked(V,false);
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (visited[i] == false) {
                dfs(i, path, visited,graph, checked);    
            }
        }
        for(int i=0;i<V;i++){
            if(checked[i]==true){
                ans.push_back(i);
            }
        }
        return ans;
    }
};