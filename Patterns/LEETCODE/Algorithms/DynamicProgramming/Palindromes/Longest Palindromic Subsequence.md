### [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/) <br>

Given a string `s`, find the longest palindromic **subsequence**'s length in `s`.

A **subsequence** is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.



#### Example 1:

```
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

```

#### Example 2:

```
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

```

# Solutions

### Python
```
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        '''
        Dynamic Programming 
                                https://youtu.be/_nCsPn7_OgI
        s="agbdba"
        
        if s[i]==s[j]:
            dp[i][j]=2+dp[i+1][j-1]
        else:
            dp[i][j]=max(dp[i][j-1], dp[i-1][j])
        
        Start with:
           a g b d b a
         a 1 0 0 0 0 0
         g 0 1 0 0 0 0 
         b 0 0 1 0 0 0 
         d 0 0 0 1 0 0 
         b 0 0 0 0 1 0 
         a 0 0 0 0 0 1 
        
        End with:
           a g b d b a
         a 1 1 1 1 3 5
         g 0 1 1 1 3 3 
         b 0 0 1 1 3 3 
         d 0 0 0 1 1 1 
         b 0 0 0 0 1 1 
         a 0 0 0 0 0 1 
        
        Result = 5
        '''
        n=len(s)
        dp=[[0]*n for _ in range(n)]
        for i in range(n):
            dp[i][i]=1
                
        palLen=1
        for i in range(n)[::-1]:
            for j in range(i+1, i+palLen+1):
                if j>=n: continue
                if s[j]==s[i]:
                    dp[i][j]=2+dp[i+1][j-1]
                else:
                    dp[i][j]=max(dp[i][j-1], dp[i+1][j])
            palLen += 1        
        
        return dp[0][-1]

```
