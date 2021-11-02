### [Jump Game II](https://leetcode.com/problems/jump-game-ii/) <br>

Given an array of non-negative integers `nums`, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.


#### Example 1:

```
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

```


#### Example 2:

```
Input: nums = [2,3,0,1,4]
Output: 2

```


# Solutions

### Python
```
class Solution:
#     def jump(self, nums: List[int]) -> int:
#         '''
#         BFS
#         Time Limit Exceeded
#         '''
#         n=len(nums)
#         if n<2: return 0
#         q=collections.deque([(0, 0)])
#         res=0
#         nextIndex=0
#         while q:
#             size=len(q)
#             while size>0:
#                 ind, path = q.pop()
                                        
#                 nextIndex=max(nextIndex,  nums[ind]+ind)
#                 if nextIndex>=(n-1):
#                     return res+1

#                 if nextIndex<n:
#                     q.appendleft((nextIndex, path+1))
                    
#                 size -= 1
#             res += 1   
#         return res
    
    def jump(self, nums: List[int]) -> int:
        '''
        1. currentPos = n-1
        2. Find left most position that can reach current position
        3. Stop on zero.
        Image:
            https://assets.leetcode.com/users/windliang/image_1550475133.png
        
        
        Explanation in Comments:
            https://leetcode.com/problems/jump-game-ii/discuss/18028/O(n)-BFS-solution
        '''
        n=len(nums)
        currentPos=n-1
        leftMost=n-1
        
        steps=0
        while currentPos > 0:
            for i in range(currentPos):
                if nums[i]+i >= currentPos:
                    leftMost=min(leftMost, i)
            steps += 1
            currentPos=leftMost
        
        return steps
    

```
