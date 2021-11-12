### [3Sum](https://leetcode.com/problems/3sum/) <br>

Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.



#### Example 1:

```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

```

#### Example 2:

```
Input: nums = []
Output: []

```

#### Example 3:

```
Input: nums = [0]
Output: []

```
# Solutions

### Python
```
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res=[]
        
        for i in range(0,len(nums)):
            
            if i>0 and nums[i]==nums[i-1]:
                continue
                
            target=-nums[i]
            fast=i+1
            end=len(nums)-1
            
            while fast<end:
                if nums[fast]+nums[end]==target:
                    res.append([nums[fast],nums[i],nums[end]])
                    fast += 1
                    while fast<end and nums[fast]==nums[fast-1]:
                            fast += 1
                elif nums[fast]+nums[end]<target:
                    fast += 1 
                else:
                    end -= 1
        return res

```
