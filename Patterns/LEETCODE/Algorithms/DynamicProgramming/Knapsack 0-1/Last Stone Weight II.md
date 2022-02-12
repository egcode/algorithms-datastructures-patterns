### [Last Stone Weight II](https://leetcode.com/problems/last-stone-weight-ii/) <br>

You are given an array of integers `stones` where `stones[i]` is the weight of the `it-h` stone.

We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights `x` and `y` with `x <= y`. The result of this smash is:

 - If `x == y`, both stones are destroyed, and
 - If `x != y`, the stone of weight `x` is destroyed, and the stone of weight `y` has new weight `y - x`.

At the end of the game, there is **at most one stone** left.

Return *the smallest possible weight of the left stone. If there are no stones left, return* `0`.



#### Example 1:

```
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.

```

#### Example 2:

```
Input: stones = [31,26,33,21,40]
Output: 5

```



# Solutions

### Python
```
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        '''
        let say array be [a,b,c,d]
        answer = (a+b)-(c+d) OR
        answer = a-(b+c+d) Or
        answer = (d+b)-(a+c) and so on.. any combination could be possible
        notice that in general I can say that
        answer = S1-S2
        where S1 is sum of some of the numbers and S2 is sum of rest of numbers
        also note that S1+S2 = SUM (sum of all numbers)
        S1 >= S2 beacuse negative answer is not possible
        now we have to minimise answer
        answer = SUM - 2*S2 (Just substituting S1 by SUM-S2)
        To minimise answer S2 has to be maximum
        Now, max value of S2 is SUM/2 (bigger than this and answer would be negative which is not possible)
        so the question reduces to find closest sum (sum of numbers) to (SUM/2)
        now this could
        '''
        total=sum(stones)
        half=total//2
        n=len(stones)
        
        dp=[[0]*(half+1) for _ in range(n+1)]
        
        for i in range(1,n+1):
            for j in range(1,half+1):
                if stones[i-1]>j:
                    dp[i][j] = dp[i-1][j]
                else:
                    dp[i][j]=max(dp[i-1][j], dp[i-1][j-stones[i-1]]+stones[i-1])
        
        return total - (2*dp[n][half])
    
    
    def lastStoneWeightII(self, stones: List[int]) -> int:
        '''
        what is the minimum difference between the sum of two groups.
        Now it's a easy classic knapsack problem.
        
        '''
        dp = {0}
        total = sum(stones)
        for stone in stones:
            s=set()
            for i in dp:
                s |= {stone + i}
            dp |= s
            
        res=float('inf')
        for s in dp:
            res = min(res, abs(total - s*2))
        return res
    

    def lastStoneWeightII(self, stones: List[int]) -> int:
        '''
        Memoization
        Here we find minimum difference between two different groups
            Code is similar to 494. Target Sum
        '''
        total=sum(stones)
        N=len(stones)
        
        @lru_cache(None)
        def dfs(i, path):
            if i==N:
                return path
            return min(abs(dfs(i+1, path+stones[i])), abs(dfs(i+1, path-stones[i])))
        
        return dfs(0, 0)

```
