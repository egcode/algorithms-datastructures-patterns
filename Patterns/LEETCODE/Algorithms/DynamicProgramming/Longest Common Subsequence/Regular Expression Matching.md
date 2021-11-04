### [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/) <br>

Given an input string `s` and a pattern `p`, implement regular expression matching with support for `'.'` and `'*'` where:

 - `'.'` Matches any single character.​​​​
 - `'*'` Matches zero or more of the preceding element.

The matching should cover the **entire** input string (not partial).



#### Example 1:

```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

```

#### Example 2:

```
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

```

#### Example 3:

```
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

```
#### Example 4:

```
Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

```
#### Example 5:

```
Input: s = "mississippi", p = "mis*is*p*."
Output: false

```

# Solutions

### Python
```
class Solution:
#     def isMatch(self, s: str, p: str) -> bool:
#         if p=="":
#             return s==""
        
#         first_match=False
#         if s != "":
#             if s[0]==p[0] or p[0]=='.':
#                 first_match=True
            
#         if len(p)>1 and p[1]=='*':
#             # Handle * star repeated chars
            
#             # continue deleting characters with star, and we still using same pattern with star. 
#             # first_match makes sure that we are deleting right character with s[1:] 
#             # eg `ssssip` becomes `ip` with pattern `s*ip`
#             deleting_repeated_with_star = first_match and self.isMatch(s[1:], p) 
            
#             # We done deleting repeated characters from * and deleting star from pattern. 
#             # eg `s*issip` becomes `issip`
#             finished_with_star = self.isMatch(s, p[2:]) 
            
#             return deleting_repeated_with_star or finished_with_star
#         else:
#             return first_match and self.isMatch(s[1:], p[1:])
        
        
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[False] * (len(p) + 1) for _ in range(len(s) + 1)]

        dp[-1][-1] = True
        for i in range(len(s), -1, -1):
            for j in range(len(p) - 1, -1, -1):
                first_match = i < len(s) and p[j] in {s[i], '.'}
                if j+1 < len(p) and p[j+1] == '*':
                    dp[i][j] = dp[i][j+2] or first_match and dp[i+1][j]
                else:
                    dp[i][j] = first_match and dp[i+1][j+1]

        return dp[0][0]        
        

```
