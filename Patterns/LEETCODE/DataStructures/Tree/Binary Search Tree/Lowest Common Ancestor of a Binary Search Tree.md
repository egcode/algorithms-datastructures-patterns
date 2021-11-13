### [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) <br>


Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”


#### Example 1:
<img src="../../../../../images/235binarysearchtree_improved.png">

```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

```

#### Example 2:
<img src="../../../../../images/235binarysearchtree_improved-1.png">

```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

```

#### Example 3:

```
Input: root = [2,1], p = 2, q = 1
Output: 2

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
#     def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
#         parent={root: None}
#         stack=[root]
        
#         while stack:
#             node=stack.pop()
            
#             if node.left:
#                 stack.append(node.left)
#                 parent[node.left]=node
#             if node.right:
#                 stack.append(node.right)
#                 parent[node.right]=node
                
#         ancestors=set()
#         while p and p in parent.keys():            
#             ancestors.add(p)
#             p=parent[p]
            
#         while q not in ancestors:
#             q=parent[q]
            
#         return q
            
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':

        if p.val > root.val and q.val > root.val:    
            return self.lowestCommonAncestor(root.right, p, q)
        elif p.val < root.val and q.val < root.val:    
            return self.lowestCommonAncestor(root.left, p, q)
        else:
            return root 
```
