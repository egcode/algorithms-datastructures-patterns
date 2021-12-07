### [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) <br>

You are given an array `prices` where `prices[i]` is the price of a given stock on the <img src="https://render.githubusercontent.com/render/math?math=i^{th}"> day.

Find the maximum profit you can achieve. You may complete **at most two transactions**.

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



#### Example 1:

```
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

```

#### Example 2:

```
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

```


#### Example 3:

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

```

#### Example 4:

```
Input: prices = [1]
Output: 0

```


# Solutions

### Python
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ###########################################################
        ########### Original Best Time to Buy and Sell Stock:######
        ###########################################################
        ###### if not prices: return 0
        ###### buy=-prices[0]
        ###### sell=0
        ###### profit=0
        ###### for i in range(1, len(prices)):
        ######     buy = max(buy, -prices[i])
        ######     sell = max(sell, buy+prices[i])
        ######     profit = max(profit, sell)
        ###### return profit
        #############################################
        '''
        Max Profit with K transations:
        '''
        if not prices: return 0
        dp=[0 for _ in range(len(prices))]
        
        K_transactions=2
        for i in range(1, K_transactions+1):
            buy=-prices[0]
            sell=0
            profit=0
            for i in range(1, len(prices)):
                buy = max(buy, dp[i]-prices[i])
                sell = max(sell, buy+prices[i])
                profit = max(profit, sell)
                dp[i]=profit
                
        return profit
    
    
#     def maxProfit(self, prices: List[int]) -> int:
#         if not prices: return 0
#         s1,s2,s3,s4 = -prices[0], float('-inf'), float('-inf'), float('-inf')
        
#         for p in prices:
#             s1=max(s1, -p)
#             s2=max(s2, s1+p)
#             s3=max(s3, s2-p)
#             s4=max(s4, s3+p)
            
#         return max(s4, 0)

```
