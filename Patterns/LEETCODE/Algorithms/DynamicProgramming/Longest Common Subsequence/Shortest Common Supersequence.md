### [Shortest Common Supersequence](https://leetcode.com/problems/shortest-common-supersequence/) <br>

Given two strings `str1` and `str2`, return *the shortest string that has both `str1` and `str2` as* ***subsequences***. If there are multiple valid strings, return **any** of them.

A string `s` is a **subsequence** of string `t` if deleting some number of characters from `t` (possibly `0`) results in the string `s`.



#### Example 1:

```
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

```

#### Example 2:

```
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"

```



# Solutions

### Python
```
class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        '''
        Extension of Longest Common Subsequence
        
        Example: 
            "aggtab"
            "gxtxaxb"
            Output: "aggxtxaxb"
            
            Backward version example here:
            
            Start with: 
            ['', '', '', '', '', '', '', '']
            ['', '', '', '', '', '', '', '']
            ['', '', '', '', '', '', '', '']
            ['', '', '', '', '', '', '', '']
            ['', '', '', '', '', '', '', '']
            ['', '', '', '', '', '', '', '']
            ['', '', '', '', '', '', '', '']
            
            End with:
                g       x      t      x     a     x     b
            a ['gtab', 'tab', 'tab', 'ab', 'ab', 'b', 'b', '']
            g ['gtab', 'tab', 'tab', 'ab', 'ab', 'b', 'b', '']
            g ['gtab', 'tab', 'tab', 'ab', 'ab', 'b', 'b', '']
            t ['tab',  'tab', 'tab', 'ab', 'ab', 'b', 'b', '']
            a ['ab',    'ab',  'ab', 'ab', 'ab', 'b', 'b', '']
            b ['b',     'b',    'b', 'b',  'b',  'b', 'b', '']
              ['',       '',     '',  '',   '',   '',  '', '']                        
            
        lcs = "gtab"
        
        Using three pointers - adding lsc characters only once into the final sting
            "aggtab"
              ^
            "gxtxaxb"
             ^
            "gtab"
             ^
            Output: "aggxtxaxb"
             
        '''
           
#         def LCS(A, B):
#             '''
#             Forward version
#             '''
#             n, m = len(A), len(B)
#             dp = [["" for _ in range(m+1)] for _ in range(n+1)]
            
#             for i in range(n):
#                 for j in range(m):
#                     if A[i] == B[j]:
#                         dp[i+1][j+1] = dp[i][j] + A[i]
#                     else:
#                         dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1], key=len)
#             return dp[-1][-1]

        def LCS(A, B):
            '''
            Backward version
            '''
            h, w = len(A), len(B)
            dp = [["" for _ in range(w+1)] for _ in range(h+1)]
                        
            for i in range(h)[::-1]:
                for j in range(w)[::-1]:
                    if A[i] == B[j]:
                        dp[i][j] = A[i] + dp[i+1][j+1]
                    else:
                        dp[i][j] = max(dp[i+1][j], dp[i][j+1], key=len)
            return dp[0][0]

        
        res, i, j = "", 0, 0
        lcs = LCS(str1, str2)
        if not lcs:
            return str1
    
        res=""
        p1,p2,p3=0,0,0
        while p3<len(lcs):
            while p1<len(str1) and str1[p1] != lcs[p3]:
                res += str1[p1]
                p1 += 1
            while p2<len(str2) and str2[p2] != lcs[p3]:
                res += str2[p2]
                p2 += 1
            res += lcs[p3]
            p1 += 1
            p2 += 1
            p3 += 1            
        return res + str1[p1:] + str2[p2:]

```
