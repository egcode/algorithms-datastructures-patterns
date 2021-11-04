### [Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) <br>

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`-th day, and an integer `fee` representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



#### Example 1:

```
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

```

#### Example 2:

```
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6

```

# Solutions

### Python
```
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        '''
        Kadane's algorithm modification
        
        Same as 122. Best Time to Buy and Sell Stock II
        We just need to make sure that we substract fee once
        
        '''
        bought=-prices[0]
        profit=0
        
        for i in range(1, len(prices)):
            buying_stock=profit-prices[i]
            bought=max(bought, buying_stock)
            
            selling_stock=bought+prices[i]
            profit=max(profit, selling_stock-fee)
           
        return profit

```
