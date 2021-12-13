### [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/) <br>

Given an integer array `nums` sorted in **non-decreasing** order, return *an array of ***the squares of each number*** sorted in non-decreasing order*.



#### Example 1:

```
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

```

#### Example 2:

```
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

```

# Solutions

### Python
```
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        n=len(A)
        res=[0]*n
        
        lo=0
        hi=n-1
        
        for i in range(n)[::-1]:
            if abs(A[lo])>abs(A[hi]):
                res[i]=A[lo]**2
                lo += 1
            else:
                res[i]=A[hi]**2
                hi -= 1
            
        return res

```
