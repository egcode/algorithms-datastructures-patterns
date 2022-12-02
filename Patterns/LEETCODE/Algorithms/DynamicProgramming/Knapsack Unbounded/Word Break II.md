### [Word Break II](https://leetcode.com/problems/word-break-ii/) <br>

Given a string `s` and a dictionary of strings `wordDict`, add spaces in `s` to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in **any order**.

**Note** that the same word in the dictionary may be reused multiple times in the segmentation.




#### Example 1:

```
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

```

#### Example 2:

```
Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.

```

#### Example 3:

```
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []

```


# Solutions

### Python
```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        '''
        DFS Recurstion
        '''
        memo={}
        
        def dfs(path):
            if path=="":
                return [[]]
            
            if path in memo.keys():
                return memo[path]
            
            out=[]
            for word in wordDict:
                if len(word)<=len(path) and path[:len(word)]==word:
                    suffix=path[len(word):]
                    r=dfs(suffix)
                    
                    tmp=[]
                    for t in r:
                        tmp.append([word]+t)
                    
                    if tmp:
                        out += tmp
            
            memo[path]=out
            return out
        
        res=dfs(s)
        
        return [" ".join(el) for el in res]
        
    
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        '''
        DP Tabulation
        '''
        n=len(s)
        dp=[[] for _ in range(n+1)]
        dp[0]=[[]]
        
        for i in range(n):
            for word in wordDict:
                if word==s[i:i+len(word)]:
                    tmp=[]
                    for d in dp[i]:
                        tmp.append(d+[word])
                    if tmp:
                        dp[i+len(word)] += tmp
                    
        return [" ".join(dd) for dd in dp[-1]]

```
