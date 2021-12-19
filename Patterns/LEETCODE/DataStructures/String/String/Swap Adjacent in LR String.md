### [Swap Adjacent in LR String](https://leetcode.com/problems/swap-adjacent-in-lr-string/) <br>

In a string composed of `'L'`, `'R'`, and `'X'` characters, like `"RXXLRXRXL"`, a move consists of either replacing one occurrence of `"XL"` with `"LX"`, or replacing one occurrence of `"RX"` with `"XR"`. Given the starting string `start` and the ending string `end`, return `True` if and only if there exists a sequence of moves to transform one string to the other.

 

#### Example 1:

```
Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: true
Explanation: We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX

```

#### Example 2:

```
Input: start = "X", end = "L"
Output: false

```



# Solutions

### Python
```
class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        '''
        There are three kinds of characters, ‘L’, ‘R’, ‘X’.
        Replacing XL with LX = move L to the left by one
        Replacing RX with XR = move R to the right by one
        
        Strings without X should also look the same
        
        '''
        
        if len(start) != len(end) or len(start)==1 or len(end)==1:
            return False
                        
        # check L R orders are the same
        if start.replace('X','') != end.replace('X', ''): return False
        
        n = len(start)
        L_starts = [i for i in range(n) if start[i] == 'L']
        L_ends = [i for i in range(n) if end[i] == 'L']
        
        R_starts = [i for i in range(n) if start[i] == 'R']
        R_ends = [i for i in range(n) if end[i] == 'R']
        
        for L_start, L_end in zip(L_starts, L_ends):
            # check if L go to the left
            # if L_start to L_end is right direction then return false
            if L_start < L_end:
                return False
            
        # check R positions are correct
        for R_start, R_end in zip(R_starts, R_ends):
            # check if R go to the right
            # if R_start to R_end is left direction then return false            
            if R_start > R_end:
                return False
            
        return True

```
