### [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) <br>

Given the `root` of a binary tree, invert the tree, and return *its root*.


#### Example 1:
<img src="../../../../images/226invert1-tree.jpg">

```
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

```

#### Example 2:
<img src="../../../../images/226invert2-tree.jpg">

```
Input: root = [2,1,3]
Output: [2,3,1]

```

#### Example 3:

```
Input: root = []
Output: []

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
    def invertTree(self, root: TreeNode) -> TreeNode:
        
        if not root:
            return None
        
        r_tree = self.invertTree(root.left)
        l_tree = self.invertTree(root.right)
        root.right=r_tree
        root.left=l_tree
        
        return root
```
