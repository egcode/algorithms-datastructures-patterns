### [Same Tree](https://leetcode.com/problems/same-tree/) <br>

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.




#### Example 1:
<img src="../../../../images/100ex1.jpg">

```
Input: p = [1,2,3], q = [1,2,3]
Output: true

```

#### Example 2:
<img src="../../../../images/100ex2.jpg">

```
Input: p = [1,2], q = [1,null,2]
Output: false

```


#### Example 3:
<img src="../../../../images/100ex3.jpg">

```
Input: p = [1,2,1], q = [1,1,2]
Output: false

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
    
    # def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
    #     if not p and not q:
    #         return True
    #     if not p or not q:
    #         return False
    #     if p.val != q.val:
    #         return False
    #     return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        
        
        
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        def ch(p: TreeNode, q: TreeNode):
            if not p and not q:
                return True
            if not p or not q:
                return False
            if p.val != q.val:
                return False
            return True
        
        stack = [(p, q)]
        
        while stack:
            p,q = stack.pop()
            
            if not ch(p,q):
                return False
            
            if p and q:
                stack.append([p.left, q.left])
                stack.append([p.right, q.right])
                
        return True

```
