### [problem_title](https://leetcode.com/problems/word-search/) <br>

Given an `m x n` grid of characters `board` and a string `word`, return `true` *if* `word` *exists in the grid*.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.




#### Example 1:
<img src="../../../../../images/79word1.jpg">

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

```

#### Example 2:
<img src="../../../../../images/79word2.jpg">

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

```

#### Example 3:
<img src="../../../../../images/79word3.jpg">

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

```

# Solutions

### Python
```
class Solution(object):
    def exist(self, board, word):
        self.ROWS = len(board)
        self.COLS = len(board[0])
        self.board = board

        for row in range(self.ROWS):
            for col in range(self.COLS):
                if self.backtrack(row, col, word):
                    return True

        # no match found after all exploration
        return False


    def backtrack(self, row, col, suffix):
        # bottom case: we find match for each letter in the word
        if len(suffix) == 0:
            return True

        # Check the current status, before jumping into backtracking
        if row < 0 or row == self.ROWS or col < 0 or col == self.COLS \
                or self.board[row][col] != suffix[0]:
            return False

        ret = False
        # mark the choice before exploring further.
        self.board[row][col] = '#'
        # explore the 4 neighbor directions
        for rowOffset, colOffset in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            ret = self.backtrack(row + rowOffset, col + colOffset, suffix[1:])
            # break instead of return directly to do some cleanup afterwards
            if ret: break

        # revert the change, a clean slate and no side-effect
        self.board[row][col] = suffix[0]

        # Tried all directions, and did not find any match
        return ret




# class TrieNode:
#     def __init__(self):
#         self.is_word=False
#         self.children={}
        
# class Trie:
#     def __init__(self):
#         self.root=TrieNode()
        
#     def add(self, word):
#         cur=self.root
#         for letter in word:
#             if letter in cur.children:
#                 cur=cur.children[letter]
#             else:
#                 new_node=TrieNode()
#                 cur.children[letter]=new_node
#                 cur=cur.children[letter]
#         cur.is_word=True
        

# class Solution:
    
#     def exist(self, board: List[List[str]], word: str) -> bool:
        
#         trie=Trie()
#         trie.add(word)

#         ans=False
        
#         def backtrack(board, r, c, node):
#             if node.is_word==True:
#                 return True            
            
#             if r<0 or r>len(board)-1 or c<0 or c>len(board[0])-1:
#                 return False
            
            
#             letter=board[r][c]
#             if letter not in node.children.keys():
#                 return False
            
#             board[r][c]="#"
            
            
#             if backtrack(board, r+1, c, node.children[letter]): return True
#             if backtrack(board, r-1, c, node.children[letter]): return True
#             if backtrack(board, r, c+1, node.children[letter]): return True
#             if backtrack(board, r, c-1, node.children[letter]): return True
            
#             board[r][c]=letter
#             return False
        
#         for i in range(0, len(board)):
#             for j in range(0, len(board[i])):
#                 if backtrack(board, i, j, trie.root): 
#                     return True
#         return ans

```
