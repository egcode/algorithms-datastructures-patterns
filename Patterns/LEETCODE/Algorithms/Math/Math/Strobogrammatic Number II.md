### [Strobogrammatic Number II](https_problem_link) <br>

Given an integer `n`, return all the **strobogrammatic numbers** that are of length `n`. You may return the answer in **any order**.

A **strobogrammatic number** is a number that looks the same when rotated `180` degrees (looked at upside down).



#### Example 1:

```
Input: n = 2
Output: ["11","69","88","96"]

```

#### Example 2:

```
Input: n = 1
Output: ["0","1","8"]

```



# Solutions

### Python
```
class Solution:
    def findStrobogrammatic(self, n: int) -> List[str]:
        res=[]
        if n%2 == 0:
            res=['']
        else:
            res=['0', '1', '8']

        for _ in range(n//2):
            temp = []
            for num in res:
                temp.append('1' + num + '1')
                temp.append('8' + num + '8')                
                temp.append('6' + num + '9')                
                temp.append('9' + num + '6')
                
                if len(num) < n-2:
                    temp.append('0' + num + '0')
            res = temp

        return res
    

```
