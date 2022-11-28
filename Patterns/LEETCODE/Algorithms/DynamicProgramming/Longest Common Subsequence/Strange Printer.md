### [Strange Printer](https://leetcode.com/problems/strange-printer/) <br>

There is a strange printer with the following two special properties:

 - The printer can only print a sequence of **the same character** each time.
 - At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string `s`, return *the minimum number of turns the printer needed to print it*.



#### Example 1:

```
Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".

```

#### Example 2:

```
Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.

```


# Solutions

### Python
```
class Solution:


    def strangePrinter(self, S):
        @cache
        def dp(i, j):
            if i > j: 
                return 0
            res = dp(i+1, j) + 1
            for k in range(i+1, j+1):
                if S[k] == S[i]:
                    res = min(res, dp(i, k-1) + dp(k+1, j))
            return res
        return dp(0, len(S) - 1)    

    
    def strangePrinter(self, s: str) -> int:
        '''
         Example: "axax"

               0   1   2   3      
               a   x   a   x
         0  a [1,  99, 99, 99]
         1  x [99, 1,  99, 99]
         2  a [99, 99, 1,  99]
         3  x [99, 99, 99, 1]

               0   1   2   3      
               a   x   a   x
         0  a [1,  2,  2,  3]
         1  x [99, 1,  2,  2]
         2  a [99, 99, 1,  2]
         3  x [99, 99, 99, 1]
        '''
        n=len(s)
        dp=[[float('inf')]*n for _ in range(n)]        
        for i in range(n):
            dp[i][i]=1            
        for length in range(1, n):
            for i in range(n-length):
                j=i+length                
                # print i-th letter separately
                dp[i][j] = dp[i+1][j] + 1
                for k in range(i+1, j+1):
                    if s[i]==s[k]:
                        dp[i][j]=min(dp[i][j], dp[i][k-1] + (dp[k+1][j] if j>k else 0))
        return dp[0][-1]

```

