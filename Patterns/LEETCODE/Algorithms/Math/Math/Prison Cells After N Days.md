### [Prison Cells After N Days](https://leetcode.com/problems/prison-cells-after-n-days/) <br>

There are `8` prison cells in a row and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

 - If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
 - Otherwise, it becomes vacant.

**Note** that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.

You are given an integer array `cells` where `cells[i] == 1` if the ith cell is occupied and `cells[i] == 0` if the `i-th` cell is vacant, and you are given an integer `n`.

Return *the state of the prison after* `n` *days* (i.e., `n` such changes described above).



#### Example 1:

```
Input: cells = [0,1,0,1,1,0,0,1], n = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

```

#### Example 2:

```
Input: cells = [1,0,0,1,0,0,1,0], n = 1000000000
Output: [0,0,1,1,1,1,1,0]

```



# Solutions

### Python
```
class Solution:
    def prisonAfterNDays(self, cells: List[int], n: int) -> List[int]:
        dic={}
        jumped=False
        while n>0:
            
            if jumped==False:
                key=tuple(cells)
                if key not in dic.keys():
                    dic[key]=n
                else:
                    # Jump cycle here
                    last_found=dic[key]
                    cycle_len=last_found-n
                    n %= cycle_len
                    jumped=True
            if n>0:
                tmp=[0] # Start
                for i in range(1, 7):
                    prv=cells[i-1]
                    nxt=cells[i+1]
                    tmp.append(int(prv==nxt))
                tmp.append(0) # End
                cells=tmp
            
            n -= 1
        
        return cells

```
