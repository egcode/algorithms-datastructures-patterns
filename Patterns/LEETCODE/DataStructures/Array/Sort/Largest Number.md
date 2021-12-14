### [Largest Number](https://leetcode.com/problems/largest-number/) <br>

Given a list of non-negative integers `nums`, arrange them such that they form the largest number.

**Note:** The result may be very large, so you need to return a string instead of an integer.



#### Example 1:

```
Input: nums = [10,2]
Output: "210"

```

#### Example 2:

```
Input: nums = [3,30,34,5,9]
Output: "9534330"

```

#### Example 3:

```
Input: nums = [1]
Output: "1"

```

#### Example 4:

```
Input: nums = [10]
Output: "10"

```

# Solutions

### Python
```
class Solution:
#     # # bubble sort
#     def largestNumber(self, nums):
#         '''
#         If we have 3, 32 and 31, then we need to choose 3 as the first element. 
#         However if we have 3, 34 and 32, then we need to chose 34 as the first element.
#         '''
#         n=len(nums)
#         for i in range(n):
#             for j in range(1, n):
#                 s1=str(nums[j-1]) + str(nums[j])
#                 s2=str(nums[j]) + str(nums[j-1])
#                 ## COMPARE
#                 if s1 < s2:
#                     nums[j], nums[j-1] = nums[j-1], nums[j]
                
#         return str(int("".join(map(str, nums))))
    
    
    # quick sort, in-place
    def largestNumber(self, nums: List[int]) -> str:
        '''
        If we have 3, 32 and 31, then we need to choose 3 as the first element. 
        However if we have 3, 34 and 32, then we need to chose 34 as the first element.
        '''
        self.quickSort(nums, 0, len(nums)-1)
        return str(int("".join(map(str, nums)))) 

    def quickSort(self, nums, l, r):
        if l >= r:
            return 
        pos = self.partition(nums, l, r)
        self.quickSort(nums, l, pos-1)
        self.quickSort(nums, pos+1, r)

    def partition(self, nums, l, r):
        low = l
        while l < r:
            
            s1=str(nums[r]) + str(nums[l])
            s2=str(nums[l]) + str(nums[r])
            ## COMPARE
            if s1 < s2:
                nums[l], nums[low] = nums[low], nums[l]
                low += 1
            l += 1
        nums[low], nums[r] = nums[r], nums[low]
        return low

```
