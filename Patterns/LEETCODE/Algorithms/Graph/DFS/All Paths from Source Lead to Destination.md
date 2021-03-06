### [All Paths from Source Lead to Destination](https://leetcode.com/problems/all-paths-from-source-lead-to-destination/) <br>

Given the edges of a directed graph where <img src="https://render.githubusercontent.com/render/math?math=edges[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=a_i">, <img src="https://render.githubusercontent.com/render/math?math=b_i">] indicates there is an edge between nodes <img src="https://render.githubusercontent.com/render/math?math=a_i"> and <img src="https://render.githubusercontent.com/render/math?math=b_i">, and two nodes `source` and `destination` of this graph, determine whether or not all paths starting from `source` eventually, end at `destination`, that is:

 - At least one path exists from the `source` node to the `destination` node
 - If a path exists from the `source` node to a node with no outgoing edges, then that node is equal to `destination`.
 - The number of possible paths from `source` to `destination` is a finite number.

Return `true` if and only if all roads from `source` lead to `destination`.




#### Example 1:
<img src="../../../../../images/1059_example_1.png">

```
Input: n = 3, edges = [[0,1],[0,2]], source = 0, destination = 2
Output: false
Explanation: It is possible to reach and get stuck on both node 1 and node 2.

```

#### Example 2:
<img src="../../../../../images/1059_example_2.png">

```
Input: n = 4, edges = [[0,1],[0,3],[1,2],[2,1]], source = 0, destination = 3
Output: false
Explanation: We have two possibilities: to end at node 3, or to loop over node 1 and node 2 indefinitely.

```

#### Example 3:
<img src="../../../../../images/1059_example_3.png">

```
Input: n = 4, edges = [[0,1],[0,2],[1,3],[2,3]], source = 0, destination = 3
Output: true

```

#### Example 4:
<img src="../../../../../images/1059_example_4.png">

```
Input: n = 3, edges = [[0,1],[1,1],[1,2]], source = 0, destination = 2
Output: false
Explanation: All paths from the source node end at the destination node, but there are an infinite number of paths, such as 0-1-2, 0-1-1-2, 0-1-1-1-2, 0-1-1-1-1-2, and so on.

```

#### Example 5:
<img src="../../../../../images/1059_example_5.png">

```
Input: n = 2, edges = [[0,1],[1,1]], source = 0, destination = 1
Output: false
Explanation: There is infinite self-loop at destination node.

```





# Solutions

### Python
```
class Solution:
    def leadsToDestination(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        
        graph=collections.defaultdict(set)
        for src,dst in edges:
            graph[src].add(dst)            
            
        vis=set()
        
        def dfs(node):
            vis.add(node)
                  
            # if it's not the end(len(granp[node]) != 0)
            # if it's the end and not destination
            if len(graph[node]) == 0 and node != destination:
                return False
                
            for child in graph[node]:
                if child in vis:
                    return False
                if dfs(child)==False:
                    return False
                        
            vis.remove(node)
            
            return True
            
        return dfs(source)

```
