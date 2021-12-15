### [Reverse Integer](https://leetcode.com/problems/reverse-integer/) <br>

Given a signed 32-bit integer `x`, return `x` *with its digits reversed*. If reversing `x` causes the value to go outside the signed 32-bit integer range [-<img src="https://render.githubusercontent.com/render/math?math=2^{31}">, <img src="https://render.githubusercontent.com/render/math?math=2^{31}"> - <img src="https://render.githubusercontent.com/render/math?math=1">], then return `0`.

**Assume the environment does not allow you to store 64-bit integers (signed or unsigned)**.



#### Example 1:

```
Input: x = 123
Output: 321

```

#### Example 2:

```
Input: x = -123
Output: -321

```


#### Example 3:

```
Input: x = 120
Output: 21

```

#### Example 4:

```
Input: x = 0
Output: 0

```


# Solutions

### Python
```
class Solution:
    def reverse(self, x: int) -> int:
        import math
        
        ans=0
        tmp=abs(x)
        while tmp>0:
            pop=tmp % 10
            tmp=tmp//10
            
            ans=ans*10+pop
            
        exp=math.pow(2, 31)-1
        if ans<-exp or ans>exp-1:
            return 0

        if x<0: 
            ans *= (-1)
        return ans

```
