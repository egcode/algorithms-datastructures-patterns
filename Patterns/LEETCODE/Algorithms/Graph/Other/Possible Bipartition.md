### [Possible Bipartition](https://leetcode.com/problems/possible-bipartition/) <br>

We want to split a group of `n` people (labeled from `1` to `n`) into two groups of **any size**. Each person may dislike some other people, and they should not go into the same group.

Given the integer `n` and the array `dislikes` where <img src="https://render.githubusercontent.com/render/math?math=dislikes[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=a_i">, <img src="https://render.githubusercontent.com/render/math?math=b_i">] indicates that the person labeled <img src="https://render.githubusercontent.com/render/math?math=a_i"> does not like the person labeled <img src="https://render.githubusercontent.com/render/math?math=b_i">, return `true` *if it is possible to split everyone into two groups in this way*.


#### Example 1:

```
Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].

```

#### Example 2:

```
Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

```

#### Example 3:

```
Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false

```



# Solutions

### Python
```
class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        '''
        Here we check if graph is BIPARTITE, 
        just like 785. Is Graph Bipartite? problem:
         - Every other node should be colored with different color.
         - If we meet two consecutive nodes with the same color we return FALSE
        '''
        graph=collections.defaultdict(list)
        for l,r in dislikes:
            graph[l].append(r)
            graph[r].append(l)
            
        # print(graph)
        def dfs(node, color):
            for next_node in graph[node]:
                if next_node in colors.keys():
                    if colors[next_node]==color:
                        return False
                else:
                    next_color=1-color
                    colors[next_node]=next_color
                    if not dfs(next_node, next_color):
                        return False
            return True
        
        
        colors={} # color 0 and color 1
        for node in range(1,n+1):
            if node not in colors.keys():
                colors[node]=0
                if not dfs(node, 0):
                    return False
        
        return True

```
