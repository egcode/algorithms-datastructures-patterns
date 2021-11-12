### [Number of Islands](https://leetcode.com/problems/number-of-islands/) <br>

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return *the number of islands*.

An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.




#### Example 1:

```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```

#### Example 2:

```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

```

# Solutions

### Python
```
class Solution:
#     def numIslands(self, grid: List[List[str]]) -> int:
#         '''
#         DFS
#         '''
#         if not grid: return 0
        
#         h=len(grid)
#         w=len(grid[0])
        
#         def dfs(r, c):
#             if r<0 or r>=h or c<0 or c>=w or grid[r][c] != "1":
#                 return
#             grid[r][c]="#"
#             dfs(r+1,c)
#             dfs(r-1,c)
#             dfs(r,c+1)
#             dfs(r,c-1)
            
#         res=0
#         for i in range(h):
#             for j in range(w):
#                 if grid[i][j]=="1":
#                     dfs(i, j)
#                     res += 1  
#         return res

    
    def numIslands(self, grid: List[List[str]]) -> int:
        '''
        BFS
        '''
        if not grid: return 0
        
        h=len(grid)
        w=len(grid[0])
        
        def bfs(i, j):
            q=[(i, j)]

            while q:
                row, col = q.pop()
                grid[row][col]="#"
                
                for d in [[-1,0], [1, 0], [0, -1], [0, 1]]:
                    r=row+d[0]
                    c=col+d[1]
                    if r<0 or r>=h or c<0 or c>=w or grid[r][c] != "1":
                        continue
                    grid[r][c]="#"
                    q.insert(0, (r, c))
        
        res=0
        for i in range(h):
            for j in range(w):
                if grid[i][j]=="1":
                    res += 1
                    bfs(i, j)
        return res   

```
