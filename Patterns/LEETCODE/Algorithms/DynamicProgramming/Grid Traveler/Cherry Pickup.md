### [Cherry Pickup](https://leetcode.com/problems/cherry-pickup/) <br>

You are given an `n x n` `grid` representing a field of cherries, each cell is one of three possible integers.

 - `0` means the cell is empty, so you can pass through,
 - `1` means the cell contains a cherry that you can pick up and pass through, or
 - `-1` means the cell contains a thorn that blocks your way.

Return *the maximum number of cherries you can collect by following the rules below*:

 - Starting at the position `(0, 0)` and reaching `(n - 1, n - 1)` by moving right or down through valid path cells (cells  with value `0` or `1`).
 - After reaching `(n - 1, n - 1)`, returning to `(0, 0)` by moving left or up through valid path cells.
 - When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell `0`.
 - If there is no valid path between `(0, 0)` and `(n - 1, n - 1)`, then no cherries can be collected.
 



#### Example 1:
<img src="../../../../../images/741grid.jpg">

```
Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
Output: 5
Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.

```

#### Example 2:

```
Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
Output: 0

```



# Solutions

### Python
```
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        '''
        Memoization
        starting from 0 to n-1 at the same time. 
        '''
        
        if not grid: return 0
        h=len(grid)
        w=len(grid[0])
        if h==1 and w==1: return grid[0][0]
        dirs=[[1,0],[0,1]]
        
        
        @lru_cache(None)
        def dp(r1, c1, r2, c2):
            if r1>=h or c1>=w or r2>=h or c2>=w:
                return -inf  
            if grid[r1][c1]==-1 or grid[r2][c2]==-1:
                return -inf
            if r1+c1 != r2+c2: # paths len should be the same
                return -inf
            
            if r1==h-1 and c1==w-1 and r2==h-1 and c2==w-1:
                return grid[h-1][w-1]
            
            
            res=-inf
            for d1 in dirs:
                for d2 in dirs:
                    row1=r1+d1[0]
                    col1=c1+d1[1]                    
                    row2=r2+d2[0]
                    col2=c2+d2[1]
                    res = max(res, dp(row1,col1,row2,col2))            
            
            cherries=0
            if r1==r2 and c1==c2:
                cherries=grid[r1][c1]
            else:
                cherries=grid[r1][c1]+grid[r2][c2]                
            return res+cherries
        
        
        res=dp(0,0,0,0)
        if res==-inf:
            return 0
        return res

```
