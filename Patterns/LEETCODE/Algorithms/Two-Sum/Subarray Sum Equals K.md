### [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) <br>

Given an array of integers `nums` and an integer `k`, return *the total number of continuous subarrays whose sum equals to* `k`.

 



#### Example 1:

```
Input: nums = [1,1,1], k = 2
Output: 2

```

#### Example 2:

```
Input: nums = [1,2,3], k = 3
Output: 2

```

# Solutions

### Python
```
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        '''
        if accum[i]-accum[j]==k 
        the sum of elements lying between indices i and j is k.
        
        array: [1,1,1] k=2
        dic : dic{0: 1, 1:1, 2:1, 3:1}
        accum     : [1,                 2,             3]
        accum loop:  1-k=-1 not in dic, 2-k=0 in dic,  3-k=1 in dic
        
        '''
        
        accum=0
        dic={0: 1} # Example [1,2] k=3  accum=1+2=3, if we don't assign this, we skip first accum-k condition
        res=0
        
        for i,num in enumerate(nums):
            accum += num
            
            if accum-k in dic.keys():
                res += dic[accum-k]
                
            dic[accum]=1+dic.get(accum, 0)
            
        return res

```
