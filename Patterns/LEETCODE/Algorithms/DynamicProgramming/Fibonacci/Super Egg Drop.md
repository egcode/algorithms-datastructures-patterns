### [Super Egg Drop](https://leetcode.com/problems/super-egg-drop/) <br>

You are given `k` identical eggs and you have access to a building with `n` floors labeled from `1` to `n`.

You know that there exists a floor `f` where `0 <= f <= n` such that any egg dropped at a floor **higher** than `f` will **break**, and any egg dropped **at or below** floor `f` will **not break**.

Each move, you may take an unbroken egg and drop it from any floor `x` (where `1 <= x <= n`). If the egg breaks, you can no longer use it. However, if the egg does not break, you may **reuse** it in future moves.

Return *the* ***minimum number of moves*** *that you need to determine* ***with certainty*** *what the value of f is*.


#### Example 1:

```
Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.

```

#### Example 2:

```
Input: k = 2, n = 6
Output: 3

```

#### Example 3:

```
Input: k = 3, n = 14
Output: 4

```



# Solutions

### Python
```
class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        '''
        Memoization (Correct but TLE)
        '''
        @lru_cache(None)
        def dp(floor, eggs):
            
            if eggs==1 or floor<=1: # try floor one by one
                return floor
            
            res = float('inf')
            for f in range(1, floor+1): # we don't know at which floor the egg will break
                egBrake  = dp(f-1, eggs-1)
                egRemain = dp(floor-f, eggs)
                res=min(res, 1 + max(egBrake, egRemain))
            return res
            
        return dp(n, k)

    def superEggDrop(self, k: int, n: int) -> int:
        '''
        Tabulation (Correct but TLE)
          Example: k = 2, n = 6
          
            Result: 4
          
          Start with:
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
            [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
            [0, inf, inf, inf, inf, inf, inf, inf, inf, inf]
            [0, inf, inf, inf, inf, inf, inf, inf, inf, inf]

          End with:
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
            [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
            [0, 1, 2, 2, 3, 3, 3, 4, 4, 4]
            [0, 1, 2, 2, 3, 3, 3, 3, 4, 4]
          
        '''
        dp = [[float('inf')] * (n+1) for _ in range(k+1)]
        
        for nn in range(n+1):
            dp[0][nn]=0
            dp[1][nn]=nn
        
        for kk in range(k+1):
            dp[kk][0]=0
                        
        for eg in range(2, k+1):
            for fl in range(1, n+1):
                for floor in range(1, fl+1):
                    eg_break  = dp[eg-1][floor-1]
                    eg_remain = dp[eg][fl-floor]
                    dp[eg][fl]=min(dp[eg][fl], 1+max(eg_break, eg_remain))
                                        
        return dp[k][n]

    def superEggDrop(self, k: int, n: int) -> int:
        '''
        Optimized tricky solution
        '''
        dp=[[0]*(k+1) for _ in range(n+1)]
        for i in range(1, n+1):
            for j in range(1, k+1):
                dp[i][j]=1+dp[i-1][j-1] + dp[i-1][j]
            if dp[i][k] >= n:
                return i

```
