### [Longest Repeating Substring](https://leetcode.com/problems/longest-repeating-substring/) <br>

Given a string `s`, *return the length of the longest repeating substrings. If no repeating substring exists, return* `0`.


#### Example 1:

```
Input: s = "abcd"
Output: 0
Explanation: There is no repeating substring.

```

#### Example 2:

```
Input: s = "abbaba"
Output: 2
Explanation: The longest repeating substrings are "ab" and "ba", each of which occurs twice.

```

#### Example 3:

```
Input: s = "aabcaabdaab"
Output: 3
Explanation: The longest repeating substring is "aab", which occurs 3 times.

```



# Solutions

### Python
```
class Solution:
    def longestRepeatingSubstring(self, s: str) -> int:
        '''
        Just like Longest Common Subsequence but:
            1. Do string to itself
            2. Do top right corner.
            3. j>i
        
           a  b  b  a  b  a        
        a [0, 0, 0, 0, 0, 0, 0]
        b [0, 0, 0, 0, 0, 0, 0]
        b [0, 0, 0, 0, 0, 0, 0]
        a [0, 0, 0, 0, 0, 0, 0]
        b [0, 0, 0, 0, 0, 0, 0]
        a [0, 0, 0, 0, 0, 0, 0]
          [0, 0, 0, 0, 0, 0, 0]        
        
           a  b  b  a  b  a        
        a [0, 0, 0, 2, 0, 1, 0]
        b [0, 0, 1, 0, 1, 0, 0]
        b [0, 0, 0, 0, 2, 0, 0]
        a [0, 0, 0, 0, 0, 1, 0]
        b [0, 0, 0, 0, 0, 0, 0]
        a [0, 0, 0, 0, 0, 0, 0]
          [0, 0, 0, 0, 0, 0, 0]
        
        '''
        n=len(s)
        dp=[[0]*(n+1) for _ in range(n+1)]
        res=0
        for i in range(n)[::-1]:
            for j in range(i+1,n)[::-1]:
                if s[i]==s[j]:
                    dp[i][j]=1+dp[i+1][j+1]
                else:
                    dp[i][j]=0
                res=max(res, dp[i][j])
        return res
        
```
