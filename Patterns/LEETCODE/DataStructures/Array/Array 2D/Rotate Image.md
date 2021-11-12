### [Rotate Image](https://leetcode.com/problems/rotate-image/) <br>

You are given an `n x n` 2D `matrix` representing an image, rotate the image by **90** degrees (clockwise).

You have to rotate the image **in-place**, which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.



#### Example 1:
<img src="../../../../../images/48mat1.jpg">

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

```

#### Example 2:
<img src="../../../../../images/48mat2.jpg">

```
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

```

#### Example 3:

```
Input: matrix = [[1]]
Output: [[1]]

```

#### Example 4:

```
Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]

```


# Solutions

### Python
```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        # Transpose matrix:
        for i in range(len(matrix)):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        # Reverse rows:
        for row in matrix:
            i=0
            j=len(row)-1
            while i<j:
                row[i], row[j] = row[j], row[i]
                i += 1
                j -= 1

```
