### [Word Break](https://leetcode.com/problems/word-break/) <br>

Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.

**Note** that the same word in the dictionary may be reused multiple times in the segmentation.



#### Example 1:

```
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

```

#### Example 2:

```
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

```

#### Example 3:

```
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

```

# Solutions

### Python
```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        '''
        Tabulation:
            Start with:
                [True, False, False, False, False, False, False, False, False]

            End with:
                [True, False, False, False, True, False, False, False, True]
        
        '''
        dp = [False] * (len(s) + 1)
        dp[0] = True
        print(dp)
        for i in range(len(s)):
            if dp[i]==True:

                for word in wordDict:
                    if s[i : i + len(word)] == word:
                        dp[i + len(word)] = True
        print(dp)
        return dp[-1]
        
        
#     def wordBreak(self, s: str, wordDict: List[str]) -> bool:
#         '''
#         Memoization
#         '''
        
#         memo={}
#         def dfs(path):
#             if path in memo.keys():
#                 return memo[path]
#             if path=="":
#                 memo[path]=True
#                 return True
#             for word in wordDict:
#                 if len(path)>=len(word) and path[:len(word)]==word:
#                     suffix=path[len(word):]
#                     if dfs(suffix)==True:
#                         memo[path]=True
#                         return True
#             memo[path]=False
#             return False
        
        
#         return dfs(s)

```
