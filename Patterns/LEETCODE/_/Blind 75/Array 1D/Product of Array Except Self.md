### [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) <br>

Given an integer array `nums`, return an array `answer` such that `answer[i]` *is equal to the product of all the elements of* `nums` except `nums[i]`.

The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.


#### Example 1:

```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

```

#### Example 2:

```
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

```

# Solutions

### Python
```
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n=len(nums)
        
        prod_right=[0]*n
        prod_right[0]=1
        for i in range(1, n):
            prod_right[i]=prod_right[i-1]*nums[i-1]
        
        prod_left=[0]*n
        prod_left[n-1]=1
        for i in reversed(range(n-1)):
            prod_left[i]=prod_left[i+1]*nums[i+1]
            
        res=[]
        for i in range(n):
            res.append(prod_left[i]*prod_right[i])
        
        return res
```
