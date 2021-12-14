### [Permutation in String](https://leetcode.com/problems/permutation-in-string/) <br>

Given two strings `s1` and `s2`, return `true` *if* `s2` *contains a permutation of* `s1`, *or* `false` *otherwise*.

In other words, return `true` if one of `s1`'s permutations is the substring of `s2`.




#### Example 1:

```
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

```

#### Example 2:

```
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

```

# Solutions

### Python
```
class Solution:
    
    def checkInclusion(self, s1: str, s2: str) -> bool:
        '''
        Sliding window dictionary
        '''
        if len(s1)>len(s2):
            return False
        
        dic1={}
        for l in s1:
            dic1[l]=1+dic1.get(l, 0)
            
            
        dic2={}
        for i in range(len(s2)):
            l=s2[i]
            
            # cut tail
            if i >= len(s1):
                ll=s2[i-len(s1)]
                if ll in dic2.keys():
                    if dic2[ll]==1:
                        del dic2[ll]
                    else:
                        dic2[ll] -= 1
            
            
            dic2[l]=1+dic2.get(l, 0)
            
            if dic1==dic2:
                return True
            
        return False
    
    
#     def checkInclusion(self, s1: str, s2: str) -> bool:
#         '''
#         Sliding window with array characters
#         '''
#         if len(s1)>len(s2):
#             return False
        
#         arr1=[0]*26
#         arr2=[0]*26
        
#         for l in s1:
#             arr1[ord(l)-ord('a')] += 1
            
#         for i in range(len(s2)):
#             l=s2[i]
            
#             arr2[ord(l)-ord('a')] += 1
            
#             if i >= len(s1):
#                 # cut tail
#                 arr2[ord(s2[i-len(s1)])-ord('a')] -= 1
            
#             if arr1==arr2:
#                 return True
            
#         return False
```
