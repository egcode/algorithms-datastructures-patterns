### [Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/) <br>

Given an `m x n` integers `matrix`, return *the length of the longest increasing path in* `matrix`.

From each cell, you can either move in four directions: left, right, up, or down. You **may not** move **diagonally** or move **outside the boundary** (i.e., wrap-around is not allowed).


#### Example 1:
<img src="../../../../../images/329grid1.jpg">

```
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

```

#### Example 2:
<img src="../../../../../images/329tmp-grid.jpg">

```
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

```

#### Example 3:

```
Input: matrix = [[1]]
Output: 1

```



# Solutions

### Python
```
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        ans=0
        cache={}
        h=len(matrix)
        w=len(matrix[0])
        
        def dfs(r, c, prev):
            nonlocal cache
            nonlocal matrix
            
            if r<0 or r >= h or c<0 or c >= w:
                return 0
            if matrix[r][c] <= prev:
                return 0 
            
            if (r,c) in cache.keys():
                return cache[(r,c)]
            
            path = max(dfs(r+1,c,matrix[r][c]),
                       dfs(r-1,c,matrix[r][c]),
                       dfs(r,c+1,matrix[r][c]),
                       dfs(r,c-1,matrix[r][c]))
            path += 1
            cache[(r,c)]=path
            return path
            
            
            
        for i in range(0, h):
            for j in range(0, w):
                ans = max(ans, dfs(i, j, -1))
    
        return ans


```
