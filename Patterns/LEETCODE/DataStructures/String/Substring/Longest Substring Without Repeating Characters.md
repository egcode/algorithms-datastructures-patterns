### [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) <br>

Given a string `s`, find the length of the **longest substring** without repeating characters.




#### Example 1:

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

```

#### Example 2:

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

```

#### Example 3:

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

```

#### Example 4:

```
Input: s = ""
Output: 0

```


# Solutions

### Python
```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        '''
        Sliding Window
        '''
        dic={}
        slow=0
        res=0
        
        for i in range(len(s)):
            l=s[i]
            
            while l in dic.keys():
                if dic[s[slow]]==1:
                    del dic[s[slow]]
                else:
                    dic[s[slow]] -= 1
                slow += 1
            
            
            dic[l]=1+dic.get(l, 0)
            res=max(res, i-slow+1)
            
        return res
    
    
    
#     def lengthOfLongestSubstring(self, s: str) -> int:
#         '''
#         Sliding Window with indexes
#         '''
#         dic={}
#         res=0
#         slow=0
        
#         for i in range(len(s)):
#             l=s[i]
            
#             if l in dic.keys():
#                 slow = max(dic[l], slow)
                
#             res=max(res, i-slow+1)
#             dic[l]=i+1 # save shifted indexes

#         return res

```
