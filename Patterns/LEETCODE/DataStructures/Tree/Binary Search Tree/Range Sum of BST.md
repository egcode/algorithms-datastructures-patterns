### [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/) <br>

Given the `root` node of a binary search tree and two integers `low` and `high`, return *the sum of values of all nodes with a value in the ***inclusive*** range* `[low, high]`.



#### Example 1:
<img src="../../../../../images/938bst1.jpg">

```
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

```

#### Example 2:
<img src="../../../../../images/938bst2.jpg">

```
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.

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
#     def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
#         stack=[]
#         current=root
#         res=0
#         while stack or current:
#             while current:
#                 stack.append(current)
#                 current=current.left
            
#             if stack:
#                 last=stack.pop()
#                 if low <= last.val <= high:
#                     res += last.val
#                 current=last.right
                
#         return res
    
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        res=0
        def preorder(node):
            nonlocal res
            if not node:
                return
            if low <= node.val <= high:
                res += node.val
            preorder(node.left)
            preorder(node.right)
            
        preorder(root)
        return res

```
