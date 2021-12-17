### [4Sum II](https://leetcode.com/problems/4sum-ii/) <br>

Given four integer arrays `nums1`, `nums2`, `nums3`, and `nums4` all of length `n`, return the number of tuples `(i, j, k, l)` such that:

 - `0 <= i, j, k, l < n`
 - `nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0`
 


#### Example 1:

```
Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

```

#### Example 2:

```
Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
Output: 1

```



# Solutions

### Python
```
class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        res=0
        dic={}
        
        for n1 in nums1:
            for n2 in nums2:
                dic[(n1+n2)]=1+dic.get(n1+n2, 0)
                
        for n3 in nums3:
            for n4 in nums4:
                res += dic.get(-(n3+n4), 0)
        
        return res
```
