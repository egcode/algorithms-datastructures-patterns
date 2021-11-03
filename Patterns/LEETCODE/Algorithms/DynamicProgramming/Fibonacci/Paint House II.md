### [Paint House II](https://leetcode.com/problems/paint-house-ii/) <br>

There are a row of `n` houses, each house can be painted with one of the `k` colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an `n x k` cost matrix `costs`.

 - For example, `costs[0][0]` is the cost of painting house `0` with color `0`; `costs[1][2]` is the cost of painting house `1` with color `2`, and so on...


Return the **minimum cost to paint all houses**.

#### Example 1:

```
Input: costs = [[1,5,3],[2,9,4]]
Output: 5
Explanation:
Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5.

```

#### Example 2:

```
Input: costs = [[1,3],[2,4]]
Output: 5

```

# Solutions

### Python
```
class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        '''
        Dynamic programming 
        Tabulation
        '''
        h=len(costs)
        w=len(costs[0])
        if h==1: return min(costs[0])
        dp=[[float('inf')]*(w+1) for _ in range(h)]
        dp[-1]=costs[-1]
        for house in range(h-1)[::-1]:
            for color in range(w):
                candid_colors = dp[house+1][color+1:]+dp[house+1][:color] # exclude current index
                dp[house][color]=costs[house][color]+min(candid_colors)
        
        return min(dp[0])

```
