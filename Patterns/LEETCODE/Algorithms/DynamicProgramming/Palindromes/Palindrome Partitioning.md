### [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) <br>

Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**. Return all possible palindrome partitioning of `s`.

A **palindrome** string is a string that reads the same backward as forward.

 




#### Example 1:

```
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

```

#### Example 2:

```
Input: s = "a"
Output: [["a"]]

```


# Solutions

### Python
```
class Solution:
#     def partition(self, s: str) -> List[List[str]]:
#         '''
#         Recursive
#         '''
#         res=[]  

#         def is_palindrome(ss):
#             return ss == ss[::-1]  
        
        
#         def dfs(s, path):
#             if not s: 
#                 res.append(path[:])
                
#             for i in range(1, len(s)+1):
#                 if is_palindrome(s[:i]): # s[:i] i exclusive, that is why we are looping to len(s)+1)
#                     dfs(s[i:], path+[s[:i]])
                    
                
#         dfs(s, [])
#         return res
    
    
    def partition(self, s: str) -> List[List[str]]:
        '''
        Tabulation
        '''
        dp = [[] for _ in range(len(s) + 1)]
        dp[-1] = [[]]
        
        
        for i in range(len(s))[::-1]:
            for j in range(i + 1, len(s) + 1):
                if s[i:j] == s[i:j][::-1]:
                    for each in dp[j]:
                        dp[i].append([s[i:j]] + each)
                        
        return dp[0]

```
