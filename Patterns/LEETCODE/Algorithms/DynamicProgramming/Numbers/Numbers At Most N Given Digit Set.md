### [Numbers At Most N Given Digit Set](https://leetcode.com/problems/numbers-at-most-n-given-digit-set/) <br>

Given an array of `digits` which is sorted in **non-decreasing** order. You can write numbers using each `digits[i]` as many times as we want. For example, if `digits = `['1','3','5']``, we may write numbers such as `'13'`, `'551'`, and `'1351315'`.

Return *the number of positive integers that can be generated that are less than or equal to a given integer* `n`.



#### Example 1:

```
Input: digits = ["1","3","5","7"], n = 100
Output: 20
Explanation: 
The 20 numbers that can be written are:
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.

```

#### Example 2:

```
Input: digits = ["1","4","9"], n = 1000000000
Output: 29523
Explanation: 
We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
In total, this is 29523 integers that can be written using the digits array.

```

#### Example 3:

```
Input: digits = ["7"], n = 8
Output: 1

```



# Solutions

### Python
```
class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        '''
        Example: 
            ["1","2","5","7","8","9"],  n = 4836, Output: 690
                            
            target = "4836"
            Loop1: 
                The numbers with the digitsize less than 4 are guarenteed to be less than n            
                Accumulate res = 4^1 + 4^2 + 4^3
                
            Loop2:
                The number's with the exact same digitsize 4
                 Condition1:
                    if target digit is bigger than current looped,
                    that means that we can create digit with length 4 - as target starting with current looped
                    for instance:
                        current target = 3
                        current looped = 2
                        if (2 < 3)
                            we cand add 4 ^ N-currenttarget-1
                 Condition2:
                    if target == current
                        copy from prev
        
        '''
        target = str(n)
        N=len(target)
        res=0
        
        for i in range(1, N):
            res += pow(len(digits), i)
            
        dp=[0]*N
        
        for i in range(N-1,-1,-1):
            for digit in digits:
                if target[i] > digit:
                    dp[i] += pow(len(digits), N-i-1)
                elif target[i] == digit:
                    dp[i] += dp[i+1] if i<N-1 else 1
            
        return res + dp[0]

```
