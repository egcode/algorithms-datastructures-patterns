### [Maximum Score from Performing Multiplication Operations](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/) <br>

You are given two integer arrays `nums` and `multipliers` of size `n` and `m` respectively, where `n >= m`. The arrays are **1-indexed**.

You begin with a score of `0`. You want to perform **exactly** `m` operations. On the <img src="https://render.githubusercontent.com/render/math?math=i^{th}"> operation **(1-indexed)**, you will:

 - Choose one integer `x` from **either the start or the end** of the array `nums`.
 - Add `multipliers[i] * x` to your score.
 - Remove `x` from the array `nums`.

*Return the* ***maximum*** *score after performing `m` operations*.



#### Example 1:

```
Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3] (pick 3), adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2] (pick 2), adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.

```

#### Example 2:

```
Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
Explanation: An optimal solution is as follows:
- Choose from the start, [-5,-3,-3,-2,7,1] (pick -5), adding -5 * -10 = 50 to the score.
- Choose from the start, [-3,-3,-2,7,1] (pick -3), adding -3 * -5 = 15 to the score.
- Choose from the start, [-3,-2,7,1] (pick -3), adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,1] (pick 1), adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,7] (pick 7), adding 7 * 6 = 42 to the score. 
The total score is 50 + 15 - 9 + 4 + 42 = 102.

```

# Solutions

### Python
```
class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        '''
        Tabulation
        
        Example:
            nums = [-5,-3,-3,-2,7,1]
            multipliers = [-10,-5,3,4,6]
            output: 102
            
            Start with Aray dp:
            [0, 0, 0, 0, 0, 0]
            [0, 0, 0, 0, 0, 0]
            [0, 0, 0, 0, 0, 0]
            [0, 0, 0, 0, 0, 0]
            [0, 0, 0, 0, 0, 0]
            [0, 0, 0, 0, 0, 0]
            
            End with:
            [102,   0,   0,  0,  0,  0] # left=0 right=5, run once  
            [ 46,  52,   0,  0,  0,  0] # left=1 right=5, (continue until left=0, right=4)
            [-36,  21,  37,  0,  0,  0] # left=2 right=5, (continue until left=0, right=3)
            [-30, -24,  30, 46,  0,  0] # left=3 right=5, (continue until left=0, right=2)
            [-18, -18, -12, 42, 42,  0] # left=4 right=5, (continue until left=0, right=1)
            [  0,   0,   0,  0,  0,  0]
            
        
        '''
        n=len(nums)
        m=len(multipliers)
        dp=[[0]*(m+1) for _ in range(m+1)]
        
        for i in range(m)[::-1]:
            for left in range(i+1)[::-1]: # we need i inclusive
                mult = multipliers[i]
                right = n - 1 - (i - left)
                dp[i][left] = max(mult * nums[left] + dp[i + 1][left + 1], 
                                  mult * nums[right] + dp[i + 1][left])  
                        
        return dp[0][0]    
    
    
#     def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
#         '''
#         Memoization
#         '''
#         n=len(nums)
#         m=len(multipliers)
        
#         @lru_cache(2000)
#         def dfs(left, i):
#             if i==m:
#                 return 0
#             right=n-1-(i-left) # i-total  `i-left` means total minus right
            
#             return  max(multipliers[i]*nums[left]+dfs(left+1, i+1),
#                         multipliers[i]*nums[right]+dfs(left, i+1))
        
#         return dfs(0, 0)
                
```
