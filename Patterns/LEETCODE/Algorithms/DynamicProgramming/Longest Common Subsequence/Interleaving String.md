### [Interleaving String](https://leetcode.com/problems/interleaving-string/) <br>

Given strings `s1`, `s2`, and `s3`, find whether `s3` is formed by an **interleaving** of `s1` and `s2`.

An **interleaving** of two strings s and t is a configuration where they are divided into **non-empty** substrings such that:

 - <img src="https://render.githubusercontent.com/render/math?math=s"> = <img src="https://render.githubusercontent.com/render/math?math=s_1"> + <img src="https://render.githubusercontent.com/render/math?math=s_2"> + ... + <img src="https://render.githubusercontent.com/render/math?math=s_n">
 - <img src="https://render.githubusercontent.com/render/math?math=t"> = <img src="https://render.githubusercontent.com/render/math?math=t_1"> + <img src="https://render.githubusercontent.com/render/math?math=t_2"> + ... + <img src="https://render.githubusercontent.com/render/math?math=t_m">
 - `|n - m| <= 1`
 - The **interleaving** is <img src="https://render.githubusercontent.com/render/math?math=s_1"> + <img src="https://render.githubusercontent.com/render/math?math=t_1"> + <img src="https://render.githubusercontent.com/render/math?math=s_2"> + <img src="https://render.githubusercontent.com/render/math?math=t_2"> + <img src="https://render.githubusercontent.com/render/math?math=s_3"> + <img src="https://render.githubusercontent.com/render/math?math=t_3"> + ... or <img src="https://render.githubusercontent.com/render/math?math=t_1"> + <img src="https://render.githubusercontent.com/render/math?math=s_1"> + <img src="https://render.githubusercontent.com/render/math?math=t_2"> + <img src="https://render.githubusercontent.com/render/math?math=s_2"> + <img src="https://render.githubusercontent.com/render/math?math=t_3"> + <img src="https://render.githubusercontent.com/render/math?math=s_3"> + ...

**Note:** `a + b` is the concatenation of strings `a` and `b`.


#### Example 1:
<img src="../../../../../images/97interleave.jpg">

```
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

```

#### Example 2:

```
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false

```

#### Example 3:

```
Input: s1 = "", s2 = "", s3 = ""
Output: true

```



# Solutions

### Python
```
class Solution:
#     def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
#         if len(s1)+len(s2) != len(s3): return False
#         n=len(s1)
#         m=len(s2)
        
#         @lru_cache(None)
#         def dfs(i, j):
#             if i==n and j==m:
#                 return True
            
#             out=False
#             if i<n and s1[i]==s3[i+j]:
#                 if dfs(i+1, j)==True:
#                     return True
#             if j<m and s2[j]==s3[i+j]:
#                 if dfs(i, j+1)==True:
#                     return True
            
#             return out
        
#         return dfs(0, 0)

    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        '''
        Tabulation
        Example:
                s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
                
        Start With:
               d      b      b      c      a
            a [False, False, False, False, False, False]
            a [False, False, False, False, False, False]
            b [False, False, False, False, False, False]
            c [False, False, False, False, False, False]
            c [False, False, False, False, False, False]
              [False, False, False, False, False, True]
              
        End with:
               d      b      b      c      a
            a [True,  False, False, False, False, False]
            a [True,  False, False, False, False, False]
            b [True,  True,  True,  True,  True,  False]
            c [False, True,  True,  False, True,  False]
            c [False, False, True,  True,  True,  True]
              [False, False, False, False, False, True]
        
        '''
        h=len(s1)
        w=len(s2)
        if h+w != len(s3): return False
        
        dp=[[False]*(w+1) for _ in range(h+1)]
        dp[-1][-1]=True        
        
        for r in range(h+1)[::-1]:
            for c in range(w+1)[::-1]:
                if r<h and s1[r]==s3[r+c] and dp[r+1][c]:
                    dp[r][c]=True
                if c<w and s2[c]==s3[r+c] and dp[r][c+1]:
                    dp[r][c]=True 
                            
        return dp[0][0]

```
