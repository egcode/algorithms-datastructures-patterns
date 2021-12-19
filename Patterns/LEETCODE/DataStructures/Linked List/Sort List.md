### [Sort List](https://leetcode.com/problems/sort-list/) <br>

Given the `head` of a linked list, return *the list after sorting it in ***ascending order****.



#### Example 1:
<img src="../../../../images/148sort_list_1.jpg">

```
Input: head = [4,2,1,3]
Output: [1,2,3,4]

```

#### Example 2:
<img src="../../../../images/148sort_list_2.jpg">

```
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

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
    def sortList(self, head: ListNode) -> ListNode:
    
        if not head:
            return head
        if not head.next:
            return head
        
        mid = self.get_mid(head)
        lo = self.sortList(head)
        hi = self.sortList(mid)
        return self.merge(lo, hi)
        
    def get_mid(self, head):
        fast=head
        slow=head
        while fast.next and fast.next.next:
            slow=slow.next
            fast=fast.next.next
        mid=slow.next
        slow.next = None     # Cuts second part from head, so we don't merge this part again
        return mid
        
    def merge(self, lo, hi):
        dummy=ListNode()
        tail=dummy
        
        while lo and hi:
            if lo.val < hi.val:
                tail.next=lo          # Assiging new list to tail
                tail=tail.next        # Move tail pointer forward 
                lo=lo.next
            else:
                tail.next=hi          # Assiging new list to tail          
                tail=tail.next        # Move tail pointer forward 
                hi=hi.next
        tail.next = lo or hi
        
        return dummy.next

```
