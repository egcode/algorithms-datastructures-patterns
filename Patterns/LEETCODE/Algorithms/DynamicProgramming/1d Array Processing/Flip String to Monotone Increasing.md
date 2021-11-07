### [Flip String to Monotone Increasing](https://leetcode.com/problems/flip-string-to-monotone-increasing/) <br>

A binary string is monotone increasing if it consists of some number of `0`'s (possibly none), followed by some number of `1`'s (also possibly none).

You are given a binary string `s`. You can flip `s[i]` changing it from `0` to `1` or from `1` to `0`.

Return the **minimum number of flips** *to make* `s` *monotone increasing*.


#### Example 1:

```
Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.

```

#### Example 2:

```
Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.

```

#### Example 3:

```
Input: s = "00011000"
Output: 2
Explanation: We flip to get 00000000.

```


# Solutions

### Python
```
class Solution:
#     def minFlipsMonoIncr(self, s: str) -> int:
#         '''
#         We count ones from left->right
#         and zeros from right<-left
        
#         Example:
#         s =    "0001100"
#         ones = [0000122]
#         zeros= [4322210]
#                [4322332] - combined values, and find minimum in combined
        
#         Caution we count elements behind pointer
        
#         '''
#         n=len(s)        
        
#         zeros=[0]*n
#         zero_sum=0
        
#         ones=[0]*n
#         ones_sum=0
#         i=0
#         j=n-1
#         while i<n and j>=0:
#             ones[i]=ones_sum 
#             zeros[j]=zero_sum 
#             if s[i]=='1':
#                 ones_sum += 1
#             if s[j]=='0':
#                 zero_sum += 1
            
#             i += 1
#             j -= 1
                      
#         res=float('inf')
#         for i in range(i):
#             res=min(res, zeros[i]+ones[i])
#         return res
        
        
    def minFlipsMonoIncr(self, s: str) -> int:
        '''
        Explanation above, this is space optimized version
        '''
        zeros = s.count('0')
        ones = 0
        res=zeros
                
        for i,ch in enumerate(s):
            if ch=='1':
                ones += 1
            else:
                zeros -= 1
            res=min(res, zeros+ones)            
        
        return res

```
