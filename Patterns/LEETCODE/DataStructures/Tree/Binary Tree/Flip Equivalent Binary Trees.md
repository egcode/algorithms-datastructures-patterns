### [Flip Equivalent Binary Trees](https://leetcode.com/problems/flip-equivalent-binary-trees/) <br>

For a binary tree **T**, we can define a **flip operation** as follows: choose any node, and swap the left and right child subtrees.

A binary tree **X** is flip equivalent to a binary tree **Y** if and only if we can make **X** equal to **Y** after some number of flip operations.

Given the roots of two binary trees `root1` and `root2`, return `true` if the two trees are flip equivalent or `false` otherwise.



#### Example 1:
<img src="../../../../../images/951tree_ex.png">

```
Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.

```

#### Example 2:

```
Input: root1 = [], root2 = []
Output: true

```


#### Example 3:

```
Input: root1 = [], root2 = [1]
Output: false

```


#### Example 4:

```
Input: root1 = [0,null,1], root2 = []
Output: false

```


#### Example 5:

```
Input: root1 = [0,null,1], root2 = [0,1]
Output: true

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
    def flipEquiv(self, r1: TreeNode, r2: TreeNode) -> bool:
        
        if r1 == None and r2 == None:
            return True
        if not r1 or not r2 or r1.val != r2.val:
            return False

        return (self.flipEquiv(r1.left, r2.left) and self.flipEquiv(r1.right, r2.right) or
                self.flipEquiv(r1.left, r2.right) and self.flipEquiv(r1.right, r2.left))

```
