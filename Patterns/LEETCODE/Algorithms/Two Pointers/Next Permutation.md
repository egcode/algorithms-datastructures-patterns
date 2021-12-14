### [Next Permutation](https://leetcode.com/problems/next-permutation/) <br>

Implement **next permutation**, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be [in place](http://en.wikipedia.org/wiki/In-place_algorithm) and use only constant extra memory.

 



#### Example 1:

```
Input: nums = [1,2,3]
Output: [1,3,2]

```

#### Example 2:

```
Input: nums = [3,2,1]
Output: [1,2,3]

```

#### Example 3:

```
Input: nums = [1,1,5]
Output: [1,5,1]

```

#### Example 4:

```
Input: nums = [1]
Output: [1]

```


# Solutions

<img src="../../../../../images/31_Next_Permutation.gif">


### Python
```
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        decreasing_found=False
        n=len(nums)
        i=n-1
        while i > 0 and decreasing_found == False:
            cur=nums[i]
            prv=nums[i-1]
            
            if prv < cur:
                decreasing_found=True
                j=n-1
                while j>i-1:
                    if nums[j]>prv:
                        nums[j], nums[i-1] = nums[i-1], nums[j]
                        break
                    j -= 1
                    
                    
                left=i
                right=n-1
                while left<right:
                    nums[left], nums[right] = nums[right], nums[left]
                    left += 1
                    right -= 1
                    
            
            i -= 1
        
        if decreasing_found==False:
            nums.sort()

```
