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
        Kadane's Algorythm, multiply version
        '''
        curMin, curMax = 1, 1
        res = max(nums)
        for num in nums:
            oldCurMin = curMin
            curMin = min(num, oldCurMin * num, curMax * num)
            curMax = max(num, oldCurMin * num, curMax * num)
            res = max(res, curMin, curMax)

        return res

    # def maxProduct(self, nums: List[int]) -> int:
    #     '''
    #     Kadane's Algorythm, multiply version
    #     '''

    #     n = len(nums)
    #     cur_sum_max, cur_sum_min = [0] * n, [0] * n
    #     best_sum = nums[0]

    #     cur_sum_max[0]=nums[0]
    #     cur_sum_min[0]=nums[0]

    #     for i in range(1, n):
    #         cur_sum_min[i] = min(nums[i], cur_sum_min[i-1] * nums[i], cur_sum_max[i-1] * nums[i])
    #         cur_sum_max[i] = max(nums[i], cur_sum_min[i-1] * nums[i], cur_sum_max[i-1] * nums[i])

    #         best_sum = max(best_sum, cur_sum_min[i], cur_sum_max[i])
    #     return best_sum
    
    ```
