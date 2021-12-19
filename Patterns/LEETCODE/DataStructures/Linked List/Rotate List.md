### [Rotate List](https_problem_link) <br>

Given the `head` of a linked list, rotate the list to the right by `k` places.

 

#### Example 1:
<img src="../../../../images/61rotate1.jpg">

```
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

```

#### Example 2:
<img src="../../../../images/61roate2.jpg">

```
Input: head = [0,1,2], k = 4
Output: [2,0,1]

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
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        '''
        Example:
        1->2->3->4->5
        k=2
        '''
        
        if k == 0 or not head:
            return head
        
        dic={}
        index=0
        cur=head
        while cur:
            index += 1            
            dic[index]=cur
            cur=cur.next

        size = index
        
        # we don't rotate since rotate index would be the end of the list        
        if k % size == 0:
            return head  
        # e.g new_end_index in example 1->2->3->4->5  is 3  5-(2%5)=3
        new_end_index = size - (k % size) 
        
        # In this part we separate tail from original end and appending to the beginning
        # e.g. we remember cut tail pointer 4->5 from original 1->2->3->4->5, and original head befomes 1->2->3    
        end_node=dic[new_end_index]
        tail=end_node.next     # remember tail pointer start
        end_node.next=None     # cut tail from original list
        
        # append tail end node to the beginning of original list
        # e.g. here we append 4->5 tail to original head 1->2->3 and get 4->5->1->2->3 as output
        tail_end=dic[size] 
        tail_end.next=head
        
        return tail

```
