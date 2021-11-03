### [Concatenated Words](https://leetcode.com/problems/concatenated-words/) <br>

Given an array of strings `words` (**without duplicates**), return all the **concatenated words** in the given list of `words`.

A **concatenated word** is defined as a string that is comprised entirely of at least two shorter words in the given array.

#### Example 1:

```
Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".

```

#### Example 2:

```
Input: words = ["cat","dog","catdog"]
Output: ["catdog"]

```

# Solutions

### Python
```
class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        memo={}
        wrds=set(words)
        
        def dfs(word):
            if word in memo.keys():
                return memo[word]
            
            for i in range(1, len(word)):
                prefix=word[:i]
                suffix=word[i:]
                
                if prefix in wrds and suffix in wrds:
                    memo[word]=True
                    return True
                if prefix in wrds and dfs(suffix):
                    memo[word]=True
                    return True
                
            memo[word]=False    
            return False
        
        res=[]
        for wrd in words:
            if dfs(wrd):
                res.append(wrd)
        
        return res

```
