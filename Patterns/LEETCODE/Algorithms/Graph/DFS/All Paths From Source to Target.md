### [All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target/) <br>

Given a directed acyclic graph (**DAG**) of `n` nodes labeled from `0` to `n - 1`, find all possible paths from node `0` to node `n - 1` and return them in **any order**.

The graph is given as follows: `graph[i]` is a list of all nodes you can visit from node `i` (i.e., there is a directed edge from node `i` to node `graph[i][j]`).


#### Example 1:
<img src="../../../../../images/797_1.jpg">

```
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

```

#### Example 2:
<img src="../../../../../images/797_2.jpg">

```
Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

```

#### Example 3:

```
Input: graph = [[1],[]]
Output: [[0,1]]

```


#### Example 4:

```
Input: graph = [[1,2,3],[2],[3],[]]
Output: [[0,1,2,3],[0,2,3],[0,3]]

```

#### Example 5:

```
Input: graph = [[1,3],[2],[3],[]]
Output: [[0,1,2,3],[0,3]]

```


# Solutions

### Python
```
class Solution:
#     def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
#         '''
#         Graph DFS
#         '''
        
#         n=len(graph)
        
#         def dfs(path, node):
#             if node == n-1:
#                 path += [node]
#                 return [path]
            
#             tmp=[]
#             for child in graph[node]:
#                 out = dfs(path+[node], child)
#                 for ot in out:
#                     tmp += [ot]
            
#             return tmp
        
#         return dfs([], 0)
            
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        '''
        Graph BFS
        '''
        
        n=len(graph)
        
        def bfs(path, node):
            q=collections.deque([(path, node)])
            res=[]
            while q:
                p, nd = q.pop()
                
                if nd==n-1:
                    res.append(p+[nd])
                
                for child in graph[nd]:
                    q.appendleft((p+[nd],child))
            return res
            
        
        return bfs([], 0)

```
