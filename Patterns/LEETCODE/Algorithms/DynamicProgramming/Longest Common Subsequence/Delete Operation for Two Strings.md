### [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings/) <br>

Given two strings `word1` and `word2`, return the minimum number of **steps** required to make `word1` and `word2` the same.

In one **step**, you can delete exactly one character in either string.



#### Example 1:

```
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

```

#### Example 2:

```
Input: word1 = "leetcode", word2 = "etco"
Output: 4

```

# Solutions

### Python
```
class Solution:
#     def minDistance(self, word1: str, word2: str) -> int:
#         '''
#         Same as 1143.Longest Common Subsequence
        
#         after we found LCS     Result = len(word1) + len(word2) -(LCS * 2)

#            s  e  a
#         e [2, 2, 1, 0], 
#         a [1, 1, 1, 0], 
#         t [0, 0, 0, 0], 
#           [0, 0, 0, 0]]

#         '''            
#         n1=len(word1)
#         n2=len(word2)
#         dp=[[0]*(n1+1) for _ in range(n2+1)]
        
#         # Find LCS
#         for row in range(n2)[::-1]:
#             for col in range(n1)[::-1]:
#                 if word1[col] == word2[row]:
#                     dp[row][col]=max(dp[row][col], 1+dp[row+1][col+1])
#                 else:
#                     dp[row][col]=max(dp[row][col], dp[row+1][col], dp[row][col+1])
                    
#         # print(dp)   
#         return (n1+n2) - (dp[0][0]*2) # Result = len(word1) + len(word2) -(LCS * 2)
    
    def minDistance(self, word1: str, word2: str) -> int:
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
           s  e  a
        e  0  0  0  3
        a  0  0  0  2
        t  0  0  0  1
           3  2  1  0
           
        Ending with
           s  e  a
        e  2  3  4  3
        a  1  2  3  2
        t  2  1  2  1
           3  2  1  0
        Result dp[0][0]=2

        '''            
        n1=len(word1)
        n2=len(word2)
        dp=[[0]*(n2+1) for _ in range(n1+1)]
        for row in range(n1):
            dp[row][-1]=n1-row
        for col in range(n2):
            dp[-1][col]=n2-col        
        # for row in dp:
        #     print(row)            
            
        for row in range(n1)[::-1]:
            for col in range(n2)[::-1]:                    
                if word1[row] == word2[col]:
                    dp[row][col]=dp[row+1][col+1]
                else:
                    dp[row][col]=1+min(dp[row+1][col], dp[row][col+1])
             
        # print("   ")
        # for row in dp:
        #     print(row)
        return dp[0][0]

```
