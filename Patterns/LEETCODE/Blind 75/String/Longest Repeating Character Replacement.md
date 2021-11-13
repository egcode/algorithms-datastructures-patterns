### [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) <br>

You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

Return *the length of the longest substring containing the same letter you can get after performing the above operations*.



#### Example 1:

```
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

```

#### Example 2:

```
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

```


# Solutions

### Python
```
class Solution:
#     def characterReplacement(self, s: str, k: int) -> int:
#         '''
#         Sliding Window
#             https://youtu.be/gqXU1UyA8pk
            
#             - Count characters with hashmap
#             - Two sliding window pointers 
#             - if most sliding window has a lot of odd character shrink it by incrementing tail
            
#         The trick is here that we don't need to decrement mostFreqCharCount on tail cut
#         And we don't need to loop through our win dictionary to get most frequent character
#         '''
#         win={}
#         n=len(s)
#         res=0
        
#         mostFreqCharCount=0
        
#         start=0
#         for end in range(n):
#             win[s[end]]=1+win.get(s[end], 0)
#             mostFreqCharCount=max(mostFreqCharCount, win[s[end]])
            
#             if (end-start+1) - mostFreqCharCount > k:
#                 # cut tail
#                 win[s[start]] -= 1
#                 start += 1
                
#             res=max(res, end-start+1)
#         return res
        
    
    def characterReplacement(self, s: str, k: int) -> int:
        win={}
        res=0
        start=0
        for end in range(len(s)):
            win[s[end]]=1+win.get(s[end], 0)
            
            # cut tail 
            while (end-start+1) - max(win.values()) > k:
                win[s[start]] -= 1
                start += 1
            
            res=max(res, end-start+1)
        
        
        return res

```
