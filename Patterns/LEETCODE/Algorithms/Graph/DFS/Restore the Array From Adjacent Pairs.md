### [Restore the Array From Adjacent Pairs](https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/) <br>

There is an integer array `nums` that consists of `n` **unique** elements, but you have forgotten it. However, you do remember every pair of adjacent elements in `nums`.

You are given a 2D integer array `adjacentPairs` of size `n - 1` where each <img src="https://render.githubusercontent.com/render/math?math=adjacentPairs[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=u_i">, <img src="https://render.githubusercontent.com/render/math?math=v_i">] indicates that the elements <img src="https://render.githubusercontent.com/render/math?math=u_i"> and <img src="https://render.githubusercontent.com/render/math?math=v_i"> are adjacent in `nums`.

It is guaranteed that every adjacent pair of elements `nums[i]` and `nums[i+1]` will exist in `adjacentPairs`, either as `[nums[i]`, `nums[i+1]]` or `[nums[i+1]`, `nums[i]]`. The pairs can appear **in any order**.

Return *the original array* `nums`. *If there are multiple solutions, return* **any of them**.



#### Example 1:

```
Input: adjacentPairs = [[2,1],[3,4],[3,2]]
Output: [1,2,3,4]
Explanation: This array has all its adjacent pairs in adjacentPairs.
Notice that adjacentPairs[i] may not be in left-to-right order.

```

#### Example 2:

```
Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
Output: [-2,4,1,-3]
Explanation: There can be negative numbers.
Another solution is [-3,1,4,-2], which would also be accepted.

```

#### Example 3:

```
Input: adjacentPairs = [[100000,-100000]]
Output: [100000,-100000]

```


# Solutions

### Python
```
class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        '''
        DFS
        The idea is to find leaf nodes. if it has only one connection - it is leaf
        '''
        if not adjacentPairs: return []
        n=len(adjacentPairs)
        graph=collections.defaultdict(list)
        
        leafs=set()
        for x, y in adjacentPairs:
            graph[x].append(y)
            graph[y].append(x)
            leafs.add(x)
            leafs.add(y)
            if len(graph[x])>1:
                leafs.remove(x)
            if len(graph[y])>1:
                leafs.remove(y)
            
        def dfs(node, nodes, vis):
            for child in graph[node]:
                if child not in vis:
                    vis.add(child)
                    nodes.append(child)
                    dfs(child, nodes, vis)
                    
        for leaf in list(leafs):
            nodes=[leaf]
            vis=set([leaf])
            dfs(leaf, nodes, vis)
            if len(nodes)==n+1:
                return nodes
        
        return []

```
