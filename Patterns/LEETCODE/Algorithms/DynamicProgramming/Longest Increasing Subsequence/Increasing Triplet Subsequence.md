### [Increasing Triplet Subsequence](https://leetcode.com/problems/increasing-triplet-subsequence/) <br>

Given an integer array `nums`, return `true` if there exists a triple of indices `(i, j, k)` such that `i < j < k` and `nums[i] < nums[j] < nums[k]`. If no such indices exists, return `false`.

#### Example 1:

```
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.

```

#### Example 2:

```
Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.

```

#### Example 3:

```
Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

```
# Solutions

### Python
```
class Solution:
#     def increasingTriplet(self, nums: List[int]) -> bool:
#         '''
#         LIS
#         '''
#         if len(nums)<3: return False
        
#         stack=[]
#         for num in nums:
#             i=0
#             n=len(stack)
#             while i<n:
#                 if num<=stack[i]:
#                     break
#                 i += 1
            
#             if i==n:
#                 stack.append(num)
#             else:
#                 stack[i]=num
                
#             if len(stack) == 3:
#                 return True
            
#         return False
    
    
            
    def increasingTriplet(self, nums: List[int]) -> bool:
        '''
        This LIS special case
        '''
        first_num = sys.maxsize
        second_num = sys.maxsize
        
        for num in nums:
            if num <= first_num:
                first_num = num
            elif num <= second_num:
                second_num = num
            else:
                return True
            
        return False            

```
