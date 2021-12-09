### [Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/) <br>

Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return list of lists of the suggested products after each character of searchWord is typed. 




#### Example 1:

```
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]

```

#### Example 2:

```
Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]

```

#### Example 3:

```
Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]

```

#### Example 4:

```
Input: products = ["havana"], searchWord = "tatiana"
Output: [[],[],[],[],[],[],[]]

```


# Solutions

### Python
```
class TrieNode:
    def __init__(self):
        self.children={}
        self.is_word=False
        self.paths=set()
        
class Trie:
    def __init__(self):
        self.root=TrieNode()
        
    def add_word(self, word):
        cur=self.root
        for ch in word:
            if ch not in cur.children.keys():
                cur.children[ch]= TrieNode()
            cur = cur.children[ch]
            cur.paths.add(word) # Add word here     
        cur.is_word=True
        
    def search_paths(self, word):
        cur=self.root
        for ch in word:
            if ch in cur.children.keys():
                cur = cur.children[ch]
            else:
                return []
        return sorted(list(cur.paths))[:3]
    
class Solution:
    
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        trie=Trie()
        for wrd in products:
            trie.add_word(wrd)
            
        res=[]
        for i in range(1, len(searchWord)+1):
            word=searchWord[:i]
            wrds=trie.search_paths(word)
            # print("_")
            # print(word)
            # print(wrds)
            res.append(wrds)
        
        return res
```
