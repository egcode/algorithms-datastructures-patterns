### [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) <br>

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return *its sum*.

A **subarray** is a **contiguous** part of an array.



#### Example 1:

```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

```

#### Example 2:

```
Input: nums = [1]
Output: 1

```

#### Example 3:

```
Input: nums = [5,4,-1,7,8]
Output: 23

```

# Solutions

### Python
```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        '''
        Kadane's Algorithm
        '''
        best_sum=nums[0]
        current_sum=nums[0]
        
        for num in nums[1:]:
            current_sum=max(num, current_sum + num)
            best_sum=max(best_sum, current_sum)
        return best_sum
    
#     def maxSubArray(self, nums: List[int]) -> int:
#         summ=0
#         res=max(nums)
        
#         for num in nums:
#             summ += num
            
#             if summ<0:
#                 summ=0
#             else:
#                 res=max(res, summ)
                
#         return res

```
