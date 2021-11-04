### [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/) <br>

Given an input string (`s`) and a pattern (`p`), implement wildcard pattern matching with support for `'?'` and `'*'` where:

 - `'?'` Matches any single character.
 - `'*'` Matches any sequence of characters (including the empty sequence).

The matching should cover the **entire** input string (not partial).



#### Example 1:

```
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

```

#### Example 2:

```
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

```
#### Example 3:

```
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

```

#### Example 4:

```
Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

```

#### Example 5:

```
Input: s = "acdcb", p = "a*c?b"
Output: false

```

# Solutions

### Python
```
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        '''
        Dynamic Programming        
        Explanation:
        https://www.youtube.com/watch?v=3ZDZ-N0EPV0&ab_channel=TusharRoy-CodingMadeSimple
        
        example: 
                 string: xaylmz
                pattern: x?y*z
                
        Dynamic programming 2D matrix:
        
                  0     1     2     3    4     5
                  
                        x     ?     y    *     g  - Pattern Row
                        
          0       T     F     F     F    F     F
          1   x   F     T     F     F    F     F
          2   a   F     F     T     F    F     F
          3   y   F     F     F     T    T     F
          4   l   F     F     F     F    T     F
          5   m   F     F     F     F    T     F
          6   z   F     F     F     F    T     T - Result
        
        
        '''
        arr_s=list(s)
        arr_p=[]
        
        # Remove suplicate stars from pattern
        # eg: "***adddd*****c?b" turn into  "*adddd*c?b"
        prev=None
        for i in range(len(p)):
            if prev and p[i]=='*' and prev=='*':
                continue
            arr_p.append(p[i])
            prev=p[i]    
            
        # Row: Pattern
        # Column: String
        dp = [[False for i in range(len(arr_p)+1)] for j in range(len(arr_s)+1)]
        
        
        dp[0][0]=True # Empty pattern is matched with empty string - True        
        if arr_p and arr_p[0] == '*': # Star Pattern match with empty string - True
            dp[0][1] = True
        
        for i in range(1, len(dp)):
            for j in range(1, len(dp[0])):
                if arr_p[j-1] == '?' or arr_s[i-1] == arr_p[j-1]:
                    dp[i][j] = dp[i-1][j-1] # Takes value from Diagonal in matrix
                elif arr_p[j-1] == '*':
                    if dp[i-1][j] or dp[i][j-1]:
                        dp[i][j] = True # Takes value from Left or Top in matrix       
        
        return dp[-1][-1]

```
