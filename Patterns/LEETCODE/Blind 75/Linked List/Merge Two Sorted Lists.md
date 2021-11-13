### [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) <br>

Merge two sorted linked lists and return it as a **sorted** list. The list should be made by splicing together the nodes of the first two lists.




#### Example 1:
<img src="../../../../images/21merge_ex1.jpg">

```
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

```

#### Example 2:

```
Input: l1 = [], l2 = []
Output: []

```

#### Example 3:

```
Input: l1 = [], l2 = [0]
Output: [0]

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
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy=ListNode()
        tail=dummy
        
        while l1 and l2:
            if l1.val < l2.val:
                tail.next=l1
                l1=l1.next
            else:
                tail.next=l2
                l2=l2.next
            tail=tail.next
            
        if l1:
            tail.next=l1
        if l2:
            tail.next=l2
        
        return dummy.next
        
```
