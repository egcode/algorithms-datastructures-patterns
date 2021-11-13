### [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) <br>

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

**Clarification**: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.




#### Example 1:
<img src="../../../../../images/297serdeser.jpg">

```
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

```

#### Example 2:

```
Input: root = []
Output: []

```

#### Example 3:

```
Input: root = [1]
Output: [1]

```

#### Example 4:

```
Input: root = [1,2]
Output: [1,2]

```


# Solutions

### Python
```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        arr=[]
        
        def preorder(node):
            if not node:
                return
            arr.append(str(node.val))
            preorder(node.left)
            arr.append("#")
            preorder(node.right)
        
        preorder(root)
        
        return " ".join(arr)

    def deserialize(self, data):
        if data=="": return None
        print(data)
        arr=data.split(" ")
        arr=collections.deque(arr)
        
        root_data=arr.popleft()
        root=TreeNode(root_data)
        
        def build(node):
            
            while arr and arr[0] != "#":
                ldata=int(arr.popleft())
                node.left=TreeNode(ldata)
                build(node.left)
            
            if arr:
                arr.popleft()
                
            
            while arr and arr[0] != "#":
                rdata=int(arr.popleft())
                node.right=TreeNode(rdata)
                build(node.right)
            
        build(root)
        return root

```
