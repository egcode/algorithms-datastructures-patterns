### [Dungeon Game](https://leetcode.com/problems/dungeon-game/) <br>

The demons had captured the princess and imprisoned her in **the bottom-right corner** of a `dungeon`. The `dungeon` consists of `m x n` rooms laid out in a 2D grid. Our valiant knight was initially positioned in the **top-left room** and must fight his way through `dungeon` to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to `0` or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

To reach the princess as quickly as possible, the knight decides to move only **rightward** or **downward** in each step.

Return the **knight's minimum initial health** *so that he can rescue the princess*.

**Note** that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.



#### Example 1:
<img src="../../../../../images/dungeon-grid-1.jpg">

```
Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
Output: 7
Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.

```

#### Example 2:

```
Input: dungeon = [[0]]
Output: 1

```

# Solutions

### Python
```
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        '''
        Recursion
        '''
        if not dungeon: return 0
        
        h=len(dungeon)
        w=len(dungeon[0])
        
        @cache
        def dfs(row, col):
            if row==h or col==w:
                return float('inf')
            
            if row == h-1 and col == w-1:
                if dungeon[row][col] <= 0:
                    return abs(dungeon[row][col])+1
                else:
                    return 1
            
            go_right = dfs(row, col+1)
            go_down = dfs(row+1, col)
            
            min_health_required = min(go_right, go_down)-dungeon[row][col]

            if min_health_required <= 0:
                return 1
            return min_health_required
        
        return dfs(0,0)
    
    
#     def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
#         '''
#         Tabulation
#         '''
#         if not dungeon: return 0
#         h=len(dungeon)
#         w=len(dungeon[0])
        
#         dp=[[float('inf')]*(w+1) for i in range(h+1)]
#         dp[h-1][w]=1
#         dp[h][w-1]=1
        
#         for i in range(h)[::-1]:
#             for j in range(w)[::-1]:
                
#                 need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];   
                
#                 # store this value
#                 dp[i][j] = need                
#                 if need <= 0:
#                     dp[i][j] = 1
                                        
#         return dp[0][0]

```
