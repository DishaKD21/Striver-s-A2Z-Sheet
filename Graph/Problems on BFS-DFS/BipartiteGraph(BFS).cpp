//785. Is Graph Bipartite?
/*
Approach:
---------
We check whether the graph is bipartite using BFS and graph coloring.

A graph is bipartite if we can divide its nodes into two sets such that
no two adjacent nodes belong to the same set.
This is equivalent to coloring the graph using only 2 colors.

Algorithm:
----------
1. Create a "colored" array initialized with -1.
   -1 → not colored
    0 → first color
    1 → second color

2. Since the graph may be disconnected,
   we iterate through all nodes.

3. For every uncolored node:
   - Start BFS.
   - Assign it color 0.
   - Push it into queue.

4. During BFS:
   - Pop a node.
   - For each neighbor:
       a) If not colored → assign opposite color and push into queue.
       b) If already colored with same color → return false.

5. If BFS completes without conflict,
   that component is bipartite.

6. If all components are valid → return true.

Why This Works:
---------------
In a bipartite graph, no two adjacent nodes can have the same color.
If we ever detect same-color neighbors,
it means there exists an odd-length cycle → graph is not bipartite.

Time Complexity:
O(V + E)

Space Complexity:
O(V)
*/
class Solution {
public:
    bool bfs(int src,vector<int> &colored,vector<vector<int>>& graph){
    queue<int> q;
    q.push(src);
    colored[src]=0;
    while(!q.empty()){
        int ind=q.front();
        q.pop();
        for(int nb:graph[ind]){
           if(colored[nb]==-1){
            colored[nb]=!colored[ind];
            q.push(nb);
           }
           else if(colored[nb]==colored[ind]){
            return false;
        }
    }}
    return true;
    }
    bool isBipartite(vector<vector<int>>& graph){
    int m=graph.size();
    vector<int> colored(m,-1);
    for(int i=0;i<m;i++){
            if(colored[i]==-1){
             if(bfs(i,colored,graph)==false)return false;
        }
    }
    return true;
    }
};