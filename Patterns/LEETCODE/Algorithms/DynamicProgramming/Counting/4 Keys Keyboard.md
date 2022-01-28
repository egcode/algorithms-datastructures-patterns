### [4 Keys Keyboard](https://leetcode.com/problems/4-keys-keyboard/) <br>

Imagine you have a special keyboard with the following keys:

 - A: Print one `'A'` on the screen.
 - Ctrl-A: Select the whole screen.
 - Ctrl-C: Copy selection to buffer.
 - Ctrl-V: Print buffer on screen appending it after what has already been printed.

Given an integer n, return *the maximum number of `'A'` you can print on the screen with ***at most*** `n` presses on the keys*.



#### Example 1:

```
Input: n = 3
Output: 3
Explanation: We can at most get 3 A's on screen by pressing the following key sequence:
A, A, A

```

#### Example 2:

```
Input: n = 7
Output: 9
Explanation: We can at most get 9 A's on screen by pressing following key sequence:
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V

```



# Solutions

### Python
```
class Solution:
    def maxA(self, n: int) -> int:
        '''              
        Tabulation
            Example: n=7

        Start with:
            [0, 1, 2, 3, 4, 5, 6, 7]
                         2  4  6  8   
                            4  6  8   
                               6  9   max
                                  8
        End with:
            [0, 1, 2, 3, 4, 5, 6, 9]
            
        
        Idea here take `i-3`-th element 
        and accumulate it i..n+1 times and compare with original
        [1,2,3,4,5] array
        
        '''
        
        dp=[i for i in range(n+1)]
        for i in range(4,n+1):
            acc=dp[i-3]
            for j in range(i,n+1):
                acc += dp[i-3]
                dp[j]=max(dp[j], acc)
        return dp[-1]

```
