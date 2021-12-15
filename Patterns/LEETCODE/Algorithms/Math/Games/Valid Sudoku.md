### [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/) <br>

Determine if a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated **according to the following rules**:

 1. Each row must contain the digits `1-9` without repetition.
 2. Each column must contain the digits `1-9` without repetition.
 3. Each of the nine `3 x 3` sub-boxes of the grid must contain the digits `1-9` without repetition.

**Note**:
 - A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 - Only the filled cells need to be validated according to the mentioned rules.


#### Example 1:
<img src="../../../../../images/36_250px-Sudoku.png">

```
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

```

#### Example 2:

```
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

```



# Solutions

### Python
```
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        #box_index = (i//3)*3+j//3
        
        h={}
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j]==".": continue
                    
                r="r-"+str(i)+"-"+str(board[i][j])
                c="c-"+str(j)+"-"+str(board[i][j])
                
                box_index=(i//3)*3+j//3
                b="b-"+str(box_index)+"-"+str(board[i][j])
                
                if r in h.keys():
                    return False
                if c in h.keys():
                    return False
                if b in h.keys():
                    return False
                
                h[r]=True
                h[c]=True
                h[b]=True
                
        return True

```
