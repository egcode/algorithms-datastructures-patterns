### [Valid Palindrome III](https://leetcode.com/problems/valid-palindrome-iii/) <br>

Given a string s and an integer `k`, return `true` if `s` is a `k`**-palindrome**.

A string is `k`**-palindrome** if it can be transformed into a palindrome by removing at most `k` characters from it.

 



#### Example 1:

```
Input: s = "abcdeca", k = 2
Output: true
Explanation: Remove 'b' and 'e' characters.

```

#### Example 2:

```
Input: s = "abbababa", k = 1
Output: true

```



# Solutions

### Python
```
class Solution:
    def isValidPalindrome(self, s: str, k: int) -> bool:
        '''
        Extension of Longest Palindromic Subsequence, here we just count min non palindrome chars
        Example:
        "abcdeca"
        2
        Output: true
        
           a  b  c  d  e  c  a      
        a [0, 1, 2, 3, 4, 3, 2]
        b [0, 0, 1, 2, 3, 2, 3]
        c [0, 0, 0, 1, 2, 1, 2]
        d [0, 0, 0, 0, 1, 2, 3]
        e [0, 0, 0, 0, 0, 1, 2]
        c [0, 0, 0, 0, 0, 0, 1]
        a [0, 0, 0, 0, 0, 0, 0]
        
        '''
    
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for i in range(n)[::-1]:
            for j in range(i+1, n):
                if s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1]
                else:
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1])+1

        return dp[0][-1] <= k
    

```
