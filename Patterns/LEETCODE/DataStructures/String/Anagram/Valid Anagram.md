### [Valid Anagram](https://leetcode.com/problems/valid-anagram/) <br>

Given two strings `s` and `t`, return `true` *if* `t` *is an anagram of* `s`, *and* `false` *otherwise*.


#### Example 1:

```
Input: s = "anagram", t = "nagaram"
Output: true

```

#### Example 2:

```
Input: s = "rat", t = "car"
Output: false

```

# Solutions

### Python
```
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        dic={}
        for ch in s:
            dic[ch]=1+dic.get(ch, 0)
        
        for ch in t:
            if ch in dic:
                if dic[ch]>1:
                    dic[ch]=dic[ch]-1
                else:
                    del dic[ch]
        
        return len(dic)==0

```
