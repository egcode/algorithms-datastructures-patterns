### [Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/) <br>

You are given a 2D array of integers `envelopes` where `envelopes[i] = [wi, hi]` represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the L**maximum number of envelopes** *you can Russian doll* (i.e., put one inside the other).

**Note:** You cannot rotate an envelope.


#### Example 1:

```
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

```

#### Example 2:

```
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1

```

# Solutions

### Python
```
class Solution:
#     def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
#         '''
#         Time Limit Exceeded
#         '''
#         n=len(envelopes)
#         if n==0: return 0
        
#         envelopes.sort(key=lambda tup:(tup[0], tup[1]))
        
#         dp=[1]*n
#         res=1
        
#         for i in range(1,n):
#             for j in range(i):
#                 if envelopes[i][0]>envelopes[j][0] and \
#                 envelopes[i][1]>envelopes[j][1]:
#                     dp[i]=max(dp[i], 1+dp[j])
#                     res=max(res, dp[i])
        
#         return res
        
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        '''
        sort widths-ascending  heights-descending.
        width are increasing already, so we can only concentrate on heights.
        Perform regular LIS on heights.
        '''
        
        envelopes.sort(key=lambda tup:(tup[0], -tup[1]))
        dp=[]
        
        for _,h in envelopes:
            i=0
            n=len(dp)
            while i<n:
                if h<=dp[i]:
                    break
                i += 1
            if i==n:
                dp.append(h)
            else:
                dp[i]=h
        
        return len(dp)

```
