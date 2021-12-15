### [Kth Missing Positive Number](https://leetcode.com/problems/kth-missing-positive-number/) <br>

Given an array `arr` of positive integers sorted in a **strictly increasing order**, and an integer `k`.

*Find the* <img src="https://render.githubusercontent.com/render/math?math=k^{th}"> *positive integer that is missing from this array*.







#### Example 1:

```
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

```

#### Example 2:

```
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

```

# Solutions

### Python
```
class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        missing=arr[0]-1
        if missing >= k:
            return k
        
        for i in range(len(arr)-1):
            cur=arr[i]
            nxt=arr[i+1]
            
            step=nxt-cur-1
            missing += step
            
            if missing >= k:
                return cur+(k-(missing-step))
                
        return arr[-1]+(k-missing)
            
    
# [   2,3,4,       7,           11]                    
# [1, 2,3,4,  5,6  7,  8,9,10,  11  ]                

```
