### [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) <br>

Given a string `s`, return the longest palindromic substring in `s`.



#### Example 1:

```
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

```

#### Example 2:

```
Input: s = "cbbd"
Output: "bb"

```

#### Example 3:

```
Input: s = "a"
Output: "a"

```

#### Example 4:

```
Input: s = "ac"
Output: "a"

```

# Solutions

### Python
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        
        def check(start, end):
            while start-1>=0 and end+1<len(s) and s[start-1]==s[end+1]:
                start -= 1
                end += 1   
            return s[start:end+1]
        
        res=""
        
        for i in range(len(s)):
            out1=check(i, i)
            if len(res)<len(out1):
                res=out1
            if i>0 and s[i-1]==s[i]:
                out2=check(i-1, i)
                if len(res)<len(out2):
                    res=out2
        
        return res

```
