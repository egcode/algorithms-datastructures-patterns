### [All Possible Full Binary Trees](https://leetcode.com/problems/all-possible-full-binary-trees/) <br>

Given an integer `n`, return a *list of all possible ***full binary trees*** with `n` nodes*. Each node of each tree in the answer must have `Node.val == 0`.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in **any order**.

A **full binary tree** is a binary tree where each node has exactly `0` or `2` children.



#### Example 1:
<img src="../../../../../images/894fivetrees.png">

```
Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

```

#### Example 2:

```
Input: n = 3
Output: [[0,0,0]]

```

# Solutions

### Python
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
#     def allPossibleFBT(self, n: int) -> List[TreeNode]:
        
#         if n % 2 == 0:
#             return []
#         if n == 1:
#             return [TreeNode(0)]
        
#         ret = []
#         for i in range(2, n + 1, 2): # every second starting from second
#             left_branch = self.allPossibleFBT(i - 1)
#             right_branch = self.allPossibleFBT(n - i)
#             print("")
#             for left in left_branch:
#                 for right in right_branch:
                    
#                     node = TreeNode(0)

#                     node.left = left
#                     node.right = right
#                     ret.append(node)
#         return ret
  

    def allPossibleFBT(self, n: int) -> List[TreeNode]:
        
        if n%2 == 0:
            return []
        if n == 1:
            return [TreeNode(0)]
        
        res = []
        for i in range(1, n, 2): # every second 
            '''
                1 2 3 4 5
                e.g.     i = 1
                     n-i-1 = 3
                 2
                / \
               1   3
                  / \
                 4   5
            '''
            left_branch = self.allPossibleFBT(i)
            right_branch = self.allPossibleFBT(n - i - 1)
            
            
            for left in left_branch:
                for right in right_branch:
                    
                    node = TreeNode(0)

                    node.left = left
                    node.right = right
                    res.append(node)
        return res

```
