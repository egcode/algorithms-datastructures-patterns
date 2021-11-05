### [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) <br>

Given a `m x n` grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

**Note:** You can only move either down or right at any point in time.


#### Example 1:
<img src="../../../../../images/minpath.jpg">

```
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

```

#### Example 2:

```
Input: grid = [[1,2,3],[4,5,6]]
Output: 12

```

# Solutions

### Python
```
class Solution:
    # def minPathSum(self, grid: List[List[int]]) -> int:
    #     '''
    #     Dijkstra's Algorithm
    #     '''
    #     if not grid: return 0
    #     h=len(grid)
    #     w=len(grid[0])
    #     heap=[(grid[0][0], 0,0)]
    #     vis=set([(0,0)])
    #     while heap:
    #         path, row, col = heappop(heap)
    #         if row==(h-1) and col==(w-1):
    #             return path
    #         for d in [[0, 1],[1,0]]:
    #             r=row+d[0]
    #             c=col+d[1]
    #             if 0<=r<h and 0<=c<w and (r,c) not in vis:
    #                 vis.add((r,c))
    #                 heappush(heap, (path+grid[r][c], r, c))
    #     return -1
        
        
#     def minPathSum(self, grid: List[List[int]]) -> int:
#         '''
#         Dynamic Programming (Recursion)
#         '''
#         if not grid: return 0
#         h=len(grid)
#         w=len(grid[0])
#         memo={}
        
#         def dfs(r, c):
#             if r>=h or c>=w:
#                 return float('inf')
            
#             if r==(h-1) and c==(w-1):
#                 return grid[r][c]
            
#             if (r,c) in memo.keys():
#                 return memo[(r,c)]
            
#             memo[(r,c)]=grid[r][c]+min(dfs(r+1, c), dfs(r,c+1))
#             return memo[(r,c)]
        
#         res=dfs(0,0)
#         return res
        
    def minPathSum(self, grid: List[List[int]]) -> int:
        '''
        Dynamic Programming (Tabulation)
        '''
        if not grid: return 0
        h=len(grid)
        w=len(grid[0])
        
        dp=[[float('inf')]*(w+1) for _ in range(h+1)]
        dp[h-1][w-1]=grid[h-1][w-1]
        
        for r in range(h)[::-1]:
            for c in range(w)[::-1]:
                if r==(h-1) and c==(w-1): continue
                dp[r][c]=grid[r][c]+min(dp[r+1][c], dp[r][c+1])
        
        return dp[0][0]
```