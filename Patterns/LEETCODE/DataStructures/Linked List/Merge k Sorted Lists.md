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
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        '''
        Example Walkthrough
        lists = [
            1 -> 4 -> 5,
            1 -> 3 -> 4,
            2 -> 6
        ]
        Round 1:
            Merge (1->4->5) and (1->3->4) → 1->1->3->4->4->5
            Last one (2->6) has no pair → stays as is
            mergedLists = [ 1->1->3->4->4->5 , 2->6 ]

        Round 2:
            Merge (1->1->3->4->4->5) and (2->6) → 1->1->2->3->4->4->5->6
            Only one list remains — return it.
        '''
        if not lists or len(lists)==0:
            return None
        while len(lists)>1:
            mergedLists = []

            for i in range(0, len(lists), 2):
                l1=lists[i]
                l2=lists[i+1] if (i+1)<len(lists) else None
                mergedLists.append(self.mergeTwoLists(l1,l2))
            lists = mergedLists
        return lists[0]

    # def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        
    #     if len(lists)==0: return None
    #     if len(lists)==1: return lists[0]
        
    #     mid=len(lists)//2
    #     l=self.mergeKLists(lists[:mid])
    #     r=self.mergeKLists(lists[mid:])
    #     return self.mergeTwoLists(l, r)

    def mergeTwoLists(self, list1, list2):
        if not list1:
            return list2
        if not list2:
            return list1

        if list1.val < list2.val:
            cur = root = list1
            list1 = list1.next
        else:
            cur = root = list2
            list2 = list2.next

        while list1 and list2:
            if list1.val > list2.val:
                cur.next = list2
                list2 = list2.next
            else:
                cur.next = list1
                list1 = list1.next
            cur = cur.next
        if list1 or list2:
            cur.next = list1 or list2
        return root
```
