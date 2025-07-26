### [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) <br>

There is an integer array `nums` sorted in ascending order (with **distinct** values).

Prior to being passed to your function, `nums` is **possibly rotated** at an unknown pivot index `k` (`1 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` **after** the possible rotation and an integer `target`, return *the index of* `target` *if it is in* `nums`, *or* `-1` *if it is not in* `nums`.

You must write an algorithm with `O(log n)` runtime complexity.


#### Example 1:

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

```

#### Example 2:

```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

```


#### Example 3:

```
Input: nums = [1], target = 0
Output: -1

```


# Solutions

### Python
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        '''
    Ex.  nums = [5, 6, 7, 0, 1, 2, 4]
        target = 1
    Initial state:
        left = 0, right = 6, mid = 3
        nums[mid] = 0, nums[left] = 5, nums[right] = 4

    Here:
        nums[left] <= nums[mid] → 5 <= 0 → ❌
        So the left side is not sorted, meaning the right side must be sorted.

    Now we check:
        if nums[mid] < target <= nums[right]:  # 0 < 1 <= 4 → ✅
        Since the target is in the sorted half, we search that half.
        '''


        left = 0
        right = len(nums)-1

        while left <= right:
            mid = (left + right)//2
            
            if nums[mid]==target:
                return mid
            elif nums[left]<=nums[mid]:
                #left is sorted 
                if nums[left]<=target<nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                # right is sorted
                if nums[mid]<target<=nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return -1

```
