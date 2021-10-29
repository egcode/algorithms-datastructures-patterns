### [Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/) <br>

You have a graph of `n` nodes labeled from `0` to `n - 1`. You are given an integer n and a list of `edges` where  $edges[i] = [a_i, b_i]$ indicates that there is an undirected edge between nodes $a_i$ and $b_i$ in the graph.

Return `true` if the edges of the given graph make up a valid tree, and `false` otherwise.
 

#### Example 1:
<img src="../../../../../images/tree1-graph.jpg">

```
Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true

```
#### Example 2:
<img src="../../../../../images/tree2-graph.jpg">

```
Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
Output: false

```

# Solutions

### Python
```
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        '''
        Disjoint set (union find)
        '''
        if len(edges) != n-1:
            return False
        
        edges.sort(key=lambda x: x[0])
        
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
            union(edge[1], edge[0])
        
        # get results
        res=set()
        for i in range(n):
            res.add(find(i))
        
        # print(root)
        # print(res)
        return len(set(root))==1
    
'''
4
[[0,1],[2,3],[1,2]]
3
[[1,0],[2,1]]
'''    

```
