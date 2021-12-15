### [Pow(x, n)](https://leetcode.com/problems/powx-n/) <br>

Implement [pow(x, n)](http://www.cplusplus.com/reference/valarray/pow/), which calculates `x` raised to the power `n` (i.e., <img src="https://render.githubusercontent.com/render/math?math=x^n">).




#### Example 1:

```
Input: x = 2.00000, n = 10
Output: 1024.00000

```

#### Example 2:

```
Input: x = 2.10000, n = 3
Output: 9.26100

```

#### Example 3:

```
Input: x = 2.00000, n = -2
Output: 0.25000

```
Explanation: 

<img src="https://render.githubusercontent.com/render/math?math=2^{-2}"> = <img src="https://render.githubusercontent.com/render/math?math=1/2^2"> = <img src="https://render.githubusercontent.com/render/math?math=1/4"> = <img src="https://render.githubusercontent.com/render/math?math=0.25">

# Solutions

### Python
```
class Solution:    
    
    def myPow(self, x: float, n: int) -> float:
        
        def recurse(x, n):
            if n==1:
                return x
            half=recurse(x, n//2) 

            if n % 2 == 0:
                return half * half
            else:
                return half * half * x
        
        
        if n==0:
            return 1
        elif n>0:
            return recurse(x, n)    
        else:
            return 1/recurse(x, abs(n))   

```
