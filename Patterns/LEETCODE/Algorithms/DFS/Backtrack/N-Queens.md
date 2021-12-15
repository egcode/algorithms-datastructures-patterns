### [N-Queens](https://leetcode.com/problems/n-queens/) <br>

The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return *all distinct solutions to the ***n-queens puzzle***. You may return the answer in **any order***.

Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.



#### Example 1:
<img src="../../../../../images/51queens.jpg">

```
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

```

#### Example 2:

```
Input: n = 1
Output: [["Q"]]

```

# Solutions

### Python
```
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def could_place(row, col):
            print("\n")
            print("row:"+str(row)+" col:"+str(col))
            print("cols[col]: "+str(cols[col]))
            print("hill_diagonals[row - col]: "+str(hill_diagonals[row - col]))
            print("dale_diagonals[row + col]: "+str(dale_diagonals[row + col])) 
            
            not_res = (cols[col] + hill_diagonals[row - col] + dale_diagonals[row + col])
            print("not_res: "+str(not_res)) 
            
            return not not_res
        
        def place_queen(row, col):
            queens.add((row, col))
            cols[col] = 1
            hill_diagonals[row - col] = 1
            dale_diagonals[row + col] = 1
        
        def remove_queen(row, col):
            queens.remove((row, col))
            cols[col] = 0
            hill_diagonals[row - col] = 0
            dale_diagonals[row + col] = 0
        
        def add_solution():
            solution = []
            for _, col in sorted(queens):
                solution.append('.' * col + 'Q' + '.' * (n - col - 1))
            output.append(solution)
        
        def backtrack(row = 0):
            for col in range(n):
                if could_place(row, col):
                    place_queen(row, col)
                    if row + 1 == n:
                        add_solution()
                    else:
                        backtrack(row + 1)
                    remove_queen(row, col)
        
        cols = [0] * n
        hill_diagonals = [0] * (2 * n - 1)
        dale_diagonals = [0] * (2 * n - 1)
        queens = set()
        output = []
        backtrack()
        return output
```
