### [Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/) <br>

Given the `root` of a binary tree, return *all root-to-leaf paths in ***any order****.

A **leaf** is a node with no children.


#### Example 1:
<img src="../../../../../images/257paths-tree.jpg">

```
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

```

#### Example 2:

```
Input: root = [1]
Output: ["1"]

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
#     def binaryTreePaths(self, root: TreeNode) -> List[str]:
#         res=[]

#         def dfs(node):
#             nonlocal res
            
#             if node and not node.left and not node.right:
#                 return [[str(node.val)]]
            
#             out=[]
#             if node.left:
#                 r=dfs(node.left)
#                 tmp=[]
#                 for t in r:
#                     tmp.append([str(node.val)]+t)
#                 if tmp:
#                     out += tmp
#             if node.right:
#                 r=dfs(node.right)
#                 tmp=[]
#                 for t in r:
#                     tmp.append([str(node.val)]+t)
#                 if tmp:
#                     out += tmp                
                
#             return out
        
#         res=dfs(root)
        
#         return ["->".join(r) for r in res]
        
        
        
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        res=[]
        def dfs(node, path):
            nonlocal res
            if node:
                if not node.left and not node.right:
                    path += [str(node.val)]
                    res.append("->".join(path))
                else:
                    dfs(node.left, path+[str(node.val)])
                    dfs(node.right, path+[str(node.val)])
        
        dfs(root, [])
        
        return res

```
