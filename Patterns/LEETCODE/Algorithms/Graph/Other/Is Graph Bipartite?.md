### [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/) <br>

There is an **undirected** graph with `n` nodes, where each node is numbered between `0` and `n - 1`. You are given a 2D array `graph`, where `graph[u]` is an array of nodes that node `u` is adjacent to. More formally, for each `v` in `graph[u]`, there is an undirected edge between node `u` and node `v`. The graph has the following properties:

 - There are no self-edges (`graph[u]` does not contain `u`).
 - There are no parallel edges (`graph[u]` does not contain duplicate values).
 - If v is in `graph[u]`, then `u` is in `graph[v]` (the graph is undirected).
 - The graph may not be connected, meaning there may be two nodes `u` and `v` such that there is no path between them.

A graph is **bipartite** if the nodes can be partitioned into two independent sets `A` and `B` such that **every** edge in the graph connects a node in set `A` and a node in set `B`.

Return `true` *if and only if it is ***bipartite****.



#### Example 1:
<img src="../../../../../images/785bi2.jpg">

```
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.

```

#### Example 2:
<img src="../../../../../images/785bi1.jpg">

```
Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.

```



# Solutions

### Python
```
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        '''
        Every other node should be colored with different color.
        If we meet two consecutive nodes with the same color we return FALSE
        '''
        colors={} # color 0 and color 1
        
        def dfs(node, color):
            
            for next_node in graph[node]:
                if next_node in colors.keys():
                    if colors[next_node]==color:
                        return False
                else:
                    next_color=1-color
                    colors[next_node]=next_color
                    if not dfs(next_node, next_color):
                        return False
                    
            return True
        
        for node in range(len(graph)):
            if node not in colors.keys():
                colors[node]=0
                if not dfs(node, 0):
                    return False
                
        return True

```
