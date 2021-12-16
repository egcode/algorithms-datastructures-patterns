### [Majority Element](https://leetcode.com/problems/majority-element/) <br>

Given an array `nums` of size `n`, return *the majority element*.

The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

 



#### Example 1:

```
Input: nums = [3,2,3]
Output: 3

```

#### Example 2:

```
Input: nums = [2,2,1,1,1,2,2]
Output: 2

```


# Solutions

### Python
```
class Solution:
#     def majorityElement(self, nums: List[int]) -> int:
#         dic={}
#         res=[-1,-1]
#         for num in nums:
#             dic[num]=1+dic.get(num, 0)
#             if dic[num]>res[0]:
#                 res=[dic[num], num]
        
#         return res[1]

    def majorityElement(self, nums: List[int]) -> int:
        '''
        Boyer-Moore Voding Algorithm
        '''
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
                
            add=-1
            if num==candidate:
                add=1
            count += add

        return candidate        

```
