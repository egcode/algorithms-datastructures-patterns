### [Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/) <br>

There are `n` cities labeled from `1` to `n`. You are given the integer `n` and an array `connections` where <img src="https://render.githubusercontent.com/render/math?math=connections[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=x_i">, <img src="https://render.githubusercontent.com/render/math?math=y_i">, <img src="https://render.githubusercontent.com/render/math?math=cost_i">] indicates that the cost of connecting city <img src="https://render.githubusercontent.com/render/math?math=x_i"> and city <img src="https://render.githubusercontent.com/render/math?math=y_i"> (bidirectional connection) is <img src="https://render.githubusercontent.com/render/math?math=cost_i">.

Return the *minimum* **cost** **to connect all the** `n` *cities such that there is at least one path between each pair of cities*. If it is impossible to connect all the `n` cities, return `-1`,

The **cost** is the sum of the connections' costs used.


#### Example 1:
<img src="../../../../../images/1135_ex1.png">

```
Input: n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: Choosing any 2 edges will connect all cities so we choose the minimum 2.

```

#### Example 2:
<img src="../../../../../images/1135_ex2.png">

```
Input: n = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: There is no way to connect all cities even if all edges are used.

```

# Solutions

### Python
```
class Solution:
    def minimumCost(self, N: int, connections: List[List[int]]) -> int:
        '''
        Kruskal's algorithm (with disjoint set (union find))
        '''
        connections.sort(key=lambda x: x[2])
        roots=[i for i in range(N)]
        ranks=[1]*N
        
        def find(x):
            if roots[x] == x:
                return x
            roots[x]=find(roots[x])
            return roots[x]
        
        def union(x, y):
            rootX=find(x)
            rootY=find(y)
            
            if rootY != rootX:
                if ranks[rootX] > ranks[rootY]:
                    roots[rootY] = rootX
                elif ranks[rootX] < ranks[rootY]:
                    roots[rootX] = rootY
                else:
                    ranks[rootX] += 1
                    roots[rootY]=rootX
                return True # free to add to MST
            else:
                return False # already added to MST
            
            
        nodes_count=0
        res=0
        for x, y, cost in connections:
            if union(x-1, y-1)==True:
                nodes_count += 1
                res += cost
              
        # Flatten nodes. ( if there is only one root, roots array becomes [0,0,0,0,0])
        for i in range(N):
            find(i)
        
        if len(set(roots))==1: # check if all nodes have same root
            return res
        return -1
    
    
#     def minimumCost(self, N: int, connections: List[List[int]]) -> int:
#         '''
#         Prim's algorithm with heap
        
#         1. Create bi-directional graph with connected points and dist
#         2. We store first point 0 in edge_heap, Starting with all edges in point 0
#         3. While we didn't finish with final MST we add point by point in MST_set, and store result in res
#         '''
#         graph=collections.defaultdict(list)
#         for a, b, cost in connections:
#             graph[a-1].append((cost, b-1))
#             graph[b-1].append((cost, a-1))
            
#         edges_heap=graph[0]
#         heapify(edges_heap)
#         vis=set([0])
    
#         res=0
#         while edges_heap:
#             cost, node = heappop(edges_heap)
#             if node not in vis:
#                 vis.add(node)
#                 res += cost
#                 for cost1, child in graph[node]:
#                     if child not in vis:
#                         heappush(edges_heap, (cost1, child))
    
#         if len(vis) != N:
#             return -1
#         return res

```
