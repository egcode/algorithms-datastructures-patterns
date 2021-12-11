### [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) <br>

Given the `head` of a singly linked list, reverse the list, and return *the reversed list*.



#### Example 1:
<img src="../../../../images/206rev1ex1.jpg">

```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

```

#### Example 2:
<img src="../../../../images/206rev1ex2.jpg">

```
Input: head = [1,2]
Output: [2,1]

```


#### Example 3:

```
Input: head = []
Output: []

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
    def reverseList(self, head: ListNode) -> ListNode:
        cur=head
        rev_head=None
        
        while cur:
            nxt = cur.next # remember current to continue
            
            # do REVERSE operatons
            cur.next = rev_head
            rev_head = cur
        
            # Continue traverse
            cur = nxt
            
        return rev_head
```
