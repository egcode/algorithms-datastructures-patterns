### [Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees/) <br>

Given the `root` of a binary tree, return all **duplicate subtrees**.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are **duplicate** if they have the **same structure** with the **same node values**.


#### Example 1:
<img src="../../../../../images/652e1.jpg">

```
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

```

#### Example 2:
<img src="../../../../../images/652e2.jpg">

```
Input: root = [2,1,1]
Output: [[1]]

```

#### Example 3:
<img src="../../../../../images/652e33.jpg">

```
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]

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
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        '''
        Explanation:
        https://www.youtube.com/watch?v=JRar1M0H5nc&ab_channel=DSCFIUDSCFIU
        '''
        
        dic=collections.defaultdict(list)
        
        def dfs(node):
            if not node:
                return "null"
            key=str(node.val)+'-'+dfs(node.left)+'-'+dfs(node.right)
            dic[key].append(node)
            return key
        
        
        dfs(root)
        res=[]
        for key in dic.keys():
            if len(dic[key]) > 1:
                res.append(dic[key][0])
                
        return res

```
