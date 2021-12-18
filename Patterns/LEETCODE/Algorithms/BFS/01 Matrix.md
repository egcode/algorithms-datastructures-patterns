### [01 Matrix](https://leetcode.com/problems/01-matrix/) <br>

Given an `m x n` binary matrix `mat`, return *the distance of the nearest `0` for each cell*.

The distance between two adjacent cells is `1`.



#### Example 1:
<img src="../../../../images/542-01-1-grid.jpg">

```
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

```

#### Example 2:
<img src="../../../../images/542-01-2-grid.jpg">

```
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

```



# Solutions

### Python
```
class Solution:
#     def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
#         '''
#         BFS   Time Limit Exceeded
#         '''
#         if not mat: return mat
#         h=len(mat)
#         w=len(mat[0])
        
#         def bfs(i, j):
#             q=collections.deque([(i, j, 0)])
#             vis=set()
#             vis.add((i, j))

#             while q:
#                 row, col, dist = q.pop()
#                 if mat[row][col]==0:
#                     return dist                    
#                 for dr, dc in [(1,0),(-1,0),(0,-1),(0,1)]:
#                     r=row+dr
#                     c=col+dc
#                     if 0<=r<h and 0<=c<w and (r, c) not in vis:
#                         vis.add((r,c))
#                         q.appendleft((r,c, dist+1))            
#             return -1
        
#         for i in range(h):
#             for j in range(w):
#                 if mat[i][j] == 1:
#                     d = bfs(i, j)
#                     mat[i][j] = d
                
#         return mat



    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        '''
        BFS 
        Just like in    286. Walls and Gates
        
            Add zeros to queue
        '''
        if not mat: return mat
        h=len(mat)
        w=len(mat[0])
        q=collections.deque()
        
        for i in range(h):
            for j in range(w):
                if mat[i][j] == 0:
                    q.appendleft((i, j, 0))
        
        vis=set()
        while q:
            row, col, dist = q.pop()
            mat[row][col]=dist
            for dr, dc in [(1,0),(-1,0),(0,1),(0,-1)]:
                r=row+dr
                c=col+dc
                if 0<=r<h and 0<=c<w and mat[r][c] != 0 and (r,c) not in vis:
                    vis.add((r,c))
                    q.appendleft((r,c, dist+1))
                    
                
        return mat    
```
