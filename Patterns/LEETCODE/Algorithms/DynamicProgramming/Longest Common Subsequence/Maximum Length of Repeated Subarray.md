### [Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/) <br>

Given two integer arrays `nums1` and `nums2`, return *the maximum length of a subarray that appears in ***both*** arrays*.


#### Example 1:

```
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].

```

#### Example 2:

```
Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5

```



# Solutions

### Python
```
class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        '''
        Tabulation:
          Example: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
          
          Start with:
                [0, 0, 0, 0, 0, 0]
                [0, 0, 0, 0, 0, 0]
                [0, 0, 0, 0, 0, 0]
                [0, 0, 0, 0, 0, 0]
                [0, 0, 0, 0, 0, 0]
                [0, 0, 0, 0, 0, 0]

          End with: 
                [0, 0, 1, 0, 0, 0]
                [0, 1, 0, 0, 0, 0]
                [3, 0, 0, 0, 0, 0]
                [0, 2, 0, 0, 0, 0]
                [0, 0, 1, 0, 0, 0]
                [0, 0, 0, 0, 0, 0]
          
        '''
        
        h=len(nums1)
        w=len(nums2)
        
        dp=[[0]*(w+1) for _ in range(h+1)]
                
        res=0
        for r in range(h)[::-1]:
            for c in range(w)[::-1]:
                if nums1[r]==nums2[c]:
                    dp[r][c]=1+dp[r+1][c+1]
                    res=max(res, dp[r][c])
            
        return res

```
