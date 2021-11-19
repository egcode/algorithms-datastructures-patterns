### [Coin Change II](https://leetcode.com/problems/coin-change-2/) <br>

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

**Return the number of combinations that make up that amount**. If that amount of money cannot be made up by any combination of the coins, return `0`.

You may assume that you have an infinite number of each kind of coin.

The answer is **guaranteed** to fit into a signed **32-bit** integer.



#### Example 1:

```
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

```

#### Example 2:

```
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

```

#### Example 3:

```
Input: amount = 10, coins = [10]
Output: 1

```

# Solutions

### Python
```
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        '''
        Tabulation
         Same as Combination Sum IV
            There is an important difference between the two, 
            the order of the loops are interchanged.

            This problem counts all the permutations             
            [1, 1, 2], [1,2,1] and [1, 1, 2] are counted as one solution.

            In the Combination Sum IV problem, 
            [1, 1, 2], [1,2,1] and [1, 1, 2] as different solutions to the sum of 4.
            
        '''
        dp = [0] * (amount + 1)
        dp[0] = 1
        
        for coin in coins:
            for x in range(coin, amount + 1):
                dp[x] += dp[x - coin]
        return dp[amount]    
    
    
#     def change(self, amount: int, coins: List[int]) -> int:
#         '''
#         Tabulation
        
#         amount=5 coins[1,2,5]
        
#           5 4 3 2 1 0
#         1 0 0 0 0 0 1
#         2 0 0 0 0 0 1
#         5 0 0 0 0 0 1
#           0 0 0 0 0 1
          
#         Base case is 1, it takes one for any coin to get zero
#         '''
#         dp=[[0]*(amount+1) for _ in range(len(coins)+1)]
#         for row in dp:
#             row[-1]=1
        
#         for row in range(len(coins))[::-1]:
#             for col in range(amount)[::-1]:
                
#                 left=0
#                 sourceRow = col+coins[row] # (current column + current coin)
#                 if sourceRow <= amount: # if source row is not out of bounds
#                     left=dp[row][sourceRow]
                    
#                 bottom=dp[row+1][col]
                
#                 dp[row][col] = left + bottom
            
#         # print(dp)
#         return dp[0][0]
            
    
    
    
#     def change(self, amount: int, coins: List[int]) -> int:
#         '''
#         DFS
        
#         Complexity: time: O(n*m)  space: O(n*m)
         
#         '''
#         res=0
#         memo={}
        
#         def dfs(path, index):
#             if path==0:
#                 return 1
#             if path<0 or index>=len(coins):
#                 return 0
#             if (path, index) in memo.keys():
#                 return memo[(path, index)]
            
#             # sum of combinations with current index
#             sum1 = dfs(path-coins[index], index)
            
#             # sum of combinations with next index, current index is not included         
#             sum2 = dfs(path, index+1)
                
#             memo[(path, index)] = sum1+sum2
#             return memo[((path, index))]
        
#         return dfs(amount, 0)
```
