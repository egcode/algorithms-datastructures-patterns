### [Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii/) <br>

Given an integer array `nums`, reorder it such that `nums[0] < nums[1] > nums[2] < nums[3]...`.

You may assume the input array always has a valid answer.



#### Example 1:

```
Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.

```

#### Example 2:

```
Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]

```

# Solutions

### Python
```
class Solution:
#     def wiggleSort(self, nums: List[int]) -> None:
#         """
#         Do not return anything, modify nums in-place instead.
#         """
        
#         arr = sorted(nums)
#         for i in range(1, len(nums), 2): 
#             nums[i] = arr.pop() 
            
#         for i in range(0, len(nums), 2): 
#             nums[i] = arr.pop() 
            
            
    def wiggleSort(self, nums: List[int]) -> None:
        
        '''
        Example nums = [1,2,...,7]      Example nums = [1,2,...,8] 

        Small half:  4 . 3 . 2 . 1      Small half:  4 . 3 . 2 . 1 .
        Large half:  . 7 . 6 . 5 .      Large half:  . 8 . 7 . 6 . 5
        --------------------------      --------------------------
        Together:    4 7 3 6 2 5 1      Together:    4 8 3 7 2 6 1 5

        
        '''
        
        nums.sort()
        half = len(nums[::2])
        nums[::2], nums[1::2] = nums[:half][::-1], nums[half:][::-1]

```
