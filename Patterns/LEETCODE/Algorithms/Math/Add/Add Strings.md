### [Add Strings](https://leetcode.com/problems/add-strings/) <br>

Given two non-negative integers, `num1` and `num2` represented as string, return *the sum of `num1` and `num2` as a string*.

You must solve the problem without using any built-in library for handling large integers (such as `BigInteger`). You must also not convert the inputs to integers directly.

 

#### Example 1:

```
Input: num1 = "11", num2 = "123"
Output: "134"

```

#### Example 2:

```
Input: num1 = "456", num2 = "77"
Output: "533"

```

#### Example 3:

```
Input: num1 = "0", num2 = "0"
Output: "0"

```


# Solutions

### Python
```
class Solution:
#     def addStrings(self, num1: str, num2: str) -> str:
#         dic={"0":0,
#             "1":1,
#             "2":2,
#             "3":3,
#             "4":4,
#             "5":5,
#             "6":6,
#             "7":7,
#             "8":8,
#             "9":9}
        
#         def int_from_string(s):
#             num=0
#             for c in s:
#                 num = num*10 + dic[c]
#             return num
        
#         return str(int_from_string(num1)+int_from_string(num2))
    
    
    def addStrings(self, num1: str, num2: str) -> str:
        dic={"0":0,
            "1":1,
            "2":2,
            "3":3,
            "4":4,
            "5":5,
            "6":6,
            "7":7,
            "8":8,
            "9":9}
        res=collections.deque([])
        p1=len(num1)-1
        p2=len(num2)-1
        carry=0
        
        while p1>=0 or p2>=0:
            d1=dic[num1[p1]] if p1>=0 else 0
            d2=dic[num2[p2]] if p2>=0 else 0
            two=d1+d2
            two += carry
            if two>9:
                carry=1
                two -= 10
            else:
                carry=0
            res.appendleft(two)
            
            p1 -= 1
            p2 -= 1
            
        if carry:
            res.appendleft(carry)
              
        return "".join([str(x) for x in res])

```
