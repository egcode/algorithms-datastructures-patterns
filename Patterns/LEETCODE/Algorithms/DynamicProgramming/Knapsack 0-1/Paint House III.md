### [Paint House III](https://leetcode.com/problems/paint-house-iii/) <br>

There is a row of `m` houses in a small city, each house must be painted with one of the `n` colors (labeled from `1` to `n`), some houses that have been painted last summer should not be painted again.

A neighborhood is a maximal group of continuous houses that are painted with the same color.

 - For example: `houses = [1,2,2,3,3,2,1,1]` contains `5` neighborhoods `[{1}, {2,2}, {3,3}, {2}, {1,1}]`.


Given an array `houses`, an `m x n` matrix `cost` and an integer `target` where:

 - `houses[i]`: is the color of the house `i`, and `0` if the house is not painted yet.
 - `cost[i][j]`: is the cost of paint the house `i` with the color `j + 1`.


Return the minimum cost of painting all *the remaining houses in such a way that there are exactly* `target` *neighborhoods*. If it is not possible, return `-1`.




#### Example 1:

```
Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
Output: 9
Explanation: Paint houses of this way [1,2,2,1,1]
This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].
Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.

```

#### Example 2:

```
Input: houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
Output: 11
Explanation: Some houses are already painted, Paint the houses of this way [2,2,1,2,2]
This array contains target = 3 neighborhoods, [{2,2}, {1}, {2,2}]. 
Cost of paint the first and last house (10 + 1) = 11.

```

#### Example 3:

```
Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[1,10],[10,1],[1,10]], m = 5, n = 2, target = 5
Output: 5

```

#### Example 4:

```
Input: houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3
Output: -1
Explanation: Houses are already painted with a total of 4 neighborhoods [{3},{1},{2},{3}] different of target = 3.

```

# Solutions

### Python
```
class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        '''
        Memoization
        i=current house
        j=previous color
        k=neighborhoods formed
        '''

        @lru_cache(None)
        def dfs(i,j,k):
            
            # we reached more heighborhoods than needed
            if k>target:
                return float('inf')
            
            # walked all houses
            if i==len(houses):
                if k==target: # reached target
                    return 0
                else:
                    return float('inf')
                
            if houses[i] != 0: # house already painted
                return dfs(i+1, houses[i], k+(houses[i] != j))
            
            res=float('inf')
            # Try every color
            for color ,price in enumerate(cost[i], 1): ## enumerate from 1
                res=min(res, price+dfs(i+1, color, k+(color != j)))
            return res
        
        out=dfs(0, 0, 0)
        if out == float('inf'):
            return -1
        return out
    
```
