### [Stone Game II](https://leetcode.com/problems/stone-game-ii/) <br>

Alice and Bob continue their games with piles of stones.  There are a number of piles **arranged in a row**, and each pile has a positive integer number of stones `piles[i]`.  The objective of the game is to end with the most stones. 

Alice and Bob take turns, with Alice starting first.  Initially, `M = 1`.

On each player's turn, that player can take **all the stones** in the **first** `X` remaining piles, where `1 <= X <= 2M`.  Then, we set `M = max(M, X)`.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.



#### Example 1:

```
Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 

```

#### Example 2:

```
Input: piles = [1,2,3,4,5,100]
Output: 104

```



# Solutions

### Python
```
class Solution:


    def stoneGameII(self, piles: List[int]) -> int:
        n=len(piles)                        
        @lru_cache(None)
        def dp(i, m):
            if i>=n:
                return 0
                
            res=float('-inf')
            for k in range(1, m*2+1):
                res = max(res,  sum(piles[i:i+k])  - dp(i+k, max(m,k)) )
                
            return res
        
        max_win_score = dp(0,1)
        return (max_win_score + sum(piles))//2



    def stoneGameII(self, piles: List[int]) -> int:
        n=len(piles)
        presum={-1:0}
        for i,p in enumerate(piles):
            presum[i]=p+presum[i-1]
                        
        @lru_cache(None)
        def dp(i, m):
            if i>=n:
                return 0
                
            res=float('-inf')
            for k in range(1, m*2+1):
                res = max(res,  presum[min(i+k-1,n-1)] - presum[i-1] - dp(i+k, max(m,k)) )
            return res
        
        max_win_score = dp(0,1)
        return (max_win_score + presum[n-1])//2

```
