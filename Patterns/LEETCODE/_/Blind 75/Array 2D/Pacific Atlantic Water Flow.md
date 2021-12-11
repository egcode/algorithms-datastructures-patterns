### [Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/) <br>

There is an `m x n` rectangular island that borders both the **Pacific Ocean** and **Atlantic Ocean**. The **Pacific Ocean** touches the island's left and top edges, and the **Atlantic Ocean** touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an `m x n` integer matrix `heights` where `heights[r][c]` represents the **height above sea level** of the cell at coordinate `(r, c)`.

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is **less than or equal to** the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a **2D list** *of grid coordinates* `result` *where* <img src="https://render.githubusercontent.com/render/math?math=result[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=r_i">, <img src="https://render.githubusercontent.com/render/math?math=c_i">] *denotes that rain water can flow from cell* (<img src="https://render.githubusercontent.com/render/math?math=r_i">, <img src="https://render.githubusercontent.com/render/math?math=c_i">) *to* **both** *the Pacific and Atlantic oceans*.



#### Example 1:
<img src="../../../../images/417waterflow-grid.jpg">

```
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

```

#### Example 2:

```
Input: heights = [[2,1],[1,2]]
Output: [[0,0],[0,1],[1,0],[1,1]]

```

# Solutions

### Python
```
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights: return []
        h=len(heights)
        w=len(heights[0])
        res=[]
        
        pacific=set()
        atlantic=set()        
        for i in range(w):
            pacific.add((0, i))
            atlantic.add((h-1, i))
        for i in range(h):
            pacific.add((i, 0))
            atlantic.add((i, w-1))
            
        memo={}
        def dfs(row, col, vis, reach_pacif, reach_atl):
            
            if (row, col) in memo.keys():
                return memo[(row, col)]
            
            if (row, col) in pacific:
                reach_pacif=True
            if (row, col) in atlantic:
                reach_atl=True
                
            if reach_pacif and reach_atl:
                return (reach_pacif, reach_atl)
                
            for d in [[-1,0],[0,1], [1,0],[0,-1]]:
                r=row+d[0]
                c=col+d[1]
                if  0 <= r < h and 0 <= c < w and heights[row][col] >= heights[r][c] and (r, c) not in vis:
                    vis.add((r, c))
                    rp, ra = dfs(r, c, vis, reach_pacif, reach_atl)
                    if rp:
                        reach_pacif=True
                    if ra:
                        reach_atl=True
                    if rp and ra:
                        memo[(r,c)]=(rp, ra)
                        return (rp, ra)
                    
            memo[(row,col)]=(reach_pacif, reach_atl)
            return (reach_pacif, reach_atl)
            
        
        for row in range(h):
            for col in range(w):
                memo={}
                vis=set()
                vis.add((row, col))
                rp, ra = dfs(row, col, vis, False, False)
                if rp and ra:
                    res.append([row, col])
            
        return res
        
```
