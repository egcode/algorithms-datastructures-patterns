### [Multiply Strings](https://leetcode.com/problems/multiply-strings/) <br>

Given two non-negative integers `num1` and `num2` represented as strings, return the product of `num1` and `num2`, also represented as a string.

**Note:** You must not use any built-in BigInteger library or convert the inputs to integer directly.



#### Example 1:

```
Input: num1 = "2", num2 = "3"
Output: "6"

```

#### Example 2:

```
Input: num1 = "123", num2 = "456"
Output: "56088"

```


# Solutions

### Python
```
class Solution:
    
#     def multiply(self, num1: str, num2: str) -> str:
#         res=0
        
#         for i, d1 in enumerate(reversed(num2)):
            
#             tmp=collections.deque([0]*i)
#             carry=0
#             for d2 in reversed(num1):
#                 mul=int(d1)*int(d2)
#                 mul += carry
#                 carry=0
#                 if mul > 9:
#                     carry=mul//10
#                     mul %= 10
#                 tmp.appendleft(mul)
#             if carry:
#                 tmp.appendleft(carry)
#             # print(tmp)
#             # tmp to int
#             digit=0
#             for num in tmp:
#                 digit=digit*10+num
#             res += digit
            
#         return str(res)
  
    def multiply(self, num1: str, num2: str) -> str:
        def to_int(s):
            digit=0
            for ch in s:
                digit=digit*10+int(ch)
            return digit
        
        n1=to_int(num1)
        n2=to_int(num2)
        
        return str(n1*n2)

```
