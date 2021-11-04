### [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) <br>

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`-th day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

 - After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



#### Example 1:

```
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

```

#### Example 2:

```
Input: prices = [1]
Output: 0

```

# Solutions

### Python
```
class Solution:
#     def maxProfit(self, prices: List[int]) -> int:
#         n=len(prices)
#         if not prices: return 0
        
#         Hold=[0]*(n+1)
#         NotHold=[0]*(n+1)
        
#         Hold[1]=-prices[0]

#         for i in range(1, n):
#             Hold[i+1]=max(Hold[i], NotHold[i-1]-prices[i])
#             NotHold[i+1]=max(NotHold[i], Hold[i]+prices[i])
#         return NotHold[-1]

    
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n <= 1: return 0
        
        diff = [prices[i+1] - prices[i] for i in range(n-1)]
        dp = [0]*(n+1) 
        dp_max = [0]*(n+1)
        
        for i in range(n-1):
            dp[i] = diff[i] + max(dp_max[i-3], dp[i-1])
            dp_max[i] = max(dp_max[i-1], dp[i])
            
        return dp_max[-3]

```
