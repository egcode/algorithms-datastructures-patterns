### [Profitable Schemes](https://leetcode.com/problems/profitable-schemes/) <br>

There is a group of `n` members, and a list of various crimes they could commit. The <img src="https://render.githubusercontent.com/render/math?math=i^{th}"> crime generates a `profit[i]` and requires `group[i]` members to participate in it. If a member participates in one crime, that member can't participate in another crime.

Let's call a **profitable scheme** any subset of these crimes that generates at least `minProfit` profit, and the total number of members participating in that subset of crimes is at most `n`.

Return the number of schemes that can be chosen. Since the answer may be very large, **return it modulo** <img src="https://render.githubusercontent.com/render/math?math=10^9"> + <img src="https://render.githubusercontent.com/render/math?math=7">.



#### Example 1:

```
Input: n = 5, minProfit = 3, group = [2,2], profit = [2,3]
Output: 2
Explanation: To make a profit of at least 3, the group could either commit crimes 0 and 1, or just crime 1.
In total, there are 2 schemes.

```

#### Example 2:

```
Input: n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
Output: 7
Explanation: To make a profit of at least 5, the group could commit any crimes, as long as they commit one.
There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).

```



# Solutions

### Python
```
class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        totalCrimes=len(profit)
        MOD=1000000007
        
        @lru_cache(None)
        def dp(crime, membs, prof):
            if membs==0:
                return 1 if prof==0 else 0
            if crime==0:
                return 1 if prof==0 else 0
            
            res=dp(crime-1, membs, prof)
            if group[crime-1] <= membs:
                res += dp(crime-1, membs-group[crime-1], max(0, prof-profit[crime-1]))
                
            return res % MOD

        return dp(totalCrimes, n, minProfit)

```
