### [Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence/) <br>

Given an integer array `nums`, return the *number of longest increasing subsequences*.

**Notice** that the sequence has to be **strictly** increasing.

#### Example 1:

```
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

```

#### Example 2:

```
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

```

# Solutions

### Python
```
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        if not nums: return 0
        n=len(nums)
        dp=[1]*n
        count=[1]*n        
        
        for i in range(n):
            for j in range(i):
                if nums[i]>nums[j]:
                    if dp[j]+1 > dp[i]:
                        dp[i]=dp[j]+1
                        count[i] = count[j]
                    elif dp[j]+1 == dp[i]:
                        count[i] += count[j]

        longest=max(dp)
        longest_arr = [count[i] for i in range(n) if dp[i]==longest]
        res=sum(longest_arr)
        
        return res
```
