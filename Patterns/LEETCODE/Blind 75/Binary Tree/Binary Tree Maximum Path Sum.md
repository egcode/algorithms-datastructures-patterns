### [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) <br>

A **path** in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence **at most once**. Note that the path does not need to pass through the root.

The **path sum** of a path is the sum of the node's values in the path.

Given the `root` of a binary tree, return *the maximum* **path sum** *of any* **non-empty** *path*.


#### Example 1:
<img src="../../../../images/124exx1.jpg">

```
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

```

#### Example 2:
<img src="../../../../images/124exx2.jpg">

```
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

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
#     def maxPathSum(self, root: TreeNode) -> int:
#         '''
#         Limit Time Exceeded
#         '''
#         nodes=[]
#         def dfs(node, parent):
#             node.parent=parent
#             nodes.append(node)
#             if node.left:
#                 dfs(node.left, node)
#             if node.right:
#                 dfs(node.right, node)

#         dfs(root, None)
        
#         res=-sys.maxsize
        
#         def dfs_count(node, vis, path):
#             nonlocal res
            
#             path += node.val
#             res=max(res, path)
            
#             p=node.parent
#             l=node.left
#             r=node.right
            
#             if p and p not in vis:
#                 vis.add(p)
#                 dfs_count(p, vis, path)
#             if l and l not in vis:
#                 vis.add(l)
#                 dfs_count(l, vis, path)
#             if r and r not in vis:
#                 vis.add(r)
#                 dfs_count(r, vis, path)

        
        
#         for node in nodes:
#             vis=set()
#             vis.add(node)
#             dfs_count(node, vis, 0)
            
#         if res==-sys.maxsize:
#             return 0
#         return res
    
    
    
    def maxPathSum(self, root: TreeNode) -> int:
        res=-sys.maxsize
        
        def dfs(node):
            nonlocal res
            
            if not node:
                return 0
            
            max_left=max(dfs(node.left), 0)
            max_right=max(dfs(node.right), 0)
            
            current_path = node.val + max_left + max_right # current path goring through node
            res=max(res, current_path)
            
            return node.val + max(max_left, max_right) # return current node and biggest branch
        
        dfs(root)
        
        return res

```
