### [Sort Colors](https://leetcode.com/problems/sort-colors/) <br>

Given an array `nums` with `n` objects colored red, white, or blue, sort them [in-place](https://en.wikipedia.org/wiki/In-place_algorithm) so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.


#### Example 1:

```
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

```

#### Example 2:

```
Input: nums = [2,0,1]
Output: [0,1,2]

```


#### Example 3:

```
Input: nums = [0]
Output: [0]

```

#### Example 4:

```
Input: nums = [1]
Output: [1]

```


# Solutions

### Python
```
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Dutch National Flag problem.
        """
        n=len(nums)
        lo=0
        hi=n-1
        
        i=0
        while i<=hi:
            if nums[i]==0:
                nums[i], nums[lo] = nums[lo], nums[i]
                lo += 1
                i += 1
            elif nums[i]==2:
                nums[i], nums[hi] = nums[hi], nums[i]
                hi -= 1
            else:
                i += 1

```
