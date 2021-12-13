### [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) <br>

Given two integer arrays `inorder` and `postorder` where `inorder` is the inorder traversal of a binary tree and `postorder` is the postorder traversal of the same tree, construct and return *the binary tree*.




#### Example 1:
<img src="../../../../../images/106tree.jpg">

```
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

```

#### Example 2:

```
Input: inorder = [-1], postorder = [-1]
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
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        '''
        inorder   - left, root, right
        postorder - right,left, root
        '''
        
        if not postorder:
            return None
        
        root_value=postorder.pop()
        root_index=inorder.index(root_value)
        root_node=TreeNode(root_value)
        
        root_node.left=self.buildTree(inorder[:root_index], postorder[:root_index])
        root_node.right=self.buildTree(inorder[root_index+1:], postorder[root_index:])
        
        return root_node
```
