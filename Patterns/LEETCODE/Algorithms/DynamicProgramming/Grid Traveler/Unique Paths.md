### [Unique Paths](https://leetcode.com/problems/unique-paths/) <br>

A robot is located at the top-left corner of a `m x n` grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

#### Example 1:
<img src="../../../../../images/robot_maze.png">

```
Input: m = 3, n = 7
Output: 28

```

#### Example 2:

```
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

```

#### Example 3:

```
Input: m = 7, n = 3
Output: 28

```
#### Example 4:

```
Input: m = 3, n = 3
Output: 6

```
# Solutions

### Python
```
    def uniquePaths(self, m: int, n: int) -> int:
        '''
        Ex. m=3 , n=2
        [1, 1, 1], 
        [1, 2, 2], 
        [1, 3, 3], 
        [1, 3, 0]
        dp[m][n] never accessed so we return dp[m-1][n-1]
        '''
        dp=[[0]*(n+1) for _ in range(m+1)]
        dp[0][0]=1

        for i in range(m):
            for j in range(n):
                dp[i][j+1] += dp[i][j]
                dp[i+1][j] += dp[i][j]
        return dp[m-1][n-1]


class Solution:
#     def uniquePaths(self, m: int, n: int) -> int:
#         '''
#         Recursion
        
#         '''
#         memo={}
        
#         def dfs(m: int, n: int) -> int:
#             if m==1 and n==1:
#                 return 1
#             if m==0 or n==0:
#                 return 0
            
#             if (m,n) in memo.keys():
#                 return memo[(m,n)]
#             memo[(m,n)] = dfs(m-1, n) + dfs(m, n-1)
#             return memo[(m,n)]
        
        
#         return dfs(m,n)
    
#     def uniquePaths(self, m: int, n: int) -> int:
#         '''
#         Tabulation
        
#         '''
#         dp=[[0]*(m+1) for i in range(n+1)]
#         dp[1][1]=1
        
#         for r in range(1, n+1):
#             for c in range(1, m+1):
#                 if r+1<=n:
#                     dp[r+1][c] += dp[r][c]
#                 if c+1<=m:
#                     dp[r][c+1] += dp[r][c]
        
#         return dp[-1][-1]
    
#     def uniquePaths(self, m: int, n: int) -> int:
#         '''
#         Tabulation 2
#         '''
#         dp=[[0]*(n+1) for i in range(m+1)]
#         dp[-2][-2]=1
        
#         for r in range(m)[::-1]:
#             for c in range(n)[::-1]:
#                 dp[r][c] += dp[r+1][c]
#                 dp[r][c] += dp[r][c+1]
                
#         return dp[0][0]

    def uniquePaths(self, m: int, n: int) -> int:
        '''
        Tabulation 3
        '''
        dp=[[0]*n for _ in range(m)]
        dp[0][0]=1
        for r in range(m):
            for c in range(n):
                if r>0:
                    dp[r][c] += dp[r-1][c]
                if c>0:
                    dp[r][c] += dp[r][c-1]
                    
        return dp[-1][-1]

```
