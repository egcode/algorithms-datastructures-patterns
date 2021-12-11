### [Binary Tree Vertical Order Traversal](https://leetcode.com/problems/binary-tree-vertical-order-traversal/) <br>

Given the `root` of a binary tree, return **the vertical order traversal** of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from **left to right**.



#### Example 1:
<img src="../../../../images/314vtree1.jpg">

```
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]

```

#### Example 2:
<img src="../../../../images/314vtree2-1.jpg">

```
Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]

```


#### Example 3:
<img src="../../../../images/314vtree2.jpg">

```
Input: root = [3,9,8,4,0,1,7,null,null,null,2,5]
Output: [[4],[9,5],[3,0,1],[8,2],[7]]

```


#### Example 4:

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
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        '''
        BFS
        '''
        if not root: return []
        columns=collections.defaultdict(list)
        q=collections.deque([(root, 0)])
        
        while q:
            node, col = q.pop()
            columns[col].append(node.val)
            
            if node.left:
                q.appendleft((node.left, col-1))
            if node.right:
                q.appendleft((node.right, col+1))
            
        return [columns[x] for x in sorted(columns.keys())]

```
