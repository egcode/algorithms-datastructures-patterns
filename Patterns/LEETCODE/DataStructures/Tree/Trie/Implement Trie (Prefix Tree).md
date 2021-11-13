### [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/) <br>

A [trie](https://en.wikipedia.org/wiki/Trie) (pronounced as "try") or **prefix tree** is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

 - `Trie()` Initializes the trie object.
 - `void insert(String word)` Inserts the string `word` into the trie.
 - `boolean search(String word)` Returns `true` if the string `word` is in the trie (i.e., was inserted before), and `false` otherwise.
 - `boolean startsWith(String prefix)` Returns `true` if there is a previously inserted string `word` that has the prefix `prefix`, and `false` otherwise.



#### Example:

```
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

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
        """
        Initialize your data structure here.
        """
        self.root=TrieNode()

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        cur=self.root
        for l in word:
            if l in cur.children.keys():
                cur=cur.children[l]
            else:
                new_node=TrieNode()
                cur.children[l]=new_node
                cur=new_node
        cur.is_word=True
                

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        cur=self.root
        for l in word:
            if l in cur.children.keys():
                cur=cur.children[l]
            else:
                return False
        return cur.is_word
    

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        cur=self.root
        for l in prefix:
            if l in cur.children.keys():
                cur=cur.children[l]
            else:
                return False
        return True

```
