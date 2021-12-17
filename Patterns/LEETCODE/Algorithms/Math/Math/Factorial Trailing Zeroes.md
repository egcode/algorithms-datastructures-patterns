### [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes/) <br>

Given an integer `n`, return *the number of trailing zeroes in* `n!`.

Note that `n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1`.

 



#### Example 1:

```
Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

```

#### Example 2:

```
Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.

```

#### Example 3:

```
Input: n = 0
Output: 0

```



# Solutions

### Python
```
class Solution:
#     def trailingZeroes(self, n: int) -> int:
#         '''
#         Brute force (Accepted)
        
#         '''
#         def factorial(n):
#             return 1 if (n==0) or (n==1) else n*factorial(n-1)
#         f=factorial(n)
#         # print(f)
        
#         zeros=0
#         while f%10 == 0:
#             f //= 10
#             zeros += 1
            
#         return zeros

    def trailingZeroes(self, n: int) -> int:
        '''
        Counting factors of 5
        
        '''
        fives = 0
        for i in range(5, n + 1, 5):
            current = i
            while current % 5 == 0:
                fives += 1
                current //= 5

        return fives

```
