### [Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) <br>

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

*Merge all the linked-lists into one sorted linked-list and return it*.




#### Example 1:

```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

```

#### Example 2:

```
Input: lists = []
Output: []

```


#### Example 3:

```
Input: lists = [[]]
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
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        
        if len(lists)==0: return None
        if len(lists)==1: return lists[0]
        
        mid=len(lists)//2
        l=self.mergeKLists(lists[:mid])
        r=self.mergeKLists(lists[mid:])
        return self.merge(l, r)
        
        
    def merge(self, l, r):
        dummy=ListNode()
        tail=dummy
        
        while l and r:
            if l.val < r.val:
                tail.next=l
                l=l.next
            else:
                tail.next=r
                r=r.next
            tail=tail.next
            
        if l:
            tail.next=l
        if r:
            tail.next=r
        
        return dummy.next

```
