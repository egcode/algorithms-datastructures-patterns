### [Word Search II](https://leetcode.com/problems/word-search-ii/) <br>

Given an `m x n` `board` of characters and a list of strings `words`, return *all words on the board*.

Each word must be constructed from letters of sequentially adjacent cells, where **adjacent cells** are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.


#### Example 1:
<img src="../../../../../images/212search1.jpg">

```
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

```

#### Example 2:
<img src="../../../../../images/212search2.jpg">

```
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []

```

# Solutions

### Python
```
class TrieNode:
    def __init__(self):
        self.is_word=False
        self.children={}
        
class Trie:
    def __init__(self):
        self.root=TrieNode()
        
    # def add(self, word):
    #     cur=self.root
    #     for l in word:
    #         if l in cur.children.keys():
    #             cur=cur.children[l]
    #         else:
    #             new_node=TrieNode()
    #             cur.children[l]=new_node
    #             cur=new_node
    #     cur.is_word=True
    def add(self, word):
        '''
        Faster add
        '''
        root = self.root
        for c in word:
            if c not in root.children:
                root.children[c] = TrieNode()
            root = root.children[c]
        root.is_word = True
        

class Solution:        
                
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie=Trie()
        for w in words:
            trie.add(w)    
        res=[]
        
        def dfs(r,c, node, path):
            nonlocal trie
            nonlocal res
            if node.is_word==True:
                res.append(path)
                # TRICKY part
                # prevet duplicate word found in board
                node.is_word = False
                # don't return for search word with prefix part string
                # return
            l=board[r][c]
            board[r][c]="#"
            for d in [[-1,0],[1,0],[0,-1],[0,1]]:
                row=r+d[0]
                col=c+d[1]
                if 0<=row<len(board) and 0<=col<len(board[row]) and board[row][col] in node.children:
                    new_ch=board[row][col]                                    
                    dfs(row, col, node.children[new_ch], path+new_ch)
            board[r][c]=l
            
            
        for i in range(len(board)):
            for j in range(len(board[i])):
                ch = board[i][j]
                if ch in trie.root.children:
                    dfs(i,j , trie.root.children[ch], ch)
                
        return res

```
