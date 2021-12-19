### [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/) <br>

Given two strings `s` and `p`, return *an array of all the start indices of `p`'s anagrams in `s`. You may return the answer in **any order***.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



#### Example 1:

```
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

```

#### Example 2:

```
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

```



# Solutions

### Python
```
class Solution:
#     def findAnagrams(self, s: str, p: str) -> List[int]:
#          '''
#          Slow
#          '''
#         res=[]
#         ss=sorted(p)
        
#         for i in range(0, len(s)-len(p)+1):
            
#             if sorted(s[i:i+len(p)])==ss:
#                 res.append(i)            
        
#         return res
    
#     def findAnagrams(self, s: str, p: str) -> List[int]:
#         '''
#         Compare Hashmaps
#         '''
#         res=[]
        
#         p_count=collections.Counter(p)
#         s_count=collections.Counter()
        
#         for i in range(len(s)):
#             s_count[s[i]] += 1
            
#             if i >= len(p):
#                 if s_count[s[i-len(p)]]==1:
#                     del s_count[s[i-len(p)]]
#                 else:
#                     s_count[s[i-len(p)]] -= 1
            
#             if s_count==p_count:
#                 res.append(i-len(p)+1)
            
            
        
#         return res
    
    
    
    def findAnagrams(self, s: str, p: str) -> List[int]:
        '''
        Awesome Sliding window with array Method.
        '''
        ns, np = len(s), len(p)
        if ns < np:
            return []

        p_count, s_count = [0] * 26, [0] * 26
        # build reference array using string p
        for ch in p:
            p_count[ord(ch) - ord('a')] += 1
        
        output = []
        # sliding window on the string s
        for i in range(ns):
            # add one more letter 
            # on the right side of the window
            s_count[ord(s[i]) - ord('a')] += 1
            # remove one letter 
            # from the left side of the window
            if i >= np:
                s_count[ord(s[i - np]) - ord('a')] -= 1
            # compare array in the sliding window
            # with the reference array
            if p_count == s_count:
                output.append(i - np + 1)
        
        return output    

```
