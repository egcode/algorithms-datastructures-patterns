### [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/) <br>

Given two integers `dividend` and `divisor`, divide two integers **without** using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, `8.345` would be truncated to `8`, and `-2.7335` would be truncated to `-2`.

Return *the ***quotient*** after dividing `dividend` by `divisor`*.

**Note:** Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [<img src="https://render.githubusercontent.com/render/math?math=2^{31}">, <img src="https://render.githubusercontent.com/render/math?math=2^{31}"> − <img src="https://render.githubusercontent.com/render/math?math=1">]. For this problem, if the quotient is strictly greater than <img src="https://render.githubusercontent.com/render/math?math=2^{31}"> - <img src="https://render.githubusercontent.com/render/math?math=1">, then return <img src="https://render.githubusercontent.com/render/math?math=2^{31}"> - <img src="https://render.githubusercontent.com/render/math?math=1">, and if the quotient is strictly less than -<img src="https://render.githubusercontent.com/render/math?math=2^{31}">, then return -<img src="https://render.githubusercontent.com/render/math?math=2^{31}">.



#### Example 1:

```
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

```

#### Example 2:

```
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.

```

#### Example 3:

```
Input: dividend = 0, divisor = 1
Output: 0

```

#### Example 4:

```
Input: dividend = 1, divisor = 1
Output: 1

```



# Solutions

### Python
```
class Solution:
    
    def divide(self, dividend: int, divisor: int) -> int:
        # Constants.
        MAX_INT = 2147483647        # 2**31 - 1
        MIN_INT = -2147483648       # -2**31

        if dividend==0 or abs(divisor)>abs(dividend):
            return 0
        
        # Special case: overflow.
        if dividend == MIN_INT and divisor == -1:
            return MAX_INT
        
        negatives=0
        if dividend<0:
            negatives += 1
            dividend = -dividend
        if divisor<0:
            negatives += 1
            divisor = -divisor
        
        res=0
        values=[divisor]
        value=divisor
        powers=[1]
        power=1

        while value+value<dividend:
            value += value
            power += power
            values.append(value)
            powers.append(power)
        dividend -= value
        res += power
        
        
        for i in reversed(range(len(values))):
            if values[i]<=dividend:
                dividend -= values[i]
                res += powers[i]
        
        if negatives==1:
            return -res
        
        return res

```
