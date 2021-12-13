### [Making A Large Island](https://leetcode.com/problems/making-a-large-island/) <br>

You are given an `n x n` binary matrix `grid`. You are allowed to change **at most one** `0` to be `1`.

Return *the size of the largest ***island*** in grid after applying this operation*.

An **island** is a 4-directionally connected group of `1`s.



#### Example 1:

```
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

```

#### Example 2:

```
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

```

#### Example 3:

```
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.

```


# Solutions

### Python
```
class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        vis={}
        vis_values={}
        h=len(grid)
        w=len(grid[0])
        id_=0
        res=0
        size=0
        
        def dfs(r, c):
            nonlocal vis
            nonlocal size
            
            if r<0 or r>=h or c<0 or c>=w or grid[r][c] != 1 or (r, c) in vis.keys():
                return
            
            vis[(r, c)]=id_
            size += 1
            
            dfs(r+1, c)
            dfs(r-1, c)
            dfs(r, c+1)
            dfs(r, c-1)
        
        # measure size of current islands
        for i in range(h):
            for j in range(w):
                if grid[i][j]==1 and (i, j) not in vis.keys():
                    size=0
                    dfs(i, j)
                    res=max(res, size)
                    vis_values[id_]=size
                    id_ += 1

        # check if we can connect islands
        for i in range(h):
            for j in range(w):
                if grid[i][j]==0:
                    tmp=1
                    vis_islands=set()
                    
                    for d in [[-1,0],[1,0],[0,-1],[0,1]]:
                        row=i+d[0]
                        col=j+d[1]
                        if row<0 or row>=h or col<0 or col>=w and grid[i][j] != 1:
                            continue
                        if (row, col) not in vis.keys():
                            continue
                        if vis[(row, col)] in vis_islands:
                            continue
                            
                        key=(row, col)
                        id_=vis[key]
                        # add identificator to vis islands
                        vis_islands.add(id_)
                        tmp += vis_values[id_]
                    res = max(res, tmp)
                    
        return res

```
