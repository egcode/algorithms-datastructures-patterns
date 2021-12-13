### [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/) <br>

Given the `root` of a **complete** binary tree, return the number of the nodes in the tree.

According to [Wikipedia](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees), every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between <img src="https://render.githubusercontent.com/render/math?math=1"> and <img src="https://render.githubusercontent.com/render/math?math=2^h"> nodes inclusive at the last level `h`.

Design an algorithm that runs in less than `O(n)` time complexity.

#### Example 1:
<img src="../../../../../images/222complete.jpg">

```
Input: root = [1,2,3,4,5,6]
Output: 6

```

#### Example 2:

```
Input: root = []
Output: 0

```

#### Example 3:

```
Input: root = [1]
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


# class Solution:
#     def countNodes(self, root: TreeNode) -> int:
#         return 1+self.countNodes(root.right)+self.countNodes(root.left) if root else 0
        
        
class Solution:

    def exists(self, idx: int, d: int, node: TreeNode) -> bool:
        """
        Last level nodes are enumerated from 0 to 2**d - 1 (left -> right).
        Return True if last level node idx exists. 
        Binary search with O(d) complexity.
        """
        left = 0 
        right = 2**d - 1
        for _ in range(d):
            pivot = left + (right - left) // 2
            if idx <= pivot:
                node = node.left
                right = pivot
            else:
                node = node.right
                left = pivot + 1
        return node is not None
        
    def countNodes(self, root: TreeNode) -> int:
        # if the tree is empty
        if not root:
            return 0
        
        
        """
        Return tree depth in O(d) time.
        """
        d = 0
        node=root
        while node.left:
            node = node.left
            d += 1        
        # if the tree contains 1 node
        if d == 0:
            return 1
        
        
        # Last level nodes are enumerated from 0 to 2**d - 1 (left -> right).
        # Perform binary search to check how many nodes exist.
        left = 1
        right = 2**d - 1
        while left <= right:
            pivot = left + (right - left) // 2
            if self.exists(pivot, d, root):
                left = pivot + 1
            else:
                right = pivot - 1
        
        # The tree contains 2**d - 1 nodes on the first (d - 1) levels
        # and left nodes on the last level.
        return (2**d - 1) + left        
```
