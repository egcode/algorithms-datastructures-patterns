### [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) <br>

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the <img src="https://render.githubusercontent.com/render/math?math=i^{th}"> day, and an integer `k`.

Find the maximum profit you can achieve. You may complete at most `k` transactions.

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).








#### Example 1:

```
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

```

#### Example 2:

```
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

```

# Solutions

### Python
```
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
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
        if k==0: return 0
        if not prices: return 0
        dp=[0 for _ in range(len(prices))]
        
        for _ in range(1, k+1):
            buy=-prices[0]
            sell=0
            profit=0
            for i in range(1, len(prices)):
                buy = max(buy, dp[i]-prices[i])
                sell = max(sell, buy+prices[i])
                profit = max(profit, sell)
                dp[i]=profit
                
        return profit        
```
