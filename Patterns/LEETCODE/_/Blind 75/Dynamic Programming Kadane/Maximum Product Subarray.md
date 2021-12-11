### [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) <br>

Given an integer array `nums`, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

It is **guaranteed** that the answer will fit in a **32-bit** integer.

A **subarray** is a contiguous subsequence of the array.



#### Example 1:

```
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

```

#### Example 2:

```
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

```

# Solutions

### Python
```
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        '''
        Kadane's Algorithm multiply version
        '''
        
        n=len(nums)
        max_so_far = [0]*n
        min_so_far = [0]*n
        
        max_so_far[0]=nums[0]
        min_so_far[0]=nums[0]
        res=nums[0]
        
        for i in range(1, n):
            max_so_far[i]=max(nums[i], nums[i]*max_so_far[i-1], nums[i]*min_so_far[i-1])
            min_so_far[i]=min(nums[i], nums[i]*max_so_far[i-1], nums[i]*min_so_far[i-1])
            
            res = max(res, max_so_far[i], min_so_far[i])
        return res

```
