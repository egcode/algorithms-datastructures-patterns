### [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) <br>

Given a binary array `nums` and an integer `k`, return the *maximum number of consecutive `1`'s in the array if you can flip at most `k` `0`'s*.



#### Example 1:

```
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Best result: [1,1,1,0,0,1,1,1,1,1,1]

```

#### Example 2:

```
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Best result: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]

```



# Solutions

### Python
```
class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        zeros=0
        left=0 # Left window border
        res=0
        
        for i,num in enumerate(nums):
            if num==0:
                zeros += 1
                
            # if window is too big, shink it 
            while zeros>k:
                if nums[left]==0:
                    zeros -= 1
                left += 1
                
            res=max(res, i-left+1)
            
            
        return res        

```
