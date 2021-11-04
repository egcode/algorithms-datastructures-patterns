### [Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/) <br>

Given a **circular integer array** `nums` of length `n`, return the maximum possible sum of a non-empty **subarray** of `nums`.

A **circular array** means the end of the array connects to the beginning of the array. Formally, the next element of `nums[i]` is `nums[(i + 1) % n]` and the previous element of `nums[i]` is `nums[(i - 1 + n) % n]`.

A **subarray** may only include each element of the fixed buffer `nums` at most once. Formally, for a subarray `nums[i], nums[i + 1], ..., nums[j]`, there does not exist `i <= k1`, `k2 <= j` with `k1 % n == k2 % n`.



#### Example 1:

```
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3

```

#### Example 2:

```
Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10

```

#### Example 3:

```
Input: nums = [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4

```
#### Example 4:

```
Input: nums = [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3

```
#### Example 5:

```
Input: nums = [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1

```
# Solutions

### Python
```
class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        '''
        Kadane's Algorithm
        
        https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/1348545/Python-3-solutions-Clean-and-Concise-O(1)-Space        
        
        '''
        n=len(nums)
                    
        def kadane(arr):
            current=arr[0]
            best_sum=arr[0]
            for i in range(1, len(arr)):
                current=max(nums[i], current+nums[i])
                best_sum=max(best_sum, current)
            return best_sum
        
        def min_sub_array_sum(arr):
            if len(arr) <= 2: return 0 # left, right element are exclusive! 
            current=0
            best_sum=arr[1]
            for i in range(1, len(arr)-1):
                current += nums[i]
                best_sum=min(best_sum, current)
                if current > 0:
                    current =0
            return best_sum
                
            
        case1 = kadane(nums)
        case2 = sum(nums)-min_sub_array_sum(nums) #The maximum result equals to the total sum minus the minimum subarray sum
        
        return max(case1, case2)        

```
