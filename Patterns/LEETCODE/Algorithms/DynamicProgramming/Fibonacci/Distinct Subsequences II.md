### [Distinct Subsequences II](https://leetcode.com/problems/distinct-subsequences-ii/) <br>

Given a string s, return the number of **distinct non-empty subsequences of** `s`. Since the answer may be very large, return it **modulo** 10<sup>9</sup> + 7.

A **subsequence** of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., `"ace"` is a subsequence of `"abcde"` while `"aec"` is not.
 


#### Example 1:
```
Input: s = "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
```

#### Example 2:
```
Input: s = "aba"
Output: 6
Explanation: The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba".
```

#### Example 3:
```
Input: s = "aaa"
Output: 3
Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
```



# Solutions

### Python
```
class Solution:
    def distinctSubseqII(self, s: str) -> int:
        dp=[1]
        vis={}
        for i,ch in enumerate(s):
            dp.append(dp[-1]*2)
            if ch in vis:
                dp[-1] -= dp[vis[ch]]
            vis[ch]=i
        
        return (dp[-1]-1) % (10**9 + 7)
        
        
        
```
