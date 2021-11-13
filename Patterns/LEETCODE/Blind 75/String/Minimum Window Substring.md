### [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) <br>

Given two strings `s` and `t` of lengths `m` and `n` respectively, *return the* **minimum window substring** *of* `s` *such that every character in* `t` (**including duplicates**) *is included in the window. If there is no such substring, return the empty string* `""`.

The testcases will be generated such that the answer is **unique**.

A **substring** is a contiguous sequence of characters within the string.

 


#### Example 1:

```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

```

#### Example 2:

```
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

```

#### Example 3:

```
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

```


# Solutions

### Python
```
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        '''
        Compare letter counts in 
        target hash and window map 
        '''
        if not t:
            return ""
        
        # target hash
        target_H={}
        for l in t:
            target_H[l]=1+target_H.get(l, 0)
        need=len(target_H.items())
            
        # window hash
        window_H={}
        win_count=0
        
        # with win_min we count amount of equal letter counts in both maps
        win_min=sys.maxsize
        indexes=[-1,-1]
        
        # left is the left window bound.
        left=0
        for right in range(len(s)):
            ch=s[right]
            
            window_H[ch]=1+window_H.get(ch,0)
            if ch in target_H.keys() and window_H[ch]==target_H[ch]:
                win_count += 1
            
            # here we shrink window from left 
            while win_count==need:
                if (right-left+1)<win_min:
                    win_min=right-left+1
                    indexes=[left, right]
                    
                window_H[s[left]] -= 1
                if s[left] in target_H.keys() and window_H[s[left]] < target_H[s[left]]:
                    win_count -= 1
            
                left += 1
                
        if win_min == sys.maxsize:
            return ""
        else:
            return s[indexes[0]: indexes[1]+1]

```
