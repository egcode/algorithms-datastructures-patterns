### [Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/) <br>

You are given a string `s`. You can convert `s` to a palindrome by adding characters in front of it.

Return *the shortest palindrome you can find by performing this transformation*.



#### Example 1:

```
Input: s = "aacecaaa"
Output: "aaacecaaa"

```

#### Example 2:

```
Input: s = "abcd"
Output: "dcbabcd"

```



# Solutions

### Python
```
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        '''
        Idea here is to find SYMMETRIC part using reversed string
        1. Reverse original string
        2. remove from original-end reversed-start and compare
        3. return clipped reverse + original string
        
        
          s          dedcba
          r[0:]      abcded    Nope...
          r[1:]   (a)bcded     Nope...
          r[2:]  (ab)cded      Nope...
          r[3:] (abc)ded       Yes! Return abc + dedcba
        
        '''
        n=len(s)
        rev=s[::-1]
        for i in range(n):
            # print("  s[:n-i]:"+str(s[:n-i]) + "   rev[i:]:"+str( rev[i:]))
            if s[:n-i] == rev[i:]:
                # print("  rev[:i]: "+str(rev[:i]))
                return rev[:i] + s
            
        return ""

```
