### [Reorder List](https://leetcode.com/problems/reorder-list/) <br>

You are given the head of a singly linked-list. The list can be represented as:

<img src="https://render.githubusercontent.com/render/math?math=L_0"> → <img src="https://render.githubusercontent.com/render/math?math=L_1"> → … → <img src="https://render.githubusercontent.com/render/math?math=L_{n - 1}"> → <img src="https://render.githubusercontent.com/render/math?math=L_n">

*Reorder the list to be on the following form*:

<img src="https://render.githubusercontent.com/render/math?math=L_0"> → <img src="https://render.githubusercontent.com/render/math?math=L_n"> → <img src="https://render.githubusercontent.com/render/math?math=L_1"> → <img src="https://render.githubusercontent.com/render/math?math=L_{n - 1}"> → <img src="https://render.githubusercontent.com/render/math?math=L_2"> → <img src="https://render.githubusercontent.com/render/math?math=L_{n - 2}"> → …



You may not modify the values in the list's nodes. Only nodes themselves may be changed.


#### Example 1:
<img src="../../../../images/143reorder1linked-list.jpg">

```
Input: head = [1,2,3,4]
Output: [1,4,2,3]

```

#### Example 2:
<img src="../../../../images/143reorder2-linked-list.jpg">

```
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

```

# Solutions

### Python
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        cur=head
        stack=[]
        
        while cur:
            stack.append(cur)
            cur=cur.next
        
        
        if len(stack)<3:
            return
        
        cur=head
        while cur and stack:
            nxt=cur.next
            end_node=stack.pop()
                        
            cur.next=end_node
            end_node.next=nxt
            cur=nxt
            
            if stack and cur == stack[-1] or cur.next == stack[-1]:
                stack[-1].next=None
                break

```
