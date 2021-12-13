### [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) <br>

Given the `root` of a Binary Search Tree and a target number `k`, return `true` *if there exist two elements in the BST such that their sum is equal to the given target*.



#### Example 1:
<img src="../../../../../images/653sum_tree_1.jpg">

```
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

```

#### Example 2:
<img src="../../../../../images/653sum_tree_2.jpg">

```
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false

```

#### Example 3:

```
Input: root = [2,1,3], k = 4
Output: true

```


#### Example 4:

```
Input: root = [2,1,3], k = 1
Output: false

```


#### Example 5:

```
Input: root = [2,1,3], k = 3
Output: true

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
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        values=set()
        cur=root
        stack=[]
        
        while cur or stack:
            while cur:
                stack.append(cur)
                cur=cur.left
                
            while stack and not cur:
                node=stack.pop()
                # print(node.val)
                if node.right:
                    cur=node.right
                if node.val in values:
                    return True
                values.add(k-node.val)
        
        return False

```
