### [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) <br>

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return the *binary tree*.



#### Example 1:
<img src="../../../../../images/105tree.jpg">

```
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

```

#### Example 2:

```
Input: preorder = [-1], inorder = [-1]
Output: [-1]

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
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        '''
        pre - root, left, right
        in  - left, root, right
        '''
        if not preorder:
            return None
        
        root_value=preorder.pop(0)
        index_of_root=inorder.index(root_value)
        root=TreeNode(root_value)
        
        root.left=self.buildTree(preorder[:index_of_root], inorder[:index_of_root])
        root.right=self.buildTree(preorder[index_of_root:], inorder[index_of_root+1:])
            
        return root
    
#     def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:        
#         if not preorder:
#             return None
        
#         root=TreeNode(preorder[0])
#         index=inorder.index(preorder[0])
#         root.left=self.buildTree(preorder[1:index+1], inorder[:index])
#         root.right=self.buildTree(preorder[index+1:], inorder[index+1:])
        
#         return root

```
