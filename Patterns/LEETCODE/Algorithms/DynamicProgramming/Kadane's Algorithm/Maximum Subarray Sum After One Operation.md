### [Maximum Subarray Sum After One Operation](https://leetcode.com/problems/maximum-subarray-sum-after-one-operation/) <br>

You are given an integer array `nums`. You must perform **exactly one** operation where you can **replace** one element `nums[i]` with `nums[i] * nums[i]`. 

Return *the* **maximum** *possible subarray sum after* **exactly one** *operation*. The subarray must be non-empty.

#### Example 1:

```
Input: nums = [2,-1,-4,-3]
Output: 17
Explanation: You can perform the operation on index 2 (0-indexed) to make nums = [2,-1,16,-3]. Now, the maximum subarray sum is 2 + -1 + 16 = 17.

```

#### Example 2:

```
Input: nums = [1,-1,1,1,-1,-1,1]
Output: 4
Explanation: You can perform the operation on index 1 (0-indexed) to make nums = [1,1,1,1,-1,-1,1]. Now, the maximum subarray sum is 1 + 1 + 1 + 1 = 4.

```

# Solutions

### Python
```
class Solution:
    def maxSumAfterOperation(self, nums: List[int]) -> int:
        '''
        Kadane's Algorithm
        '''
        n=len(nums)
        if n==1: return abs(nums[0]*nums[0])

        squared=0 # one already squared
        max_sum=0 # non squared sum
        best_sum=0
        
        for num in nums:
            squared=max(max_sum + num*num,  squared+num)
            max_sum=max(0, max_sum + num)
            best_sum=max(best_sum, squared, max_sum)
            
        
        return best_sum

```
