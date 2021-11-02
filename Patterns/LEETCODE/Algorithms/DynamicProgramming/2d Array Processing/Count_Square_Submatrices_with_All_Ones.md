### [Count Square Submatrices with All Ones](https://leetcode.com/problems/count-square-submatrices-with-all-ones/) <br>

Given a   `m * n`   matrix of ones and zeros, return how many square submatrices have all ones.



#### Example 1:

```
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

```

#### Example 2:

```
Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.

```



# Solutions

### Python
```
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        '''
        Same problem as 221. Maximal Square.
        Instead we sum all values in dp
        
        '''
        res=0
        if not matrix: return res
        h=len(matrix)
        w=len(matrix[0])
        
        dp=[[0]*(w+1) for i in range(h+1)]
        
        for i in range(1, h+1):
            for j in range(1, w+1):
                if matrix[i-1][j-1]==1:
                    dp[i][j]=1+min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
        
        for row in dp:
            res += sum(row)
        return res
        
        
        
'''

[[0,1,1,1],[1,1,1,1],[0,1,1,1]]
[
[0,1,1,1],
[1,1,1,1],
[0,1,1,1]
]
[
[0,0,0,0,0], 
[0,0,1,1,1], 
[0,1,1,2,2], 
[0,0,1,2,3]
]



[[1,0,1],[1,1,0],[1,1,0]]
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]

'''   
```
