### [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/) <br>

Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return the *values of the nodes you can see ordered from top to bottom*.




#### Example 1:
<img src="../../../../images/199tree.jpg">

```
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

```

#### Example 2:

```
Input: root = [1,null,3]
Output: [1,3]

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
    def rightSideView(self, root: TreeNode) -> List[int]:
        res=[]
        if not root: return res
        
        q=collections.deque([root])
        
        while q:
            size=len(q)
            level=[]
            while size>0:
                node=q.pop()
                level.append(node.val)                
                if node.left:
                    q.appendleft(node.left)
                if node.right:
                    q.appendleft(node.right)
                
                size -= 1
                
            res.append(level[-1])
        
        return res

```
