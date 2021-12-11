### [Word Search II](https://leetcode.com/problems/word-search-ii/) <br>

Given an `m x n` `board` of characters and a list of strings `words`, return *all words on the board*.

Each word must be constructed from letters of sequentially adjacent cells, where **adjacent cells** are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.


#### Example 1:
<img src="../../../../images/212search1.jpg">

```
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

```

#### Example 2:
<img src="../../../../images/212search2.jpg">

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
        
    def add(self, word):
        cur=self.root
        for l in word:
            if l in cur.children.keys():
                cur=cur.children[l]
            else:
                new_node=TrieNode()
                cur.children[l]=new_node
                cur=new_node
        cur.is_word=True


class Solution:
    def __init__(self):
        self.trie=Trie()
        self.ans=[]
    
    def DFS(self, board, r, c, node, cand):
        if node.is_word==True:
            self.ans.append(cand)
            node.is_word=False
            
        if r<0 or r >= len(board) or c<0 or c >= len(board[r]):
            return
        
        l=board[r][c]
        
        if l not in node.children.keys():
            return
        
        board[r][c]="#"
        self.DFS(board, r+1,c , node.children[l], cand+l)
        self.DFS(board, r-1,c , node.children[l], cand+l)
        self.DFS(board, r,c+1 , node.children[l], cand+l)
        self.DFS(board, r,c-1 , node.children[l], cand+l)
        board[r][c]=l
        
                
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        for w in words:
            self.trie.add(w)
            
        for i in range(len(board)):
            for j in range(len(board[i])):
                self.DFS(board, i,j , self.trie.root, "")
                
        return self.ans

```
