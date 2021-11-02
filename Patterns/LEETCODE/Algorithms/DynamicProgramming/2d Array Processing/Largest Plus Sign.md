### [Largest Plus Sign](https://leetcode.com/problems/largest-plus-sign/) <br>

You are given an integer `n`. You have an `n x n` binary grid `grid` with all values initially `1`'s except for some indices given in the array `mines`. The `i-th`  element of the array mines is defined as `mines[i] = [xi, yi]` where `grid[xi][yi] == 0`.

Return the order of the largest axis-aligned plus sign of 1's contained in `grid`. If there is none, return `0`.

An **axis-aligned** plus sign of `1`'s of order `k` has some center `grid[r][c] == 1` along with four arms of length `k - 1` going up, down, left, and right, and made of `1`'s. Note that there could be `0`'s or `1`'s beyond the arms of the plus sign, only the relevant area of the plus sign is checked for `1`'s.



#### Example 1:
<img src="../../../../../images/plus1-grid.jpg">

```
Input: n = 5, mines = [[4,2]]
Output: 2
Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.

```


#### Example 2:
<img src="../../../../../images/plus2-grid.jpg">

```
Input: n = 1, mines = [[0,0]]
Output: 0
Explanation: There is no plus sign, so return 0.
```


# Solutions

### Python
```
class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        '''
        Example how we count:
        [1,1,1,0,1,1] - original
        
        [0,1,2,0,1,2] - from left
        [3,2,1,0,2,1] - from right
        [0,1,1,0,1,1] - result, take minimum from two.
        
        Here we should do the same for horizontal and vertical
        '''
        res=0
        dp=[[float('inf') for _ in range(n)] for _ in range(n)]
        mins={(mine[0],mine[1]) for mine in mines}
        
        for r in range(n):
            count=0
            for c in range(n):
                count = count+1 if (r,c) not in mins else 0
                dp[r][c]=count
            
            count=0
            for c in range(n)[::-1]:
                count = count+1 if (r,c) not in mins else 0
                dp[r][c]=min(dp[r][c], count)
                
        for c in range(n):
            count=0
            for r in range(n):
                count = count+1 if (r,c) not in mins else 0
                dp[r][c]=min(dp[r][c], count)
            count=0    
            for r in range(n)[::-1]:
                count = count+1 if (r,c) not in mins else 0
                dp[r][c]=min(dp[r][c], count)
                res=max(res, dp[r][c])
                
        # for row in dp:
        #     print(row)
        
        return res

```
