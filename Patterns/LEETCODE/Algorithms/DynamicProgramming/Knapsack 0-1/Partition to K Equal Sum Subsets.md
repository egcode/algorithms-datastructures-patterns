### [Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/) <br>

Given an integer array `nums` and an integer `k`, return `true` if it is possible to divide this array into `k` non-empty subsets whose sums are all equal.



#### Example 1:

```
Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

```

#### Example 2:

```
Input: nums = [1,2,3,4], k = 3
Output: false

```



# Solutions

### Python
```
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        '''
        Memoization with bitmasking
        '''
        n=len(nums)
        if n<k: return False            
        total=sum(nums)
        target=total//k
        if total/k != target: return False        
        maskFull=(1<< n)-1
                
        @lru_cache(None)
        def dp(path,k,m):
            if k==0:
                return True
            if m==maskFull:
                return False
            if path>target:
                return False
            
            for i in range(n):
                if m & (1<<i): continue
                if path+nums[i]==target:
                    if dp(0, k-1, m | (1<<i)):
                        return True
                if dp(path+nums[i], k, m | (1<<i)):
                    return True
                
            return False
            
        return dp(0,k,0)
```
