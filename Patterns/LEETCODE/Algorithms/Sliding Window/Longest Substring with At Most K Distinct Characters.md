### [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/) <br>

Given a string `s` and an integer `k`, return *the length of the longest substring of `s` that contains at most `k` distinct characters*.



#### Example 1:

```
Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.

```

#### Example 2:

```
Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.

```



# Solutions

### Python
```
class Solution:
#    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
#         '''
#         TLE
#         '''
#         if k==0: return 0
#         res=0
        
#         for i in range(len(s)):
#             p=i
#             counter=0
#             vis=set(s[i])
#             while p>=0 and len(vis) <= k:
#                 if s[p] not in vis and len(vis)==k:
#                     break
#                 vis.add(s[p])
#                 p -= 1
#                 counter += 1
#             res=max(res, counter)
                
#         return res

    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        '''
        Sliding window with map
        '''
        vis={}
        left=0 # Sliding window left side
        res=0
        
        for i, ch in enumerate(s):
            
            vis[ch]=1+vis.get(ch, 0)
            
            # Cut window tail
            while len(vis.keys()) > k:
                if s[left] in vis.keys():
                    if vis[s[left]]==1:
                        del vis[s[left]]
                    else:
                        vis[s[left]] -= 1
                left += 1
                
            res=max(res, i-left+1)
                
        return res

```
