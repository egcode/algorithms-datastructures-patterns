### [House Robber](https://leetcode.com/problems/house-robber/) <br>

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return the **maximum amount of money** you can rob tonight **without alerting the police**.

#### Example 1:

```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

```

#### Example 2:

```
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

```

# Solutions

### Python
```
class Solution:
#     def rob(self, nums: List[int]) -> int:
#         a=0
#         b=0
        
#         for i in range(len(nums)):
#             if i%2==0:
#                 a=max(b, nums[i]+a)
#             else:
#                 b=max(a, nums[i]+b)
            
#         return max(a,b)
    
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        memo={}
        
        def dfs(i):
            if i in memo.keys():
                return memo[i]
            if i>=n:
                return 0
            
            res=max(nums[i]+dfs(i+2), dfs(i+1))
            memo[i]=res
            return res
        return dfs(0)

```
