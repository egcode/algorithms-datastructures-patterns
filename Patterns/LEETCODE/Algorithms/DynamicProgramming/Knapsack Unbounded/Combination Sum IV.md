### [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/) <br>

Given an array of **distinct** integers `nums` and a target integer `target`, return the number of possible combinations that add up to `target`.

The answer is **guaranteed** to fit in a **32-bit** integer.

#### Example 1:

```
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

```

#### Example 2:

```
Input: nums = [9], target = 3
Output: 0

```

# Solutions

### Python
```
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        '''
        Dynamic Programming tabulation (nums version of count_construct3)
        
        Example:
            nums=[1,2,3] target=4
        
        total =  0 1 2 3 4
           dp = [1,0,0,0,0]  - represents all target digits
                     
        loop through and if (i-num >= 0) that means that this num could be part of target
        
        
        Same as Coin Change 2 problem
            There is an important difference between the two, 
            the order of the loops are interchanged.

            This problemcounts all the permutations 
            [1, 1, 2], [1,2,1] and [1, 1, 2] as different solutions to the sum of 4.

            In the coin-change-2 problem, 
            [1, 1, 2], [1,2,1] and [1, 1, 2] are counted as one solution.
        
        '''
        dp=[0]*(target+1)
        dp[0]=1 # could be part of target 
        
        for total in range(target+1):
            for num in nums:
                if total-num >= 0: # num could be part of target
                    dp[total] += dp[total-num]
        # print(dp)
        return dp[target]
        
    
#     def combinationSum4(self, nums: List[int], target: int) -> int:
#         '''
#         DFS
#         '''
#         n=len(nums)
#         memo={}
        
#         def dfs(summ, i):
#             if (summ,i) in memo.keys():
#                 return memo[(summ,i)]
#             if summ>target:
#                 memo[(summ,i)]=0
#                 return 0                     
#             if summ==target:
#                 memo[(summ,i)]=1
#                 return 1
            
#             out=0
#             for j in range(n):
#                 d=dfs(summ+nums[j], j)
#                 if d>0:
#                     out += d
                
#             memo[(summ,i)]=out
#             return memo[(summ,i)]
        
#         out=dfs(0,0)
#         # print(memo)
#         return out

```
