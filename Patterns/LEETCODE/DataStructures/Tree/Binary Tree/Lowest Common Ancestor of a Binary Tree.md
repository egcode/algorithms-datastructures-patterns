### [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) <br>

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow a **node to be a descendant of itself**).”




#### Example 1:
<img src="../../../../../images/236binarytree.png">

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

```

#### Example 2:
<img src="../../../../../images/236binarytree-1.png">

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

```

#### Example 3:

```
Input: root = [1,2], p = 1, q = 2
Output: 1

```


# Solutions

### Python
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        stack=[root]
        parent={root: None} # If we don't add root at the begining, we could have key Error
        
        while stack:
            node = stack.pop()
            if node.right:
                parent[node.right]=node
                stack.append(node.right)
            if node.left:
                parent[node.left]=node
                stack.append(node.left)
                
        ancestors = set()
        while p:
            ancestors.add(p)
            p=parent[p]
            
        while q not in ancestors:
            q=parent[q]
            
        return q
```
