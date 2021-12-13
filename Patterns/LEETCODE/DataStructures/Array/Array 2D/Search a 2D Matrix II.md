### [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/) <br>

Write an efficient algorithm that searches for a `target` value in an `m x n` integer matrix. The `matrix` has the following properties:

 - Integers in each row are sorted in ascending from left to right.
 - Integers in each column are sorted in ascending from top to bottom.
 


#### Example 1:
<img src="../../../../../images/240searchgrid2.jpg">

```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

```

#### Example 2:
<img src="../../../../../images/240searchgrid.jpg">

```
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false

```

# Solutions

### Python
```
class Solution:
    def searchMatrix(self, matrix, target):
        '''
        Starting from bottom-left corner, 
        since this row of largest values.
        
        if current is smaller than target we increase column
        if current is bigger than target we decrease row
        '''
        
        h=len(matrix)
        w=len(matrix[0])
        
        r=h-1
        c=0
        
        while c<w and r>=0:
            if matrix[r][c]==target:
                return True
            elif matrix[r][c]>target:
                r -= 1
            else:
                c += 1
        
        return False

```
