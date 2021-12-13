### [Check Completeness of a Binary Tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree/) <br>

Given the `root` of a binary tree, determine if it is a complete binary tree.

In a [complete binary tree](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees), every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between <img src="https://render.githubusercontent.com/render/math?math=1"> and <img src="https://render.githubusercontent.com/render/math?math=2^h"> nodes inclusive at the last level `h`.





#### Example 1:
<img src="../../../../../images/958complete-binary-tree-1.png">

```
Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.

```

#### Example 2:
<img src="../../../../../images/958complete-binary-tree-2.png">

```
Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.

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
    def isCompleteTree(self, root: TreeNode) -> bool:
        '''
        Check Level per level
        '''
        q=collections.deque([(root, True)])
        
        # IF we meet empty node that means that this level should be last one with Non empty node
        # and if we meet non empty node on next level, we return False
        should_finish=False 
        
        while q:
            size=len(q)
            level=[]
            empty_count=0
            nodes_count=0
            while size>0:
                node, is_left = q.pop()
                
                if node:
                    if should_finish==True:
                        return False
                    
                    level.append((is_left, node.val))
                    nodes_count += 1
                    
                    q.appendleft((node.left, True))
                    q.appendleft((node.right, False))
                else:
                    level.append((None, None))
                    empty_count += 1
                size -= 1
                
            # Check for left->right->left->right sequence
            # if we don't follow sequence or element is None return False
            lev=level[:nodes_count]
            for i, r in enumerate(lev):
                if i%2==0:
                    if r[0] != True or r[0]==None:
                        return False
                else:
                    if r[0] != False or r[0]==None:
                        return False
            if empty_count>0:
                should_finish=True
        return True

```
