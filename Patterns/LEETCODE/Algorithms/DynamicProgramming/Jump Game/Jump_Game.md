### [Jump Game](https://leetcode.com/problems/jump-game/) <br>

You are given an integer array `nums`. You are initially positioned at the array's **first index**, and each element in the array represents your maximum jump length at that position.

Return `true` if you can reach the last index, or `false` otherwise.



#### Example 1:

```
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

```


#### Example 2:

```
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

```


# Solutions

### Python
```
class Solution:
#     def canJump(self, nums: List[int]) -> bool:
#         '''
#         BFS Time Limit Exceeded
        
#         '''
#         n=len(nums)
#         if n==1: return True
        
#         stack=collections.deque([0])
#         while stack:
#             i = stack.pop()
#             num=nums[i]
#             while num>0:
#                 next_index=i+num
#                 if next_index==n-1:
#                     return True
#                 if next_index<n:
#                     stack.appendleft(next_index)
#                 num -= 1
                
#         return False

    
#     def canJump(self, nums: List[int]) -> bool:
#         '''
#         DFS Time Limit Exceeded
#         '''
#         n=len(nums)
#         if n==1: return True
#         memo={}
        
#         def dfs(current):
#             if current in memo.keys():
#                 return memo[current]
            
#             if current == (n-1):
#                 memo[current]=True
#                 return True            
#             num=nums[current]
#             while num>0:
#                 next_index=current+num
#                 if next_index<n:
#                     if dfs(next_index)==True:
#                         memo[current]=True
#                         return True
#                 num -= 1

#             memo[current]=False
#             return False
        
#         return dfs(0)
        
    def canJump(self, nums: List[int]) -> bool:
        '''
        Explanation:
        https://leetcode.com/problems/jump-game/discuss/596454/Python-Simple-solution-with-thinking-process-Runtime-O(n)
        '''
        n=len(nums)
        last_index = n-1
        
        for i in range(n)[::-1]: # Iterate backwards from second to last item until the first item
            if (i+nums[i]) >= last_index: # If this index has jump count which can reach to or beyond the last position
                last_index = i # Since we just need to reach to this new index
        
        return last_index == 0

```
