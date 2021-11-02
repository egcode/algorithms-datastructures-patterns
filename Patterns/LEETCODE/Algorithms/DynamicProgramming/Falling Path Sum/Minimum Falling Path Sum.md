### [Minimum Falling Path Sum](https://leetcode.com/problems/minimum-falling-path-sum/) <br>

Given an `n x n` array of integers `matrix`, return the **minimum sum** of any **falling path** through `matrix`.

A **falling path** starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position `(row, col)` will be `(row + 1, col - 1)`, `(row + 1, col)`, or `(row + 1, col + 1)`.



#### Example 1:

```
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum underlined below:
[[2,1,3],      [[2,1,3],
 [6,5,4],       [6,5,4],
 [7,8,9]]       [7,8,9]]

1 -> 5 -> 7         1 -> 4 -> 8
```


#### Example 2:

```
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is underlined below:
[[-19,57],
 [-40,-5]]

-19 -> -40
```


#### Example 3:

```
Input: matrix = [[-48]]
Output: -48

```

# Solutions

### Python
```
class Solution:
#     def minFallingPathSum(self, matrix: List[List[int]]) -> int:
#         '''
#         Dijkstra's algorithm Time Limit Exceeded
#         '''
#         if not matrix: return 0
#         h=len(matrix)
#         w=len(matrix)
        
#         heap=[]
#         for i in range(w):
#             heappush(heap, (matrix[0][i], 0, i, matrix[0][i]))
            
#         res=float('inf')
#         while heap:
#             curr_val, row, col, path = heappop(heap)
#             if row==(h-1):
#                 res=min(res, path)
            
#             for d in [[1, 0],[1,-1],[1,1]]:
#                 r=row+d[0]
#                 c=col+d[1]
#                 if 0<=r<h and 0<=c<w:
#                     heappush(heap, (matrix[r][c], r, c, path+matrix[r][c]))
            
#         return res
    
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        '''
        Dynamic programming
        '''
        if not matrix: return 0
        h=len(matrix)
        w=len(matrix)
        
        dp=[ [float('inf')]*(w+1) for _ in range(h)]
        dp[-1]=matrix[-1]+[float('inf')]
        for r in range(h-1)[::-1]:
            for c in range(w)[::-1]:
                dp[r][c]=matrix[r][c]+min(dp[r+1][c+1], dp[r+1][c], dp[r+1][c-1])
        
        return min(dp[0])
        
```
