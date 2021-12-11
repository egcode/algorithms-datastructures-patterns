### [Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/) <br>

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the `WordDictionary` class:

 - `WordDictionary()` Initializes the object.
 - `void addWord(word)` Adds `word` to the data structure, it can be matched later.
 - `bool search(word)` Returns `true` if there is any string in the data structure that matches `word` or `false` otherwise. `word` may contain dots `'.'` where dots can be matched with any letter.

#### Example:

```
Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

```


# Solutions

### Python
```
class TrieNode:
    def __init__(self):
        self.children={}
        self.is_word=False
        
class Trie:
    def __init__(self):
        self.root=TrieNode()

    def add_word(self, word):
        cur=self.root
        for ch in word:
            if ch not in cur.children.keys():
                cur.children[ch]=TrieNode()
            cur=cur.children[ch]
        cur.is_word=True
        
    def search_word(self, word, nd=None):
        cur=nd
        if nd == None:
            cur=self.root
        
        for i,ch in enumerate(word):
            if ch in cur.children.keys():
                cur=cur.children[ch]
            elif ch=='.':
                for child in cur.children.values():
                    if self.search_word(word[i+1:], child):
                        return True
                return False
            else:
                return False
            
        return cur.is_word


class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie=Trie()

    def addWord(self, word: str) -> None:
        self.trie.add_word(word)
        

    def search(self, word: str) -> bool:
        return self.trie.search_word(word)

```
