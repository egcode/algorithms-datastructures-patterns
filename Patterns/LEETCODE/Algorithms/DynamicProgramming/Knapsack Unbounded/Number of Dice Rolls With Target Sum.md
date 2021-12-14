### [Number of Dice Rolls With Target Sum](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/) <br>

You have d dice and each die has `f` faces numbered `1, 2, ..., f`. You are given three integers `d`, `f`, and `target`.

Return *the number of possible ways (out of* <img src="https://render.githubusercontent.com/render/math?math=f^d"> *total ways)* **modulo** <img src="https://render.githubusercontent.com/render/math?math=10^9"> + <img src="https://render.githubusercontent.com/render/math?math=7"> *to roll the dice so the sum of the face-up numbers equals target*.



#### Example 1:

```
Input: d = 1, f = 6, target = 3
Output: 1
Explanation: 
You throw one die with 6 faces.  There is only one way to get a sum of 3.

```

#### Example 2:

```
Input: d = 2, f = 6, target = 7
Output: 6
Explanation: 
You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

```


#### Example 3:

```
Input: d = 2, f = 5, target = 10
Output: 1
Explanation: 
You throw two dice, each with 5 faces.  There is only one way to get a sum of 10: 5+5.

```

#### Example 4:

```
Input: d = 1, f = 2, target = 3
Output: 0
Explanation: 
You throw one die with 2 faces.  There is no way to get a sum of 3.

```

#### Example 5:

```
Input: d = 30, f = 30, target = 500
Output: 222616187
Explanation: 
The answer must be returned modulo 10^9 + 7.

```


# Solutions

### Python
```
class Solution:
#    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
#         '''
#         Memoization

#         '''
#         MOD = 10**9 + 7
        
#         @lru_cache(None)
#         def dfs(dice, path):
#             if path==0:
#                 if dice==0: # Only if both `path` and `dice` ==0
#                     return 1
#                 else:
#                     return 0
#             if path<0 or dice<=0:
#                 return 0
            
#             out=0
#             for face in range(1,f+1):
#                 out += dfs(dice-1, path-face)
#             return out
            
#         res=dfs(d, target)
#         return res % MOD
    
    
    

    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        '''
        Same as [518. Coin Change 2](https://leetcode.com/problems/coin-change-2/)
        with the difference that the total number of coins (dices) should be equal to d
        
        Memoization
            d = 2, f = 6, target = 7
            Output: 6
            
            Start with:
                [1, 0, 0, 0, 0, 0, 0, 0]
                
            End with:
                [0, 0, 1, 2, 3, 4, 5, 6]
 
        '''
        dp=[0]*(target+1)
        dp[0]=1
        
        for _ in range(d):
            dp1=[0]*(target+1)
            for i in range(1, f+1):
                for k in range(i, target+1):
                    dp1[k] += dp[k-i]
                    
            dp=dp1

        return dp[-1] % 1000000007

```
