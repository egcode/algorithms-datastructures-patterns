### [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) <br>

Given an integer array `nums`, return the length of the longest strictly increasing subsequence.

A **subsequence** is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, `[3,6,2,7]` is a subsequence of the array `[0,3,1,6,2,2,7]`.

#### Example 1:

```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

```

#### Example 2:

```
Input: nums = [0,1,0,3,2,3]
Output: 4

```

#### Example 3:

```
Input: nums = [7,7,7,7,7,7,7]
Output: 1

```
# Solutions

### Python
```
class Solution:     
#     def lengthOfLIS(self, nums: List[int]) -> int:
#         res=1
        
#         dp=[1]*len(nums)
        
#         for i in range(1, len(dp)):
#             for j in range(i):
#                 if nums[i]>nums[j]:
#                     dp[i]=max(dp[i], dp[j]+1)
#                     res=max(res, dp[i])
#         return res
        
        
#     def lengthOfLIS(self, nums: List[int]) -> int:
#         '''
#         Works but Time Limit Exceeded
#         '''
#         dp=[[n] for n in nums]
#         # print(dp)
        
#         for i in range(len(nums)):
#             for j in range(i):
#                 if nums[i]>nums[j] and len(dp[i])<=len(dp[j]):
#                     dp[i]=dp[j]+[nums[i]]
            
#         # print(dp)        
#         return len(max(dp, key=len))
    
    
    def lengthOfLIS(self, nums: List[int]) -> int:
        '''
        Remember this LIS construction
        '''
        dp=[]
        
        for num in nums:
            i=0
            n=len(dp)
            while i<n:
                if num<=dp[i]:
                    break
                i += 1
            if i==n:
                dp.append(num)
            else:
                dp[i]=num
        
        return len(dp)

```
