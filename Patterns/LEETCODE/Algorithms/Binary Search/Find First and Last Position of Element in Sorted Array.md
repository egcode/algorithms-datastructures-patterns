### [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) <br>

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.

 


#### Example 1:

```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

```

#### Example 2:

```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

```

#### Example 3:

```
Input: nums = [], target = 0
Output: [-1,-1]

```



# Solutions

### Python
```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        
        n=len(nums)
        
        lo=0
        hi=n-1
        max_left=-1
        while lo<=hi:
            mid=lo+(hi-lo)//2
            if nums[mid]==target:
                max_left=mid
                hi=mid-1
            elif nums[mid]<target:
                lo=mid+1
            else:
                hi=mid-1
        lo=0
        hi=n-1
        max_right=-1
        while lo<=hi:
            mid=lo+(hi-lo)//2
            if nums[mid]==target:
                max_right=mid
                lo=mid+1
            elif nums[mid]<target:
                lo=mid+1
            else:
                hi=mid-1
        return [max_left, max_right]

```
