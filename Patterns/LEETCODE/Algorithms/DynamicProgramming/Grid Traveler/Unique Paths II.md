### [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) <br>

A robot is located at the top-left corner of a `m x n` grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as `1` and `0` respectively in the grid.


#### Example 1:
<img src="../../../../../images/robot1UniquePaths.jpg">

```
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

```

#### Example 2:
<img src="../../../../../images/robot2UniquePaths.jpg">

```
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1

```

# Solutions

### Python
```
class Solution:
#     def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
#         '''
#         Recursion
#         '''
#         h=len(obstacleGrid)
#         w=len(obstacleGrid[0])
#         cache={}
        
#         def dfs(r, c):
#             if (r,c) in cache.keys():
#                 return cache[(r,c)]
#             if r<0 or r>=h or c<0 or c>=w:
#                 return 0
#             if obstacleGrid[r][c]==1:
#                 return 0
#             if r==h-1 and c==w-1:
#                 return 1
            
#             cache[(r,c)] = dfs(r+1, c) + dfs(r, c+1)
#             return cache[(r,c)]
        
#         return dfs(0, 0)
    
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        '''
        Tabulation
        '''
        if obstacleGrid[-1][-1]==1: return 0
        h=len(obstacleGrid)
        w=len(obstacleGrid[0])
        dp=[[0]*(w+1) for i in range(h+1)]
        dp[-2][-2]=1
        
        for r in range(h)[::-1]:
            for c in range(w)[::-1]:
                if obstacleGrid[r][c] != 1:
                    dp[r][c] += dp[r+1][c]
                    dp[r][c] += dp[r][c+1]
                
        return dp[0][0]

```
