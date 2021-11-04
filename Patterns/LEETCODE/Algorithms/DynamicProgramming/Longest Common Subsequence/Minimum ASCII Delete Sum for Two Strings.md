### [Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/) <br>

Given two strings `s1` and `s2`, return the lowest **ASCII** sum of deleted characters to make two strings equal.



#### Example 1:

```
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

```

#### Example 2:

```
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

```

# Solutions

### Python
```
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        '''
        72. Edit Distance - Shorter variation with DELETE and REPLACE operations 
        
        if w1[i]==w2[j]:
            (i+1, j+1)  without increment
        else:
            insert  (i, j+1)
            delete  (i+1, j)
            replace (i+1, j+1)
            
            all with one increment
        
        
        Starting with:
           e    a    t
        s  0    0    0    313
        e  0    0    0    198
        a  0    0    0    97
           314  213  116  0
           
        Ending with
              e    a    t
             [314, 213, 116, 0]
          s  [231, 332, 429, 313]
          e  [116, 217, 314, 198]
          a  [217, 116, 213, 97]
             [314, 213, 116, 0]

        '''            
        n1=len(s1)
        n2=len(s2)
        dp=[[0]*(n2+1) for _ in range(n1+1)]
        summ=0
        for row in range(n1)[::-1]:
            summ += ord(s1[row])                        
            dp[row][-1]=summ
        summ=0
        for col in range(n2)[::-1]:
            summ += ord(s2[col])            
            dp[-1][col]=summ  
            
        # for row in dp:
        #     print(row)
        # print(60*"_")
        for row in range(n1)[::-1]:
            for col in range(n2)[::-1]:                    
                if s1[row] == s2[col]:
                    dp[row][col] = dp[row+1][col+1]
                else:
                    dp[row][col] = min(dp[row+1][col]+ord(s1[row]), dp[row][col+1]+ord(s2[col]))
                    
        # for row in dp:
        #     print(row)
        return dp[0][0]
```
