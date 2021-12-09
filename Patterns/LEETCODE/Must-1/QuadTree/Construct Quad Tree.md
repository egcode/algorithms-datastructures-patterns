### [Construct Quad Tree](https://leetcode.com/problems/construct-quad-tree/) <br>

Given a `n * n` matrix `grid` of `0's` and `1's` only. We want to represent the `grid` with a Quad-Tree.

***Return the root of the Quad-Tree*** representing the `grid`.

Notice that you can assign the value of a node to **True** or **False** when `isLeaf` is **False**, and both are `accepted` in the answer.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

 - `val`: True if the node represents a grid of 1's or False if the node represents a grid of 0's. 
 - `isLeaf`: True if the node is leaf node on the tree or False if the node has the four children.

```
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}

```

We can construct a Quad-Tree from a two-dimensional area using the following steps:

 - If the current grid has the same value (i.e all `1's` or all `0's`) set `isLeaf` True and set `val` to the value of the grid and set the four children to Null and stop.
 - If the current grid has different values, set `isLeaf` to False and set `val` to any value and divide the current grid into four sub-grids as shown in the photo.
 - Recurse for each of the children with the proper sub-grid.

<img src="../../../../images/427new_top.png">



If you want to know more about the Quad-Tree, you can refer to the [wiki](https://en.wikipedia.org/wiki/Quadtree).

**Quad-Tree format**:

The output represents the serialized format of a Quad-Tree using level order traversal, where `null` signifies a path terminator where no node exists below.

It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list `[isLeaf, val]`.

If the value of `isLeaf` or `val` is True we represent it as **1** in the list `[isLeaf, val]` and if the value of `isLeaf` or `val` is False we represent it as **0**.





#### Example 1:
<img src="../../../../images/427grid1.png">

```
Input: grid = [[0,1],[1,0]]
Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
Explanation: The explanation of this example is shown below:
Notice that 0 represnts False and 1 represents True in the photo representing the Quad-Tree.

```
<img src="../../../../images/427e1tree.png">



#### Example 2:
<img src="../../../../images/427e2mat.png">

```
Input: grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
Output: [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
Explanation: All values in the grid are not the same. We divide the grid into four sub-grids.
The topLeft, bottomLeft and bottomRight each has the same value.
The topRight have different values so we divide it into 4 sub-grids where each has the same value.
Explanation is shown in the photo below:

```
<img src="../../../../images/427e2tree.png">




#### Example 3:

```
Input: grid = [[1,1],[1,1]]
Output: [[1,1]]

```


#### Example 4:

```
Input: grid = [[0]]
Output: [[1,0]]

```


#### Example 5:

```
Input: grid = [[1,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]]
Output: [[0,1],[1,1],[1,0],[1,0],[1,1]]

```



# Solutions

### Python
```
"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        root=Node(0, 1, None, None, None, None)
        
        if len(set([item for row in grid for item in row]))==1:
            root.val=grid[0][0]
        else:
            root.isLeaf=False
            half=len(grid)//2
            root.topLeft=self.construct([row[:half] for row in grid[:half]])
            root.topRight=self.construct([row[half:] for row in grid[:half]])
            root.bottomLeft=self.construct([row[:half] for row in grid[half:]])
            root.bottomRight=self.construct([row[half:] for row in grid[half:]])
            
        return root
```
