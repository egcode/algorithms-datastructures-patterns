### [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) <br>

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?



#### Example 1:

```
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

```

#### Example 2:

```
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

```

# Solutions

### Python
```
class Solution:
    
    def climbStairs(self, n: int) -> int:
        memo={0:0,1:1,2:2}
        
        def stairs(i):
            if i in memo.keys():
                return memo[i]            
            memo[i]=stairs(i-1)+stairs(i-2)
            return memo[i]
        return stairs(n)
        

#      def climbStairs(self, n: int) -> int:
#         if n==1:
#             return 1
#         dp=[0,1,2]
        
#         for i in range(3,n+1):
#             dp.append(dp[i-1]+dp[i-2])
            
#         print(dp)
#         return dp[n]
```
