### [Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/) <br>

An integer array is called arithmetic if it consists of **at least three elements** and if the difference between any two consecutive elements is the same.

For example, `[1,3,5,7,9]`, `[7,7,7,7]`, and `[3,-1,-5,-9]` are arithmetic sequences.
Given an integer array nums, return the number of arithmetic **subarrays** of `nums`.

A **subarray** is a contiguous subsequence of the array.

 

#### Example 1:

```
Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

```


#### Example 2:

```
Input: nums = [1]
Output: 0

```


# Solutions

### Python
```
class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        """
        Every digit that gets added to the sequence adds 'n' more possibilities to the output 
        where 'n' is the difference between number of digits in array and 3.

        e.g For [1,2,3] we have [1,2,3]
        For [1,2,3,4] we have [1,2,3], [1,2,3,4], [2,3,4] ie it adds 2 new sub-arrays ending with 4.
        For [1,2,3,4,5], we have [1,2,3,4,5], [2,3,4,5], [3,4,5] ie it adds 3 new sub-arrays 
        ending with 5 to whatever we could make with 4 elements ie [1,2,3,4]
        Likewise for 6 elements, we will have 4 new sub-arrays that'd be added, so on and forth.

        TLDR:

        So the logic is to add 1 to every single element that gets added in the sequence.

        """
        res=0
        n=len(nums)
        curWindowLen=0
        for i in range(2, n):
            if nums[i]-nums[i-1]==nums[i-1]-nums[i-2]:
                curWindowLen += 1
                res += curWindowLen
            else:
                curWindowLen = 0
            
        return res
    
    
#     def numberOfArithmeticSlices(self, nums: List[int]) -> int:
#         '''
#         Dynamic Programming
#         Tabulation
#         '''
#         n=len(nums)
#         dp=[0]*n
#         summ=0
#         for i in range(2, n):
#             if nums[i]-nums[i-1]==nums[i-1]-nums[i-2]:
#                 dp[i]=1+dp[i-1]
#                 summ += dp[i]
                
                
#         return summ

```
