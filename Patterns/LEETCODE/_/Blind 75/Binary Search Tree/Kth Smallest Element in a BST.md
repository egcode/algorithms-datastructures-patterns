### [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) <br>

Given the `root` of a binary search tree, and an integer <img src="https://render.githubusercontent.com/render/math?math=k">, return the <img src="https://render.githubusercontent.com/render/math?math=k^{th}"> *smallest value* (**1-indexed**) *of all the values of the nodes in the tree*.



#### Example 1:
<img src="../../../../images/230kthtree1.jpg">

```
Input: root = [3,1,4,null,2], k = 1
Output: 1

```

#### Example 2:
<img src="../../../../images/230kthtree2.jpg">

```
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

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
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        cur=root
        stack=[]
        count = 0
        while stack or cur:
            while cur:
                stack.append(cur)
                cur = cur.left
        
            if stack:
                p = stack.pop()
                count += 1
                if count == k:
                    return p.val
                cur = p.right
                
                
                
        return 0
```
