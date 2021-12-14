### [Design Tic-Tac-Toe](https://leetcode.com/problems/design-tic-tac-toe/) <br>

Assume the following rules are for the tic-tac-toe game on an `n x n` board between two players:

 1. A move is guaranteed to be valid and is placed on an empty block.
 2. Once a winning condition is reached, no more moves are allowed.
 3. A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.

Implement the `TicTacToe` class:

 - `TicTacToe(int n)` Initializes the object the size of the board `n`.
 - `int move(int row, int col, int player)` Indicates that the player with id `player` plays at the cell `(row, col)` of the board. The move is guaranteed to be a valid move.


#### Example 1:

```
Input
["TicTacToe", "move", "move", "move", "move", "move", "move", "move"]
[[3], [0, 0, 1], [0, 2, 2], [2, 2, 1], [1, 1, 2], [2, 0, 1], [1, 0, 2], [2, 1, 1]]
Output
[null, 0, 0, 0, 0, 0, 0, 1]

Explanation
TicTacToe ticTacToe = new TicTacToe(3);
Assume that player 1 is "X" and player 2 is "O" in the board.
ticTacToe.move(0, 0, 1); // return 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

ticTacToe.move(0, 2, 2); // return 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

ticTacToe.move(2, 2, 1); // return 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

ticTacToe.move(1, 1, 2); // return 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

ticTacToe.move(2, 0, 1); // return 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

ticTacToe.move(1, 0, 2); // return 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

ticTacToe.move(2, 1, 1); // return 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|

```


# Solutions

### Python
```
class TicTacToe:

    def __init__(self, n: int):
        """
        Initialize your data structure here.
        """
        self.n=n
        self.horiz=[0]*n
        self.vert=[0]*n
        self.diag1=0
        self.diag2=0

    def move(self, row: int, col: int, player: int) -> int:
        """
        Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins.
        """
        n=self.n
        move=1
        if player == 2:
            move=-1
        
        self.horiz[col] += move
        self.vert[row] += move
        
        
        '''
        00 | 01 | 02
        ___|____|____
        10 | 11 | 12
        ___|____|____
        20 | 21 | 22
        '''
        
        if row==col: # 00,  11,  22
            self.diag1 += move
        if row+col == (n-1): # 20, 11, 02 
            self.diag2 += move
            
        if abs(self.horiz[col])==n or abs(self.vert[row])==n or abs(self.diag1)==n or abs(self.diag2)==n:
            return player
        
        return 0

```
