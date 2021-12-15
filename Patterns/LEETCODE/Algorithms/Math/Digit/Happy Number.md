### [Happy Number](https://leetcode.com/problems/happy-number/) <br>

Write an algorithm to determine if a number `n` is happy.

A **happy number** is a number defined by the following process:

 - Starting with any positive integer, replace the number by the sum of the squares of its digits.
 - Repeat the process until the number equals 1 (where it will stay), or it **loops endlessly in a cycle** which does not include 1.
 - Those numbers for which this process **ends in 1** are happy.

*Return `true` if `n` is a happy number, and `false` if not.*



#### Example 1:

```
Input: n = 19
Output: true
```
## Explanation:

<img src="https://render.githubusercontent.com/render/math?math=1^2"> + <img src="https://render.githubusercontent.com/render/math?math=9^2"> = <img src="https://render.githubusercontent.com/render/math?math=82">

<img src="https://render.githubusercontent.com/render/math?math=8^2"> + <img src="https://render.githubusercontent.com/render/math?math=2^2"> = <img src="https://render.githubusercontent.com/render/math?math=68">

<img src="https://render.githubusercontent.com/render/math?math=6^2"> + <img src="https://render.githubusercontent.com/render/math?math=8^2"> = <img src="https://render.githubusercontent.com/render/math?math=100">

<img src="https://render.githubusercontent.com/render/math?math=1^2"> + <img src="https://render.githubusercontent.com/render/math?math=0^2"> + <img src="https://render.githubusercontent.com/render/math?math=0^2"> = <img src="https://render.githubusercontent.com/render/math?math=1">



#### Example 2:

```
Input: n = 2
Output: false

```

# Solutions

### Python
```
class Solution:
    def isHappy(self, n: int) -> bool:
        if n==1: return True
        h={}
        
        def helper(n):
            if n==1:
                return True
            if n in h.keys():
                return False
            
            h[n]=True
            
            temp=n
            new=0
            while temp>0:
                pop=temp % 10
                temp=(temp-pop)/10
                new += pop * pop  
            
            if helper(new) == True:
                return True
            return False

        
        return helper(n)

```
