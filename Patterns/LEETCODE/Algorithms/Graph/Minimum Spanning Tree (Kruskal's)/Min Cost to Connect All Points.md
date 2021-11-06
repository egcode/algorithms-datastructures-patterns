### [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/) <br>

You are given an array `points` representing integer coordinates of some points on a 2D-plane, where <img src="https://render.githubusercontent.com/render/math?math=points[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=x_i">, <img src="https://render.githubusercontent.com/render/math?math=y_i">].

The cost of connecting two points [<img src="https://render.githubusercontent.com/render/math?math=x_i">, <img src="https://render.githubusercontent.com/render/math?math=y_i">] and [<img src="https://render.githubusercontent.com/render/math?math=x_j">, <img src="https://render.githubusercontent.com/render/math?math=y_j">] is the **manhattan distance** between them: |<img src="https://render.githubusercontent.com/render/math?math=x_i"> - <img src="https://render.githubusercontent.com/render/math?math=x_j">| + |<img src="https://render.githubusercontent.com/render/math?math=y_i"> - <img src="https://render.githubusercontent.com/render/math?math=y_j">|, where `|val|` denotes the absolute value of `val`.

Return the **minimum cost to make all points connected**. All points are connected if there is **exactly one** simple path between any two points.



#### Example 1:
<img src="../../../../../images/1584-ex1.png">

```
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

```
<img src="../../../../../images/1584-ex1-1.png">


```
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.

```



#### Example 2:

```
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18

```

#### Example 3:

```
Input: points = [[0,0],[1,1],[1,0],[-1,1]]
Output: 4

```

#### Example 4:

```
Input: points = [[-1000000,-1000000],[1000000,1000000]]
Output: 4000000

```

#### Example 5:

```
Input: points = [[0,0]]
Output: 0

```


# Solutions

### Python
```
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        '''
        Kruskal's Alrorithm with Disjoint set
        
        1. Gather edges represents with distances in array
        2. Sort edges by dist. To make sure we will build Minumum Spanning Tree
        3. Using disjoint-set (union find) append points that don't form the cycle
        '''
        edges=[]
        for i, p1 in enumerate(points):
            for j, p2 in enumerate(points):
                if i==j: continue
                dist=abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])
                edges.append((dist, i, j))
                
        # Sort edges by dist        
        edges.sort(key=lambda x: x[0])
        
        n=len(points)
        root=[i for i in range(n)]
        
        def find(x):
            if x == root[x]:
                return x
            root[x]=find(root[x])
            return root[x]
        
        def union(x, y):
            rootX=find(x)
            rootY=find(y)
            if rootY != rootX:
                root[rootY]=rootX
                # Different root, we free to add it current tree
                return True
            else:
                # Same root we don't add to current tree
                return False
        res=0
        for dist, p1, p2 in edges:
            if union(p1, p2)==True:
                res += dist
        
        return res
    
#     def minCostConnectPoints(self, points: List[List[int]]) -> int:
#         '''
#         Prim's Algorithm with heap
        
#         1. Create bi-directional graph with connected points and dist
#         2. We store first point 0 in edge_heap, Starting with all edges in point 0
#         3. While we didn't finish with final MST we add point by point in MST_set, and store result in res
#         '''
#         graph=collections.defaultdict(list)
#         for i, p1 in enumerate(points):
#             for j, p2 in enumerate(points):
#                 if i==j: continue
#                 dist=abs(p1[0]-p2[0]) + abs(p1[1]-p2[1])
#                 graph[i].append((dist, j))
#                 graph[j].append((dist, i))
        
#         # Starting with all edges in point 0
#         edges_heap = graph[0]
#         heapify(edges_heap)
#         MST_set=set([0])
        
#         res=0
#         while len(MST_set) < len(points):
#             dist, point = heappop(edges_heap)
#             if point not in MST_set:
#                 MST_set.add(point)
#                 res += dist
#                 for neigh_dist, neigh_point in graph[point]:
#                     if neigh_point not in MST_set:
#                         heappush(edges_heap, (neigh_dist, neigh_point))
        
#         return res

```
