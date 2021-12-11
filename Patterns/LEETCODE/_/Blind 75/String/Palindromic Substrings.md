### [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/) <br>

Given a string `s`, return *the number of* **palindromic substrings** *in it*.

A string is a **palindrome** when it reads the same backward as forward.

A **substring** is a contiguous sequence of characters within the string.

 



#### Example 1:

```
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

```

#### Example 2:

```
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

```


# Solutions

### Python
```
class Solution:
    def countSubstrings(self, s: str) -> int:
        n=len(s)
        res=0
        
        def count(i,j):
            count=1
            while (i-1)>=0 and (j+1)<n and s[i-1]==s[j+1]:
                i -= 1
                j += 1
                count += 1
            return count
            
        for i in range(n):
            res += count(i, i)
            if i>0:
                if s[i-1]==s[i]:
                    res += count(i-1, i)
            
        return res
```
