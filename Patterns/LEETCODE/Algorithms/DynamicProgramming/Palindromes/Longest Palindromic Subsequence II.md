### [Longest Palindromic Subsequence II](https://leetcode.com/problems/longest-palindromic-subsequence-ii/) <br>

A subsequence of a string `s` is considered a **good palindromic subsequence** if:

 - It is a subsequence of `s`.
 - It is a palindrome (has the same value if reversed).
 - It has an `even` length.
 - No two consecutive characters are equal, except the two middle ones.

For example, if `s = "abcabcabb"`, then `"abba"` is considered a **good palindromic subsequence**, while `"bcb"` (not even length) and `"bbbb"` (has equal consecutive characters) are not.

Given a string `s`, return *the ***length*** of the ***longest good palindromic subsequence*** in `s`*.



#### Example 1:

```
Input: s = "bbabab"
Output: 4
Explanation: The longest good palindromic subsequence of s is "baab".

```

#### Example 2:

```
Input: s = "dcbccacdb"
Output: 4
Explanation: The longest good palindromic subsequence of s is "dccd".

```


# Solutions

### Python
```
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        
        @lru_cache(None)
        def dp(l, r, prev):
            if l >= r: return 0 # we shouldn't use same character twice
            
            if s[l] == s[r] and s[l] != prev:
                return dp(l+1, r-1, s[l]) + 2
            return max(dp(l, r-1, prev), dp(l+1, r, prev))
        
        res=dp(0, n-1, '')    
        dp.cache_clear()
        return res

```
