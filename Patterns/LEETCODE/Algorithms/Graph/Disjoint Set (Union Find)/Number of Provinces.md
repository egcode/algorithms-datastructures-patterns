### [Number of Provinces](https://leetcode.com/problems/number-of-provinces/) <br>

There are `n` cities. Some of them are connected, while some are not. If city `a` is connected directly with city `b`, and city `b` is connected directly with city `c`, then city a is connected indirectly with city `c`.

A **province** is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an `n x n` matrix `isConnected` where `isConnected[i][j] = 1` if the `i`-th city and the `j`-th city are directly connected, and `isConnected[i][j] = 0` otherwise.

Return the *total number of* **provinces**.




#### Example 1:
<img src="../../../../../images/graph1prov.jpg">

```
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

```

#### Example 2:
<img src="../../../../../images/graph2prov.jpg">

```
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

```

# Solutions

### Python
```
class Solution:
#     def findCircleNum(self, M: List[List[int]]) -> int:
#         '''
#         DFS
#         '''
#         graph=[set() for _ in range(len(M))]
#         for i in range(len(M)):
#             for j in range(len(M[i])):
#                 if M[i][j]==1 and i != j:
#                     graph[i].add(j)
#                     graph[j].add(i)
        
#         vis=set()
#         def dfs(node):
#             for child in graph[node]:
#                 if child not in vis:
#                     vis.add(child)
#                     dfs(child)

#         res=0
#         for node in range(len(graph)):
#             if node not in vis:
#                 vis.add(node)
#                 res += 1
#                 dfs(node)

#         return res
    
    
    def findCircleNum(self, M: List[List[int]]) -> int:
        '''
        Disjoint set (union find)
        '''
        n=len(M)
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
    
        for i in range(n):
            for j in range(len(M[0])):
                if j != i and M[i][j]==1:
                    union(i, j)
        
        # # Counting root nodes    
        res=set()
        for i in range(n):
            res.add(find(root[i]))        
        return len(res)
```
