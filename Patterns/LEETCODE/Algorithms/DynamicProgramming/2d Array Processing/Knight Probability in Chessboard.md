### [Knight Probability in Chessboard](https://leetcode.com/problems/knight-probability-in-chessboard/) <br>

On an `n x n` chessboard, a knight starts at the cell `(row, column)` and attempts to make exactly `k` moves. The rows and columns are **0-indexed**, so the top-left cell is `(0, 0)`, and the bottom-right cell is `(n - 1, n - 1)`.

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.

<img src="../../../../../images/688-knight.png">


Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly `k` moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.





#### Example 1:

```
Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.

```

#### Example 2:

```
Input: n = 1, k = 0, row = 0, column = 0
Output: 1.00000

```



# Solutions

### Python
```
class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        '''
        Memoization
        Idea here is to calculeate k moves within board 
        and divide every move by 8-number of total moves for a knight
        
        Time:  (N^2 * K) * 8
        Space: N^2 * K
        
        '''
        
        dirs=[(-2,-1),(-2,1),(-1,-2),(1,-2),(2,-1),(2,1),(1,2),(-1,2)]
        
        @lru_cache(None)
        def dp(r,c, path):            
            if path==k:
                return 1

            res=0
            for d in dirs:
                rr=r+d[0]
                cc=c+d[1]
                if 0<=rr<n and 0<=cc<n:
                    res += dp(rr,cc,path+1) / 8
                
            return res
                
        return dp(row,column,0)
    
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        '''
        Tabulation
        Idea here is to calculeate k moves within board 
        and divide every move by 8-number of total moves for a knight
        
        Since it's tabulation we can optimize it,
        because every step we depend on k-1 step
        
        Time:  (N^2 * K) * 8
        Space: N^2 * K
        
        '''
        dirs=[(-2,-1),(-2,1),(-1,-2),(1,-2),(2,-1),(2,1),(1,2),(-1,2)]        
        dp=[[[0]*(n+1) for _ in range(n+1)] for _ in range(k+1)]
        dp[0][row][column]=1
        
        for kk in range(1, k+1):
            for r in range(n):
                for c in range(n):
                    for d in dirs:
                        old_r=r+d[0]
                        old_c=c+d[1]
                        if 0<=old_r<n and 0<=old_c<n:
                            dp[kk][r][c] += dp[kk-1][old_r][old_c] / 8

                            
        res=0
        # accumulate all probabilites of the last step
        for r in range(n):
            for c in range(n):
                res += dp[k][r][c]
        return res

```
