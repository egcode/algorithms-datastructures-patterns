### [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/) <br>

Given two strings `s` and `t`, return the number of distinct subsequences of `s` which equals `t`.

A string's **subsequence** is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., `"ACE"` is a subsequence of `"ABCDE"` while `"AEC"` is not).

It is guaranteed the answer fits on a 32-bit signed integer.



#### Example 1:

```
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
```
<ins>**rabb**</ins>b<ins>**it**</ins>

<ins>**ra**</ins>b<ins>**bbit**</ins>

<ins>**rab**</ins>b<ins>**bit**</ins>



#### Example 2:

```
Input: s = "babsbas", t = "bas"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bas" from s.
```
<ins>**ba**</ins>b<ins>**s**</ins>bas

<ins>**ba**</ins>bsba<ins>**s**</ins>

<ins>**b**</ins>absb<ins>**as**</ins>

ba<ins>**b**</ins>sb<ins>**as**</ins>

babs<ins>**bas**</ins>

# Solutions

### Python
```
class Solution:
#     def numDistinct(self, s: str, t: str) -> int:
#         '''
#         Extension of 1143.Longest Common Subsequence.        
          
#           s=rabbbit  t=rabbit
#           if s[i]=="a" and t[j]=="" it takes 1 way to generate t from s by removin letter a,
#           if s[i]==""  and t[j]=="a" it takes 0 ways
#           if s[i]==""  and t[j]==""  it takes  1 way
          
          
#            r a b b i t 
#         r [0 0 0 0 0 0 1]
#         a [0 0 0 0 0 0 1]
#         b [0 0 0 0 0 0 1]
#         b [0 0 0 0 0 0 1]
#         b [0 0 0 0 0 0 1]
#         i [0 0 0 0 0 0 1]
#         t [0 0 0 0 0 0 1]
#           [0 0 0 0 0 0 1]
        
#         copy previous row  (i+1, j)      # continue with t[i]
#         if w1[i]==w2[j]:
#             (i+1, j+1)  add to current   # continue with t[i] and s[j]
#         '''            
        
#         h=len(s)
#         w=len(t)
        
#         dp=[[0]*(w+1) for _ in range(h+1)]
#         for row in range(h+1):
#             dp[row][-1]=1
        
#         for row in range(h)[::-1]:
#             for col in range(w)[::-1]:
#                 dp[row][col]=dp[row+1][col] 
#                 if s[row]==t[col]:
#                     dp[row][col] += dp[row+1][col+1]
#         return dp[0][0]
        
        
    def numDistinct(self, s: str, t: str) -> int:
        '''
        DFS
        
           s=rabbbit  t=rabbit
           if s[i]=="a" and t[j]=="" it takes 1 way to generate t from s by removin letter a,
           if s[i]==""  and t[j]=="a" it takes 0 ways
           if s[i]==""  and t[j]==""  it takes  1 way
        
            i source pointer
            j target ponter
        '''
        
        @lru_cache(None)
        def dfs(i, j):
            if j==len(t):
                return 1
            if i==len(s):
                return 0
            
            if s[i]==t[j]:
                # dfs(i+1, j+1) - continue same letters
                # dfs(i+1, j) -   continue same target next source
                return dfs(i+1, j+1) + dfs(i+1, j)
            else:
                return dfs(i+1, j)
            
        return dfs(0,0)
            
```
