//785. Is Graph Bipartite?
/*
Approach:
---------
We solve this problem using Graph Coloring with DFS.

A graph is bipartite if we can divide its nodes into two groups
such that no two adjacent nodes have the same color.

Steps:
1. We maintain a "colored" array where:
      -1  → node not colored yet
       0  → color 1
       1  → color 2

2. For each unvisited node, we start DFS.

3. In DFS:
   - Color the current node.
   - Visit all its neighbors.
   - If a neighbor is uncolored, assign it opposite color.
   - If a neighbor already has the same color as current node,
     then the graph is NOT bipartite.

4. If we finish DFS without conflicts, the component is bipartite.

5. Since the graph may be disconnected, we run DFS for every node
   that is still uncolored.

Time Complexity: O(V + E)
Space Complexity: O(V)
*/