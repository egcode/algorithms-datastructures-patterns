### [Power of Two](https://leetcode.com/problems/power-of-two/) <br>

Given an integer `n`, return `true` if it is a power of two. Otherwise, return `false`.

An integer `n` is a power of two, if there exists an integer `x` such that <img src="https://render.githubusercontent.com/render/math?math=n"> == <img src="https://render.githubusercontent.com/render/math?math=2^x">.



#### Example 1:

```
Input: n = 1
Output: true
Explanation: 2^0 = 1
```

#### Example 2:

```
Input: n = 16
Output: true
Explanation: 2^4 = 16

```

#### Example 3:

```
Input: n = 3
Output: false

```

#### Example 4:

```
Input: n = 4
Output: true

```

#### Example 5:

```
Input: n = 5
Output: false

```


# Solutions

### Python
```
class Solution:
#     def isPowerOfTwo(self, n: int) -> bool:
#         '''
#         1. Power of two has just one 1-bit:
#             1 = 00000001
#             2 = 00000010
#             4 = 00000100
#             8 = 00001000
        
#         2. A number which is not a power of two, has more than one 1-bit in its binary representation:
#             3 = 00000011
#             5 = 00000101
#             6 = 00000110
#             7 = 00000111
        
        
        
#          n & (-n)   
#         keeps rightmost 1-bit and sets all other bits to 0
#         if after this operation number is the same that means that it is power of two with one 1-bit binary
         
#         '''
#         if n == 0: return False
        
#         return n & (-n) == n

    def isPowerOfTwo(self, n: int) -> bool:
        '''
        1. Power of two has just one 1-bit.
            1 = 00000001
            2 = 00000010
            4 = 00000100
            8 = 00001000
            
        n & (n-1)
        this operation removes this 1-bit
        and if number is zero that means that it's power of two number.
        '''
        if n == 0: return False        
        return n & (n-1) == 0
```
