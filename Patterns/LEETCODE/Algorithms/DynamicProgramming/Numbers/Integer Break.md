### [Integer Break](https://leetcode.com/problems/integer-break/) <br>

Given an integer `n`, break it into the sum of `k` **positive integers**, where `k >= 2`, and maximize the product of those integers.

Return the **maximum product** you can get.

#### Example 1:

```
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

```

#### Example 2:

```
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

```

# Solutions

### Python
```
class Solution:
#     def integerBreak(self, n: int) -> int:
#         '''
#         DFS
#         '''
#         if n<2: return n
        
#         memo={}
#         def dfs(pathMult, N):            
#             if (pathMult, N) in memo.keys():
#                 return memo[(pathMult, N)]
            
#             if N==0:
#                 memo[(pathMult, N)]=pathMult
#                 return pathMult
#             if N<0:
#                 memo[(pathMult, N)]=0                
#                 return 0
#             out=0
#             for i in range(1, n+1):
#                 if i != n:
#                     d=dfs(pathMult*i, N-i)
#                     if out>d: # Here d==0 we should not proceed, overflow, N<0
#                         break
#                     else:
#                         out=d
                    
#             memo[(pathMult, N)] = out                    
#             return out
        
#         return dfs(1, n)
            
    def integerBreak(self, n: int) -> int:
        '''
        Math
        
        Factors should be less than 4
        Prove that for all integers n > 4, ( ( n-3 ) * 3 ) > n
        '''
        if n==2: return 1
        if n==3: return 2
        
        product=1
        while n>4:
            product *= 3
            n -= 3
        product *= n
        return product

```
