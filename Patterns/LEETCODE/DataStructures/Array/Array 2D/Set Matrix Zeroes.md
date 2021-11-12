### [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) <br>

Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`'s, and return the matrix.

You must do it in place.



#### Example 1:
<img src="../../../../../images/73-mat1.jpg">

```
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

```

#### Example 2:
<img src="../../../../../images/73-mat2.jpg">

```
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

```

# Solutions

### Python
```
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        '''
        DFS 
        '''
        if not matrix: return matrix
        zeros=set()
        h=len(matrix)
        w=len(matrix[0])
        for i in range(h):
            for j in range(w):
                if matrix[i][j] == 0:
                    zeros.add((i,j))
            
        
        def dfs(row,col,d):
            r=row+d[0]
            c=col+d[1]
            if 0<=r<h and 0<=c<w:
                matrix[r][c]=0
                dfs(r,c,d)
            
        for row,col in zeros:
            dfs(row, col, (1,0))
            dfs(row, col, (-1,0))
            dfs(row, col, (0,-1))
            dfs(row, col, (0,1))

#     def setZeroes(self, matrix: List[List[int]]) -> None:
#         is_col = False
#         h = len(matrix)
#         w = len(matrix[0])
        
#         for i in range(h):
#             # Since first cell for both first row and first column is the same i.e. matrix[0][0]
#             # We can use an additional variable for either the first row/column.
#             # For this solution we are using an additional variable for the first column
#             # and using matrix[0][0] for the first row.
#             if matrix[i][0] == 0:
#                 is_col = True
#             for j in range(1, w):
#                 # If an element is zero, we set the first element of the corresponding row and column to 0
#                 if matrix[i][j]  == 0:
#                     matrix[0][j] = 0
#                     matrix[i][0] = 0

                    
#         # Iterate over the array once again and using the first row and first column, update the elements.
#         for i in range(1, h):
#             for j in range(1, w):
#                 if not matrix[i][0] or not matrix[0][j]:
#                     matrix[i][j] = 0

#         # See if the first row needs to be set to zero as well
#         if matrix[0][0] == 0:
#             for j in range(C):
#                 matrix[0][j] = 0

#         # See if the first column needs to be set to zero as well        
#         if is_col:
#             for i in range(h):
#                 matrix[i][0] = 0
```
