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
        Dynamic programming, Tabulation
        '''
        if amount==0: return 0
        dp=[float('inf')]*(amount+1)
        dp[0]=0
        
        for am in range(1, amount+1):
            for coin in coins:
                if am-coin < 0: 
                    continue
                dp[am]=min(dp[am], 1+dp[am-coin])
        
        if dp[amount] != float('inf'):
            return dp[amount]
        return -1


#     def coinChange(self, coins: List[int], amount: int) -> int:
#         '''
#         Recursion
#         '''
#         if amount == 0: return 0
#         memo = {}

#         def dfs(path):
#             if path == 0:
#                 return 0
#             if path in memo:
#                 return memo[path]
            
#             shortest = float('inf')
#             for coin in coins:
#                 if path-coin < 0:
#                     continue
#                 out = dfs(path-coin)
#                 shortest=min(shortest, out+1)
                        
#             memo[path] = shortest
#             return memo[path]
        
#         short=dfs(amount)
        
        
#         if short != float('inf'):
#             return short
#         return -1

```
