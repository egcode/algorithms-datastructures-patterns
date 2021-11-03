### [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) <br>

Given a **non-empty** array `nums` containing **only positive integers**, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.


#### Example 1:

```
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

```

#### Example 2:

```
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

```

# Solutions

### Python
```
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total=sum(nums)
        if total%2 != 0:
            return False
        
        half=total//2
        memo={}
        
        def dfs(path, nms):
            
            if path==half and len(nms)>0:
                memo[path]=True
                return True
            
            if path in memo.keys():
                return memo[path]            
            
            for i in range(len(nms)):
                new_nums=nms[:i]+nms[i+1:]
                if dfs(path+nms[i], new_nums)==True:
                    memo[path]=True
                    return True
                
            memo[path]=False    
            return False
        
        return dfs(0, nums)

```
