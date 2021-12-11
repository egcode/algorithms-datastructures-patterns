### [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) <br>

Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. **Note that** `pos` **is not passed as a parameter**.

Return `true` *if there is a cycle in the linked list*. Otherwise, return `false`.




#### Example 1:
<img src="../../../../images/141circularlinkedlist.png">

```
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

```

#### Example 2:
<img src="../../../../images/141circularlinkedlist_test2.png">

```
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

```


#### Example 3:
<img src="../../../../images/141circularlinkedlist_test3.png">

```
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

```


# Solutions

### Python
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        cur=head
        vis=set()
        while cur:
            if cur in vis:
                return True
            vis.add(cur)
            cur=cur.next
            
        return False
        
```
