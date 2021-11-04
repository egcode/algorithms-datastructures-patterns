### [Longest Consecutive Sequence](https_problem_link) <br>

Given an unsorted array of integers `nums`, return *the length of the longest consecutive elements sequence*.

You must write an algorithm that runs in `O(n)` time.

#### Example 1:

```
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

```

#### Example 2:

```
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

```

# Solutions

### Python
```
class Solution:
#     def longestConsecutive(self, nums: List[int]) -> int:
#         '''
#         - Convert array to set
#         - Check each num if it's start of a sequence:
#             if yes, increase num +1 and check if this new num is in the set, if it is lenght+1 and store in result.
#             if no, continue
#         '''
        
#         s=set(nums)
#         res=0
#         n=len(nums)
        
#         for i in range(n):
#             if nums[i]-1 not in s: # check if it's start of a sequence
#                 # check length of a sequence
#                 tmp=nums[i]
#                 l=0
#                 while tmp in s:
#                     l += 1
#                     res=max(res, l)
#                     tmp += 1
                
#         return res
    
    
    def longestConsecutive(self, nums: List[int]) -> int:
        '''
        Explanation:
            https://www.youtube.com/watch?v=P6RZZMu_maU&ab_channel=NeetCode
            
            
        - Convert array to set
        - Check each num if it's start of a sequence:
            if yes, increase num +1 and check if this new num is in the set, if it is lenght+1 and store in result.
            if no, continue
        '''
        
        num_set=set(nums)
        res=0
        
        for num in nums:
            if num-1 not in num_set: # check if it's start of a sequence
                # check length of a sequence
                tmp=num
                length=0
                while num+length in num_set:
                    length += 1
                res=max(res, length)
                
        return res    
```
