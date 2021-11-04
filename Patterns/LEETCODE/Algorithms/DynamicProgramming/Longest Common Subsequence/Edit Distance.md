### [Edit Distance](https://leetcode.com/problems/edit-distance/) <br>

Given two strings `word1` and `word2`, return the minimum number of operations required to convert `word1` to `word2`.

You have the following three operations permitted on a word:

 - Insert a character
 - Delete a character
 - Replace a character


#### Example 1:

```
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

```

#### Example 2:

```
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

```

# Solutions

### Python
```
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        '''
        Extension of 1143.Longest Common Subsequence.        
            https://www.youtube.com/watch?v=XYi2-LPrwm4&ab_channel=NeetCode
            
        Start with
           s  e  a
        e [0, 0, 0, 3], 
        a [0, 0, 0, 2], 
        t [0, 0, 0, 1], 
          [3, 2, 1, 0]]
        
        if w1[i]==w2[j]:
            (i+1, j+1)  without increment
        else:
            insert  (i, j+1)
            delete  (i+1, j)
            replace (i+1, j+1)
            
            all with one increment
        '''            
        n1=len(word1)
        n2=len(word2)
        dp=[[0]*(n2+1) for _ in range(n1+1)]
        for row in range(n1):
            dp[row][-1]=n1-(row)
        for col in range(n2):
            dp[-1][col]=n2-(col)
            
        for row in range(n1)[::-1]:
            for col in range(n2)[::-1]:
                if word1[row]==word2[col]:
                    dp[row][col]=max(dp[row][col], dp[row+1][col+1])
                else:
                    dp[row][col]=min(1+dp[row+1][col+1], 1+dp[row][col+1], 1+dp[row+1][col])
                    
        # print(dp)
        return dp[0][0]
```
