### [Basic Calculator](https://leetcode.com/problems/basic-calculator-iii/) <br>

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, `'+'`, `'-'`, `'*'`, `'/'` operators, and open `'('` and closing parentheses `')'`. The integer division should **truncate toward zero**.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-<img src="https://render.githubusercontent.com/render/math?math=2^{31}">, <img src="https://render.githubusercontent.com/render/math?math=2^{31}"> - <img src="https://render.githubusercontent.com/render/math?math=1">].

**Note:** You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as `eval()`.



#### Example 1:

```
Input: s = "1+1"
Output: 2

```

#### Example 2:

```
Input: s = "6-4/2"
Output: 4

```

#### Example 3:

```
Input: s = "2*(5+5*2)/3+(6/2+8)"
Output: 21

```

#### Example 4:

```
Input: s = "(2+6*3+5-(3*14/7+2)*5)+3"
Output: -12

```

#### Example 5:

```
Input: s = "0"
Output: 0

```


# Solutions

### Python
```
class Solution:
    def calculate(self, s: str) -> int:
        def update(op, v):
            if op == "+": stack.append(v)
            if op == "-": stack.append(-v)
            if op == "*": stack.append(stack.pop() * v)           #for BasicCalculator II and BasicCalculator III
            if op == "/": stack.append(int(stack.pop() / v))      #for BasicCalculator II and BasicCalculator III
    
        i = 0
        num = 0
        stack = []
        sign = "+"
        
        while i < len(s):
            if s[i].isdigit():
                num = num * 10 + int(s[i])
            elif s[i] in "+-*/":
                update(sign, num)
                num = 0
                sign = s[i]
            elif s[i] == "(":                                        # For BasicCalculator I and BasicCalculator III
                num, j = self.calculate(s[i + 1:])
                i = i + j
            elif s[i] == ")":                                        # For BasicCalculator I and BasicCalculator III
                update(sign, num)
                return sum(stack), i + 1
            i += 1
        update(sign, num)
        return sum(stack)

```
