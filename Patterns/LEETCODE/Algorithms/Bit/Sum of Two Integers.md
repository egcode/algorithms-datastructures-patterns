### [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) <br>

Given two integers `a` and `b`, return *the sum of the two integers without using the operators* `+` *and* `-`.




#### Example 1:

```
Input: a = 1, b = 2
Output: 3

```

#### Example 2:

```
Input: a = 2, b = 3
Output: 5

```

# Solutions

### Python
```
class Solution:
    def getSum(self, a: int, b: int) -> int:
            mask = 0xffffffff
            while b != 0:
                carry = (a & b) << 1
                a = (a ^ b) & mask
                b = carry & mask
            if a > mask // 2:
                return ~(a ^ mask)
            else:
                return a
```
