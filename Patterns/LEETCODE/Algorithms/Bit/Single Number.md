### [Single Number](https://leetcode.com/problems/single-number/) <br>

Given a **non-empty** array of integers `nums`, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.



#### Example 1:

```
Input: nums = [2,2,1]
Output: 1

```

#### Example 2:

```
Input: nums = [4,1,2,1,2]
Output: 4

```

#### Example 3:

```
Input: nums = [1]
Output: 1

```

# Solutions

### Python
```
class Solution:
#     def singleNumber(self, nums: List[int]) -> int:
#         h={}
        
#         for i in range(len(nums)):
#             if nums[i] in h:
#                 del h[nums[i]]
#             else:
#                 h[nums[i]]=True
        
#         key, value = h.popitem()
#         return key

    def singleNumber(self, nums: List[int]) -> int:

        mask=0
        
        for n in nums:
            mask=mask ^ n
            
        return mask
```
