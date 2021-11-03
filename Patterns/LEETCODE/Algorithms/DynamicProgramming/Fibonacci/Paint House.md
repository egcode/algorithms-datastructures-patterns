### [Paint House](https://leetcode.com/problems/paint-house/) <br>

There is a row of `n` houses, where each house can be painted one of three colors: red, blue, or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an `n x 3` cost matrix `costs`.

 - For example, `costs[0][0]` is the cost of painting house `0` with the color red; `costs[1][2]` is the cost of painting house 1 with color green, and so on...

 
Return the **minimum cost to paint all houses**.



#### Example 1:

```
Input: costs = [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
Minimum cost: 2 + 5 + 3 = 10.

```

#### Example 2:

```
Input: costs = [[7,6,2]]
Output: 2

```

# Solutions

### Python
```
class Solution:
#     def minCost(self, costs: List[List[int]]) -> int:
#         '''
#         DFS 
#         Top to Bottom
#         '''
#         num_houses=len(costs)
#         memo={}
        
#         def dfs(house, color):
#             if house >= num_houses:
#                  return 0
#             if (house, color) in memo.keys():
#                 return memo[(house, color)]
            
#             n1=dfs(house+1, (color+1)%3)
#             n2=dfs(house+1, (color+2)%3)

#             memo[(house, color)]=costs[house][color] + min(n1, n2)
#             return memo[(house, color)]
        
#         h1=dfs(0, 0)
#         h2=dfs(0, 1)
#         h3=dfs(0, 2)
        
#         return min(h1, h2, h3)
        
    def minCost(self, costs: List[List[int]]) -> int:
        '''
        Dynamic Programming 
        Bottom up
        '''
        h=len(costs)
        w=len(costs[0])
        dp=[[0]*w for _ in range(h)]
        dp[-1]=costs[-1]
        
        for house in range(h-1)[::-1]:
            for color in [0,1,2]:
                h1=dp[house+1][(color+1)%3]
                h2=dp[house+1][(color+2)%3]
                dp[house][color]=costs[house][color]+min(h1, h2)
        
        return min(dp[0])
```
