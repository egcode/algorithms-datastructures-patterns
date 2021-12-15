### [Add Binary](https://leetcode.com/problems/add-binary/) <br>

Given two binary strings `a` and `b`, return *their sum as a binary string*.



#### Example 1:

```
Input: a = "11", b = "1"
Output: "100"

```

#### Example 2:

```
Input: a = "1010", b = "1011"
Output: "10101"

```

# Solutions

### Python
```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        carry=False
        
        res=collections.deque()
        carry=False
        p1=len(a)-1
        p2=len(b)-1
        
        while p1>=0 or p2>=0:
            d1=a[p1] if p1>=0 else '0'
            d2=b[p2] if p2>=0 else '0'
            
            # 1 1
            if d1=='1' and d2=='1':
                if carry:
                    res.appendleft('1')
                else:
                    res.appendleft('0')
                carry=True
            # 0 0        
            elif d1=='0' and d2=='0':
                if carry:
                    res.appendleft('1')
                    carry=False
                else: 
                    res.appendleft('0')
            # 1 0    
            elif d1=='1' and d2=='0' or d1=='0' or d2=='1':
                if carry: 
                    res.appendleft('0')
                else: 
                    res.appendleft('1')
            p1 -= 1
            p2 -= 1
        
        if carry:
            res.appendleft('1')
                    
                    
        return "".join(res)

```
