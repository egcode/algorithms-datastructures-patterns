### [Minimum Number of Vertices to Reach All Nodes](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/) <br>

Given a **directed acyclic graph**, with `n` vertices numbered from `0` to `n-1`, and an array `edges` where $edges[i]$ = [$from_i$, $to_i$] represents a directed edge from node $from_i$ to node $to_i$.

Find the **smallest set of vertices from which all nodes in the graph are reachable**. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.


and some inline math, $e^{i \pi} = -1$




#### Example 1:
<img src="../../../../../images/minvertofverstall1.png">

```
Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
Output: [0,3]
Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].

```

#### Example 2:
<img src="../../../../../images/minvertofverstall2.png">

```
Input: n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
Output: [0,2,3]
Explanation: Notice that vertices 0, 3 and 2 are not reachable from any other node, so we must include them. Also any of these vertices can reach nodes 1 and 4.

```

# Solutions

### Python
```
class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        '''
        Disjoint set (Union find)
        '''
        
        root=[i for i in range(n)]
        
        def find(x):
            if root[x] == x:
                return x
            root[x]=find(root[x])
            return root[x]
        
        def union(x,y):
            rootX=find(x)
            rootY=find(y)
            if rootY != rootX:
                root[y]=rootX
                
        for src, dst in edges:
            union(src, dst)
         
        res=set()
        for i in range(n):
            res.add(find(i))
            
        return res

```
