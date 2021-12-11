### [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) <br>

Given the `head` of a linked list, remove the <img src="https://render.githubusercontent.com/render/math?math=n^{th}"> node from the end of the list and return its head.



#### Example 1:
<img src="../../../../images/19remove_ex1.jpg">

```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

```

#### Example 2:

```
Input: head = [1], n = 1
Output: []

```


#### Example 3:

```
Input: head = [1,2], n = 1
Output: [1]

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
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        
        dummy=ListNode()
        dummy.next=head
        
        slow=dummy
        fast=dummy
        
        # Move fast node so we have n gap between fast and slow
        # n+1 because we start with dummy node
        for i in range(n+1):
            fast=fast.next
            
        # While fast is not None move slow forward, slow will stop before n-th node
        while fast:
            fast = fast.next
            slow = slow.next
            
        # Assign remove n-th node
        slow.next = slow.next.next
        
        return dummy.next
```
