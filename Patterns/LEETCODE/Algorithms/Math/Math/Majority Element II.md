### [Majority Element II](https://leetcode.com/problems/majority-element-ii/) <br>

Given an integer array of size `n`, find all elements that appear more than `⌊ n/3 ⌋` times.



#### Example 1:

```
Input: nums = [3,2,3]
Output: [3]

```

#### Example 2:

```
Input: nums = [1]
Output: [1]

```

#### Example 3:

```
Input: nums = [1,2]
Output: [1,2]

```


# Solutions

### Python
```
class Solution:
#     def majorityElement(self, nums: List[int]) -> List[int]:
#         n=len(nums)
#         times=n//3        
#         h={}
#         ans=set()
        
#         for i in range(len(nums)):
#             d=nums[i]
#             h[d]=1+h.get(d, 0)
#             if h[d]>times:
#                 ans.add(d)
        
#         return ans
        
        
    def majorityElement(self, nums: List[int]) -> List[int]:
        if not nums: return []
        
        cand1, cand2 = None, None
        count1, count2 = 0, 0
        
        # Pass1
        for n in nums:
            if cand1==n:
                count1 += 1
            elif cand2==n:
                count2 += 1
            elif count1==0:
                cand1=n
                count1 = 1
            elif count2==0:
                cand2=n
                count2 = 1
            else:
                count1 -= 1
                count2 -= 1
        
        # Pass2
        ans = []
        for cand in [cand1, cand2]:
            if nums.count(cand) > len(nums)//3:
                ans.append(cand)
        return ans

```
