### [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/) <br>

You are given an integer array `cost` where `cost[i]` is the cost of `i`-th step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index `0`, or the step with index `1`.

Return the **minimum cost to reach the top of the floor**.



#### Example 1:

```
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

```

#### Example 2:

```
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

```

# Solutions

### Python
```
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        '''
        DP
        '''
        n=len(cost)
        dp=[0]*(n+1)
        dp[0]=cost[0]
        dp[1]=cost[1]
        
        for i in range(2, n):
            dp[i]=cost[i]+min(dp[i-1], dp[i-2])
                
        return min(dp[n-1], dp[n-2])

#     def minCostClimbingStairs(self, cost: List[int]) -> int:
#         '''
#         Recursion Eugene
#         '''        
#         n=len(cost)
#         memo={}
        
#         def dfs(i):
#             if i in memo.keys():
#                 return memo[i]
#             if i >= n:
#                 return 0
#             memo[i]=cost[i]+min(dfs(i+1), dfs(i+2))
#             return memo[i]
        
#         return min(dfs(1), dfs(0))
    
    
#     def minCostClimbingStairs(self, cost: List[int]) -> int:
#         '''
#         Recursion
#         '''
#         n=len(cost)
#         memo={}
        
#         def dfs(i):
#             # Base case, we are allowed to start at either step 0 or step 1
#             if i <= 1:
#                 return 0
            
#             if i in memo.keys():
#                 return memo[i]
            
#             one=cost[i-1]+dfs(i-1)
#             two=cost[i-2]+dfs(i-2)
#             memo[i]=min(one,two)
#             return memo[i]
        
#         return dfs(n)    
```
