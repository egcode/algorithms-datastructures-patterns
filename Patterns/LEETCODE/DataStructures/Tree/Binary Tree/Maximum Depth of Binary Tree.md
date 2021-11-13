### [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) <br>

Given the `root` of a binary tree, return its *maximum depth*.

A binary tree's **maximum depth** is the number of nodes along the longest path from the root node down to the farthest leaf node.


#### Example 1:
<img src="../../../../../images/104tmp-tree.jpg">

```
Input: root = [3,9,20,null,null,15,7]
Output: 3

```

#### Example 2:

```
Input: root = [1,null,2]
Output: 2

```


#### Example 3:

```
Input: root = []
Output: 0

```


#### Example 4:

```
Input: root = [0]
Output: 1

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
    
#     def maxDepth(self, root: TreeNode) -> int:
#         queue=[root]
#         depth=0
#         while queue:
#             size=len(queue)
#             while size > 0:
#                 last=queue.pop()
#                 if last:
#                     queue.insert(0, last.right)
#                     queue.insert(0, last.left)

#                 size -= 1
#             if queue:
#                 depth += 1
            
#         return depth
     
    
        
    
    def maxDepth(self, root: TreeNode) -> int: 
        if not root:
            return 0
        print("val:"+str(root.val))
        ld, rd = 0, 0
        ld=self.maxDepth(root.right)+1
        rd=self.maxDepth(root.left)+1
        return max(ld,rd)

```
