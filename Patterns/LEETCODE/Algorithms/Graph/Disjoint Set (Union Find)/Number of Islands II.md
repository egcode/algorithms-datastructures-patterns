### [Number of Islands II](https://leetcode.com/problems/number-of-islands-ii/) <br>

You are given an empty 2D binary grid `grid` of size `m x n`. The grid represents a map where `0`'s represent water and `1`'s represent land. Initially, all the cells of grid are water cells (i.e., all the cells are `0`'s).

We may perform an add land operation which turns the water at position into a land. You are given an array positions where <img src="https://render.githubusercontent.com/render/math?math=positions[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=r_i">, <img src="https://render.githubusercontent.com/render/math?math=c_i">] is the position (<img src="https://render.githubusercontent.com/render/math?math=r_i">, <img src="https://render.githubusercontent.com/render/math?math=c_i">) at which we should operate the <img src="https://render.githubusercontent.com/render/math?math=i^{th}"> operation.

Return *an array of integers `answer` where `answer[i]` is the number of islands after turning the cell* (<img src="https://render.githubusercontent.com/render/math?math=r_i">, <img src="https://render.githubusercontent.com/render/math?math=c_i">) *into a land*.

An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.



#### Example 1:
<img src="../../../../../images/305_tmp-grid.jpg">

```
Input: m = 3, n = 3, positions = [[0,0],[0,1],[1,2],[2,1]]
Output: [1,1,2,3]
Explanation:
Initially, the 2d grid is filled with water.
- Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land. We have 1 island.
- Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land. We still have 1 island.
- Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land. We have 2 islands.
- Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land. We have 3 islands.

```

#### Example 2:

```
Input: m = 1, n = 1, positions = [[0,0]]
Output: [1]

```



# Solutions

### Python
```
class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        '''
        Disjoint set (union find) with 2D matrix.
        Convert 2D array into 1D array
        To get value from 1D array:
        index = row * width + col
        '''
        root=[-1 for _ in range(m*n)]
        rank=[0]*(m*n)
        count=0
        res=[]
        
        def find(x):
            if x == root[x]:
                return x
            root[x] = find(root[x])
            return root[x]

        def union(x, y):
            nonlocal count
            rootX = find(x)
            rootY = find(y)
            if rootX != rootY:
                if rank[rootX] > rank[rootY]:
                    root[rootY] = rootX
                elif rank[rootX] < rank[rootY]:
                    root[rootX] = rootY
                else:
                    root[rootY] = rootX
                    rank[rootX] += 1    
                count -= 1
                
        def set_root(i):
            nonlocal count
            if root[i] == -1:
                root[i]=i
                count += 1
            
            
        for r,c in positions:
            islands_met=set()
            if r-1>=0 and root[(r-1)*n+c] >= 0:
                islands_met.add((r-1)*n+c)
            if r+1<m and root[(r+1)*n+c] >= 0:
                islands_met.add((r+1)*n+c)
                
            if c-1>=0 and root[r*n+c-1] >= 0:
                islands_met.add(r*n+c-1)
            if c+1<n and root[r*n+c+1] >= 0:
                islands_met.add(r*n+c+1)
                
                
            index=r*n+c
            set_root(index)
            for ismet in islands_met:
                union(ismet, index)
            res.append(count)
                
            
        return res        
                    
    
#     def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
#         '''
#         Cache every position in `roots` map and store it's roots.
#         Cache every island and store it's children in `islands` map.
#         If we merge islands we delete not needed islands from `islands` map and reassign it's roots in `roots` map.
#         '''
#         roots={} # key-(x,y)   value-island root (x,y)
#         islands=collections.defaultdict(list) # key-island root,   value-array of children [(x1,y1), (x2,y2)]
                        
#         res=[]    
#         for row,col in positions:
#             islands_met=set()
#             for d in [[-1,0], [1,0],[0,1],[0,-1]]:
#                 r=row+d[0]
#                 c=col+d[1]
#                 if 0<=r<m and 0<=c<n:
#                     if (r,c) in roots.keys():
#                         islands_met.add(roots[(r,c)])
                        
#             if len(islands_met)==0:
#                 islands[(row,col)].append((row,col))
#                 roots[(row,col)]=(row,col)
#             elif len(islands_met)==1:
#                 root=islands_met.pop()
#                 islands[root].append((row,col))
#                 roots[(row,col)]=root
#             elif len(islands)>1:
#                 root1=islands_met.pop()
#                 islands[root1].append((row,col))
#                 roots[(row,col)]=root1
#                 for root2 in islands_met:
#                     for rr in islands[root2]:
#                         # union(root1,root2)
#                         roots[(rr[0],rr[1])]=root1
#                         islands[root1].append(rr)
#                     del islands[root2]
                    
#             res.append(len(islands.keys()))
                    
            
#         return res

```
