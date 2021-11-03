### [Ugly Number II](https://leetcode.com/problems/ugly-number-ii/) <br>

An **ugly number** is a positive integer whose prime factors are limited to `2`, `3`, and `5`.

Given an integer `n`, return the `n`-th **ugly number**.



#### Example 1:

```
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

```

#### Example 2:

```
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

```

# Solutions

### Python
```
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp=[0]*n
        dp[0]=1
        p2,p3,p5 = 0, 0, 0
        
        for i in range(1, n):
            dp[i]=min(dp[p2]*2, dp[p3]*3, dp[p5]*5)
            
            if dp[i]==dp[p2]*2:
                p2 += 1
            if dp[i]==dp[p3]*3:
                p3 += 1
            if dp[i]==dp[p5]*5:
                p5 += 1 
            
        # print(dp)
        return dp[n-1]
```
