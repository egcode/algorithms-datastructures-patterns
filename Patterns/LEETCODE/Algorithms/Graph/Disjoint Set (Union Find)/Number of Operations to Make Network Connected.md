### [Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/) <br>

There are `n` computers numbered from `0` to `n-1` connected by ethernet cables `connections` forming a network where `connections[i] = [a, b]` represents a connection between computers `a` and `b`. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network `connections`. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the *minimum number of times* you need to do this in order to make all the computers connected. If it's not possible, return -1. 



#### Example 1:
<img src="../../../../../images/1319sample_1_1677.png">

```
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

```

#### Example 2:
<img src="../../../../../images/1319sample_2_1677.png">

```
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

```


#### Example 3:

```
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.

```


#### Example 4:

```
Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
Output: 0

```


# Solutions

### Python
```
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        '''
        Disjoint Set (Union Find)
        
        - if we have less than n-1 connections - it is impossible to connect all computers.
        - return numberOfClusters-1
        
        
        '''
        
        if len(connections) < n-1:
            # impossible to create full network
            return -1
        
        roots=[i for i in range(n)]
        ranks=[0]*n
        
        def find(x):
            if x == roots[x]:
                return x
            roots[x]=find(roots[x])
            return roots[x]
        
        def union(x,y):
            rootX=find(x)
            rootY=find(y)
            if ranks[rootX]>ranks[rootY]:
                roots[rootY]=rootX
            elif ranks[rootX]<ranks[rootY]:
                roots[rootX]=rootY
            else:
                roots[rootY]=rootX
                ranks[rootX] += 1
            
        for x,y in connections:
            union(x, y)
            
        clusters=set()
        for i in range(n):
            clusters.add(find(i))
            
        return len(clusters)-1

```
