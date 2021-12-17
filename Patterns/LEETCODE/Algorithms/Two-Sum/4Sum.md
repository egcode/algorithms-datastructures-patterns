### [4Sum](https://leetcode.com/problems/4sum/) <br>

Given an array `nums` of `n` integers, return *an array of all the unique quadruplets* `[nums[a], nums[b], nums[c], nums[d]]` such that:

 - `0 <= a, b, c, d < n`
 - `a`, `b`, `c`, and `d` are **distinct**.
 - `nums[a] + nums[b] + nums[c] + nums[d] == target`


You may return the answer in **any order**.

 

#### Example 1:

```
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

```

#### Example 2:

```
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

```



# Solutions

### Python
```
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        def kSum(nums: List[int], target: int, k: int) -> List[List[int]]:
            res = []
            
            if len(nums)==0 or (nums[0]*k)>target or target>(nums[-1]*k):
                return res
            
            if k == 2:
                return twoSum(nums, target)
            
            for i in range(len(nums)):
                if i>0 and nums[i-1] == nums[i]:
                    continue
                ks=kSum(nums[i+1:], target-nums[i], k-1)
                # print("\nks:"+str(ks))
                for set in ks:
                    # print("res before:"+str(res))
                    res.append([nums[i]]+set)
                    # print("res after:"+str(res))
            return res

        
        def twoSum(nums: List[int], target: int) -> List[List[int]]:
            res = []
            s=0
            e=len(nums)-1
            
            while s<e:
                sum=nums[s]+nums[e]
                if sum<target or (s>0 and nums[s]==nums[s-1]):
                    s += 1
                elif sum>target or (e<len(nums)-1 and nums[e]==nums[e+1]):
                    e -= 1
                else:
                    res.append([nums[s], nums[e]])
                    s += 1
                    e -= 1
            return res

        nums.sort()
        return kSum(nums, target, 4)        
```
