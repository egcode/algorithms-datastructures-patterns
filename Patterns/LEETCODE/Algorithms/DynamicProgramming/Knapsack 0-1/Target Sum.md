### [Target Sum](https://leetcode.com/problems/target-sum/) <br>

You are given an integer array `nums` and an integer `target`.

You want to build an **expression** out of nums by adding one of the symbols `'+'` and `'-'` before each integer in nums and then concatenate all the integers.

 - For example, if `nums = [2, 1]`, you can add a `'+'` before 2 and a `'-'` before `1` and concatenate them to build the expression `"+2-1"`.

Return the number of different **expressions** that you can build, which evaluates to `target`.



#### Example 1:

```
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

```

#### Example 2:

```
Input: nums = [1], target = 1
Output: 1

```

# Solutions

### Python
```
class Solution:
#     def findTargetSumWays(self, nums: List[int], S: int) -> int:
        
#         @cache
#         def dfs(i, path):
            
#             if i==len(nums):
#                 if path==S:
#                     return 1
#                 else:
#                     return 0
#             return dfs(i+1, path+nums[i]) + dfs(i+1, path-nums[i])
        
#         return dfs(0, 0)
    
    
    
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        
        memo={}
        def dfs(i, path):
            
            if (i,path) in memo.keys():
                return memo[(i, path)]
            
            if i==len(nums):
                if path==S:
                    memo[(i,path)]=1
                    return 1
                else:
                    memo[(i,path)]=0
                    return 0
            else:
                r = dfs(i+1, path+nums[i]) + dfs(i+1, path-nums[i])
                memo[(i, path)]=r
                return memo[(i, path)]
                    
        
        
        return dfs(0, 0)    
```
