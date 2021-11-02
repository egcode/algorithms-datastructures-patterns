### [Matrix Block Sum](https://leetcode.com/problems/matrix-block-sum/) <br>

Given a `m x n` matrix `mat` and an integer `k`, return a matrix `answer` where each `answer[i][j]` is the sum of all elements `mat[r][c]` for:

`i - k <= r <= i + k`,
`j - k <= c <= j + k`, and
`(r, c)` is a valid position in the matrix.


#### Example 1:

```
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

```


#### Example 2:

```
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
```


# Solutions

### Python
```
class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        '''
        Summed Area Table
        
        https://computersciencesource.wordpress.com/2010/09/03/computer-vision-the-integral-image/
        
        RangeSum:
        +-----+-+-------+     +--------+-----+     +-----+---------+     +-----+--------+
        |     | |       |     |        |     |     |     |         |     |     |        |
        |     | |       |     |        |     |     |     |         |     |     |        |
        +-----+-+       |     +--------+     |     |     |         |     +-----+        |
        |     | |       |  =  |              |  +  |     |         |  -  |              | + mat[i][j]
        +-----+-+       |     |              |     +-----+         |     |              |
        |               |     |              |     |               |     |              |
        |               |     |              |     |               |     |              |
        +---------------+     +--------------+     +---------------+     +--------------+
            dp[r][c]       =     dp[r-1][c]     +     dp[r][c-1]      -     dp[r-1][c-1]   + mat[r-1][c-1]
        
        
        
        Find  specific block's sum   with range sum    
        +---------------+   +--------------+   +---------------+   +--------------+   +--------------+
        |               |   |         |    |   |   |           |   |         |    |   |   |          |
        |   (r1,c1)     |   |         |    |   |   |           |   |         |    |   |   |          |
        |   +------+    |   |         |    |   |   |           |   +---------+    |   +---+          |
        |   |      |    | = |         |    | - |   |           | - |      (r1,c2) | + |   (r1,c1)    |
        |   |      |    |   |         |    |   |   |           |   |              |   |              |
        |   +------+    |   +---------+    |   +---+           |   |              |   |              |
        |        (r2,c2)|   |       (r2,c2)|   |   (r2,c1)     |   |              |   |              |
        +---------------+   +--------------+   +---------------+   +--------------+   +--------------+
        
        '''
        h=len(mat)
        w=len(mat[0])
        
        # Presum
        dp=[[0]*(w+1) for _ in range(h+1)]
        
        for r in range(1, h+1):
            for c in range(1, w+1):
                dp[r][c]=mat[r-1][c-1]+dp[r-1][c]+dp[r][c-1]-dp[r-1][c-1]
        
        res=[[0]*w for _ in range(h)]
        for r in range(1, h+1):
            for c in range(1, w+1):
                r1=max(0, r-k-1)
                c1=max(0, c-k-1)
                r2=min(h, r+k)
                c2=min(w, c+k)
                right_bot=dp[r2][c2]
                left_bot=dp[r2][c1]
                top_right=dp[r1][c2]
                top_left=dp[r1][c1]                
                res[r-1][c-1]= right_bot - left_bot - top_right + top_left
        
        # print(dp)
        return res    
    
```
