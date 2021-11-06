### [Critical Connections in a Network](https://leetcode.com/problems/critical-connections-in-a-network/) <br>

There are n servers numbered from `0` to `n - 1` connected by undirected server-to-server `connections` forming a network where <img src="https://render.githubusercontent.com/render/math?math=connections[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=a_i">, <img src="https://render.githubusercontent.com/render/math?math=b_i">] represents a connection between servers <img src="https://render.githubusercontent.com/render/math?math=a_i"> and <img src="https://render.githubusercontent.com/render/math?math=b_i">. Any server can reach other servers directly or indirectly through the network.

A **critical connection** is a connection that, if removed, will make some servers unable to reach some other server.

Return all **critical connections** in the network in any order.



#### Example 1:
<img src="../../../../../images/1192-1.png">

```
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

```

#### Example 2:

```
Input: n = 2, connections = [[0,1]]
Output: [[0,1]]

```

# Solutions

### Python
```
class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        '''
        Tarjan's Algorithm
        '''
        res=[]
        vis=set()
        lowest={}
        
        graph=[[] for _ in range(n)]
        for con in connections:
            graph[con[0]].append(con[1])
            graph[con[1]].append(con[0])
            
        def dfs(cur_node, rank, prev_node):
            vis.add(cur_node)
            lowest[cur_node]=rank
            
            for next_node in graph[cur_node]:
                if next_node==prev_node:
                    continue
                if next_node not in vis:
                    dfs(next_node, rank+1, cur_node)
                    
                lowest[cur_node]=min(lowest[cur_node], lowest[next_node])
                
                if lowest[next_node] >= rank+1:
                    res.append([cur_node, next_node])
                
        
        dfs(0, 0, -1)
        return res

```
