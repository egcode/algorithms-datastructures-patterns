### [Triangle](https://leetcode.com/problems/triangle/) <br>

Given a `triangle array`, return the **minimum path sum from top to bottom**.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index `i` on the current row, you may move to either index `i` or index `i + 1` on the next row.



#### Example 1:

```
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11.

```


#### Example 2:

```
Input: triangle = [[-10]]
Output: -10
```


# Solutions

### Python
```
class Solution:
#     def minimumTotal(self, triangle: List[List[int]]) -> int:
#         n=len(triangle)
        
#         @cache
#         def dfs(r, c):
#             if r==n:
#                 return 0
#             left=triangle[r][c]+dfs(r+1, c)
#             right=sys.maxsize
#             if c<len(triangle[r])-1:
#                 right=triangle[r][c+1]+dfs(r+1, c+1)
#             return min(left, right)
        
#         return dfs(0, 0)
    
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n=len(triangle)
        memo={}
        
        def dfs(r, c):
            if (r,c) in memo.keys():
                return memo[(r,c)]
            if r==n:
                return 0
            left=triangle[r][c]+dfs(r+1, c)
            right=sys.maxsize
            if c<len(triangle[r])-1:
                right=triangle[r][c+1]+dfs(r+1, c+1)
                
            memo[(r,c)]=min(left,right)
            return memo[(r,c)]
        
        return dfs(0, 0)    
```
