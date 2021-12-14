### [Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/) <br>

Given a **sorted** integer array `arr`, two integers `k` and `x`, return the `k` closest integers to `x` in the array. The result should also be sorted in ascending order.

An integer `a` is closer to `x` than an integer `b` if:

 - `|a - x| < |b - x|`, or
 - `|a - x| == |b - x|` and `a < b`
 



#### Example 1:

```
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

```

#### Example 2:

```
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

```

# Solutions

### Python
```
class Solution:
#     def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
#         dists=[]
#         for el in arr:
#             d=el-x
#             dists.append((abs(d), el))
            
#         dists.sort(key=lambda tup:tup[0])
#         res=[d[1] for d in dists[:k]]
#         res.sort()
#         return res
        
        
    
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        lo=0
        hi=len(arr)-1
        
        while (hi-lo+1)>k:
            # compare distances
            if abs(arr[lo]-x) > abs(arr[hi]-x):  # if distance from lower to x is bigger
                lo += 1
            else:
                hi -= 1
            
        return arr[lo:hi+1]

```
