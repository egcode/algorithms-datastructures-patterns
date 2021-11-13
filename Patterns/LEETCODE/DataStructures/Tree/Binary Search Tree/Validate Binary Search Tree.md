### [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) <br>

Given the `root` of a binary tree, *determine if it is a valid binary search tree (BST)*.

A **valid BST** is defined as follows:

 - The left subtree of a node contains only nodes with keys **less than** the node's key.
 - The right subtree of a node contains only nodes with keys **greater than** the node's key.
 - Both the left and right subtrees must also be binary search trees.


#### Example 1:
<img src="../../../../images/98tree1.jpg">

```
Input: root = [2,1,3]
Output: true

```

#### Example 2:
<img src="../../../../images/98tree2.jpg">

```
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

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
#     def isValidBST(self, root: TreeNode) -> bool:
#         stack=[]
#         cur=root
#         prev=None
        
#         while stack or cur:
#             while cur:
#                 stack.append(cur)
#                 cur=cur.left
                
#             if stack:
#                 last=stack.pop()
                
#                 if prev != None:
#                     if prev >= last.val:
#                         return False
#                 prev=last.val
                
#                 cur=last.right
#         return True
    
    
    
    def valid(self, root: TreeNode, low: None, high: None) -> bool:
        if not root:
            return True
        
        # print("root: "+str(root.val)+"  low:"+str(low)+" high:"+str(high))

        if low != None:
            if root.val<=low:
                return False
        if high != None:
            if root.val>=high:
                return False

        if not self.valid(root.left, low, root.val):
            return False
        
        if not self.valid(root.right, root.val, high):
            return False
        return True

                            
    def isValidBST(self, root: TreeNode) -> bool:
        return self.valid(root,None,None)

```
