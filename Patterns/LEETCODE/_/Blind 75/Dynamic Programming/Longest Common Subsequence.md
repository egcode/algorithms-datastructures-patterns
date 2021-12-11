### [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) <br>

Given two strings `text1` and `text2`, return the length of their longest **common subsequence**. If there is no **common subsequence**, return `0`.

A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

 - For example, `"ace"` is a subsequence of `"abcde"`.

A **common subsequence** of two strings is a subsequence that is common to both strings.

 

#### Example 1:

```
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

```

#### Example 2:

```
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

```

#### Example 3:

```
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

```

# Solutions

### Python
```
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        '''
        Same as below but we loop from the end
           a  c  e
        a [0, 0, 0, 0], 
        b [0, 0, 0, 0], 
        c [0, 0, 0, 0], 
        d [0, 0, 0, 0], 
        e [0, 0, 0, 0], 
          [0, 0, 0, 0]]

        '''            
        
        n1=len(text1)
        n2=len(text2)
        dp=[[0]*(n2+1) for _ in range((n1+1))]
        
        
        for row in range(n1)[::-1]:
            for col in range(n2)[::-1]:
                if text1[row]==text2[col]:
                    dp[row][col]=max(dp[row][col], 1+dp[row+1][col+1])
                else:
                    dp[row][col]=max(dp[row][col], dp[row][col+1], dp[row+1][col])
        
        return dp[0][0]
    

#     def longestCommonSubsequence(self, text1: str, text2: str) -> int:
#         '''
#         Same as above, but we loop from begining
#            a  c  e
#         a [0, 0, 0, 0], 
#         b [0, 0, 0, 0], 
#         c [0, 0, 0, 0], 
#         d [0, 0, 0, 0], 
#         e [0, 0, 0, 0], 
#           [0, 0, 0, 0]]

#         '''            
        
#         n1=len(text1)
#         n2=len(text2)
#         dp=[[0]*(n2+1) for _ in range((n1+1))]
        
        
#         for row in range(n1):
#             for col in range(n2):
#                 if text1[row]==text2[col]:
#                     dp[row+1][col+1]=max(dp[row+1][col+1], 1+dp[row][col])
#                 else:
#                     dp[row+1][col+1]=max(dp[row+1][col+1], dp[row][col+1], dp[row+1][col])
#         print(dp)
        
#         return
```
