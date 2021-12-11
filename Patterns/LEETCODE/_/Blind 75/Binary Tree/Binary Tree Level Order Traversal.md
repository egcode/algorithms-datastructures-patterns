### [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) <br>

Given the `root` of a binary tree, return *the level order traversal of its nodes' values.* (i.e., from left to right, level by level).


#### Example 1:
<img src="../../../../images/102tree1.jpg">

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

```

#### Example 2:

```
Input: root = [1]
Output: [[1]]

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
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        res=[]
        q=collections.deque([root])
        
        while q:
            size=len(q)
            arr=[]
            while size>0:
                node=q.pop()
                arr.append(node.val)
                if node.left:
                    q.appendleft(node.left)
                if node.right:
                    q.appendleft(node.right)
                size -= 1
            res.append(arr)
        return res
```
