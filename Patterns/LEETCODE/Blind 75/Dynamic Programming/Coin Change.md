### [Coin Change](https://leetcode.com/problems/coin-change/) <br>

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

**Return the fewest number of coins that you need to make up that amount**. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

#### Example 1:

```
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

```

#### Example 2:

```
Input: coins = [2], amount = 3
Output: -1

```

#### Example 3:

```
Input: coins = [1], amount = 0
Output: 0

```

#### Example 4:

```
Input: coins = [1], amount = 1
Output: 1

```

#### Example 5:

```
Input: coins = [1], amount = 2
Output: 2

```


# Solutions

### Python
```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        '''
        Recursion
        '''
        if amount == 0: return 0
        memo = {}

        def dfs(path):
            if path == 0:
                return 0
            if path < 0:
                return None
            if path in memo:
                return memo[path]
            
            
            shortest = None
            for coin in coins:
                remainder=path-coin
                out = dfs(remainder)
                
                if out is not None:
                    out = out + 1
                    if shortest is None or out<shortest:
                        shortest=out
                        
            memo[path] = shortest
            return memo[path]
        
        short=dfs(amount)
        
        
        if short != None:
            return short
        return -1
    
        
        
#         if arr:
#             return len(arr)
#         return -1
    
#     def coinChange(self, coins: List[int], amount: int) -> int:
#         '''
#         BFS Time Limit Exceeded
#         '''
#         res=sys.maxsize
#         vis=set() 
#         q=[(amount, 0)]
        
#         while len(q)>0:
#             path, level = q.pop()
#             if path == 0:
#                 return level
#             vis.add(path)
#             for coin in coins:
#                 rem=path-coin
#                 if rem >= 0 and rem not in vis:
#                     q.insert(0, (rem, level+1))
        
#         return -1
        
    
    
#     def coinChange(self, coins: List[int], amount: int) -> int:
#         '''
#         Dynamic programming
#         '''
#         if amount==0: return 0
        
#         dp=[None for _ in range(amount+1)]
#         dp[0]=0
        
#         for i in range(0, amount+1):
#             if dp[i] != None:
#                 for coin in coins:
#                     if (i+coin) >= len(dp):
#                         continue
#                     if dp[i+coin] == None or dp[i]+1<dp[i+coin]: 
#                         dp[i+coin]=dp[i]+1
        
#         # print(dp)
#         if dp[-1]:
#             return dp[-1]
#         else:
#             return -1

```
