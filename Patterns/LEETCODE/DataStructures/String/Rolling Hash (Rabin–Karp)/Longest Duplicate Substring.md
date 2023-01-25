### [Longest Duplicate Substring](https://leetcode.com/problems/longest-duplicate-substring/) <br>

Given a string `s`, consider all *duplicated substrings*: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.

Return **any** duplicated substring that has the longest possible length. If `s` does not have a duplicated substring, the answer is `""`.



#### Example 1:

```
Input: s = "banana"
Output: "ana"

```

#### Example 2:

```
Input: s = "abcd"
Output: ""

```


# Solutions

### Python
```
class Solution:
    def longestDupSubstring(self, s: str) -> str:
        def helper(length):
            seen = set()
            curHash = 0
            
            # d is the number of characters in the input alphabet
            d = 256            
            for i in range(length):
                curHash = (curHash * d + nums[i]) % mod
            seen.add(curHash)
            
            a = (d**length) % mod
            for i in range(length,n):
                curHash = (curHash * d + nums[i] - nums[i-length] * a) % mod
                
                if curHash in seen:
                    return i-length+1
                
                seen.add(curHash)
            return -1
        
        mod = 9023874098237409872309487
        
        n=len(s)
        l=0
        r=n-1
        res=0
        nums=[ord(c)-ord('a') for c in s]
        while l<r:
            mid=l+(r-l+1)//2
            start = helper(mid)
            if start >= 0:
                l=mid
                res=start
            else:
                r=mid-1
        return s[res:res+l]
```

