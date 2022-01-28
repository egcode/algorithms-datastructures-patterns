### [Find the Derangement of An Array](https://leetcode.com/problems/find-the-derangement-of-an-array/) <br>

In combinatorial mathematics, a **derangement** is a permutation of the elements of a set, such that no element appears in its original position.

You are given an integer `n`. There is originally an array consisting of `n` integers from `1` to `n` in ascending order, return *the number of ***derangements*** it can generate*. Since the answer may be huge, return it **modulo** <img src="https://render.githubusercontent.com/render/math?math=10^9"> + <img src="https://render.githubusercontent.com/render/math?math=7">.



#### Example 1:

```
Input: n = 3
Output: 2
Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].

```

#### Example 2:

```
Input: n = 2
Output: 1

```



# Solutions

### Python
```
class Solution:
    def findDerangement(self, n: int) -> int:
        '''    
        Derangement formula:
            dp[i] = (i-1) * dp[i-1]+dp[i-2]
            
        (i-1) - Then let's think about value n, we know it can not be put on index n, instead, it can be put on index 1 to n-1, so there are n-1 possibilities.
            
    For each of the situation above, let's say value n is put on index i, 
        then we need to discuss about where we put value i:
    1.if value i is put on index n (looks like value i and value n swapped their positions), 
        then we can just ignore value i, value n, index i, index n, 
        what's left are n-2 different values and n-2 different indexes, the problem becomes D(n-2).
        
    2.if value i is not put on index n, then we can only ignore value n and index i, 
    what's left are n-1 different values and n-1 different indexes, each value has an 
    index that it can not be put on. (value i can not be put on index n here) 
    So the problem becomes D(n-1).

        Derangement formula:
         D(n) = (n-1) [D(n-2) + D(n-1)].
        '''
        
        if n<=1: return 0
        dp=[0 for i in range(n+1)]
        dp[2]=1
        for i in range(3,n+1):
            dp[i]=(i-1) * (dp[i-1]+dp[i-2]) % 1000000007
        
        return dp[-1]

```
