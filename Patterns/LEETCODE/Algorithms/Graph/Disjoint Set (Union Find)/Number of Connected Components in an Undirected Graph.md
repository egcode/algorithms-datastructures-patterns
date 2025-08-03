### [Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/) <br>

You have a graph of `n` nodes. You are given an integer `n` and an array `edges` where `edges[i] = [a_i, b_i]` indicates that there is an edge between node `a_i` and node `b_i` in the graph.

Return the **number of connected components** in the graph.



#### Example 1:
<img src="../../../../../images/conn1-graph.jpg">

```
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2

```

#### Example 2:
<img src="../../../../../images/conn2-graph.jpg">

```
Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1

```

# Solutions

### Python
```
class Solution:
#     def countComponents(self, n: int, edges: List[List[int]]) -> int:
#         '''
#         DFS 
#         BFS
#         '''
        
#         graph=[[] for _ in range(n)]
#         for ed in edges:
#             graph[ed[0]].append(ed[1])
#             graph[ed[1]].append(ed[0])
        
        
#         vis=set()
#         res=0
        
#         def dfs(node):
#             for child in graph[node]:
#                 if child not in vis:
#                     vis.add(child)
#                     dfs(child)
                    
# #         def bfs(node):
# #             q=collections.deque([node])
# #             vis.add(node)
            
# #             while q:
# #                 nd=q.pop()
# #                 for child in graph[nd]:
# #                     if child not in vis:
# #                         q.appendleft(child)
# #                         vis.add(child)
            
#         for node in range(n):
#             if node not in vis:
#                 res += 1
#                 vis.add(node)
#                 dfs(node)
#                 # bfs(node)
            
#         return res
    
    
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        '''
        Disjoint set (union find)
        '''
    
        root=[i for i in range(n)]
        rank=[1]*n
    
        def find(x):
            if x == root[x]:
                return x
            root[x] = find(root[x])
            return root[x]

        def union(x, y):
            rootX = find(x)
            rootY = find(y)
            if rootX != rootY:
                if rank[rootX] > rank[rootY]:
                    root[rootY] = rootX
                elif rank[rootX] < rank[rootY]:
                    root[rootX] = rootY
                else:
                    root[rootY] = rootX
                    rank[rootX] += 1    
    
        for edge in edges:
            union(edge[0], edge[1])
        
        # get results
        res=set()
        for i in range(n):
            res.add(find(i))
        
        return len(res)

```
