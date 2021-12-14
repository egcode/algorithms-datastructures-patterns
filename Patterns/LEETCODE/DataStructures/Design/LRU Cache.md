### [LRU Cache](https://leetcode.com/problems/lru-cache/) <br>

Design a data structure that follows the constraints of a [Least Recently Used (LRU) cache](https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU).

Implement the `LRUCache` class:

 - `LRUCache(int capacity)` Initialize the LRU cache with **positive** size `capacity`.
 - `int get(int key)` Return the value of the key if the key exists, otherwise return `-1`.
 - `void put(int key, int value)` Update the value of the `key` if the `key` exists. Otherwise, add the `key-value` pair to the cache. If the number of keys exceeds the `capacity` from this operation, **evict** the least recently used key.


The functions `get` and `put` must each run in `O(1)` average time complexity.



#### Example 1:

```
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

```


# Solutions

### Python
```
class Node:
    def __init__(self, val, key):
        self.key=key
        self.val=val
        self.prev=None
        self.next=None
        
    
class LRUCache:
    def add(self, node):
        node.prev=self.head
        node.next=self.head.next
        
        self.head.next.prev=node
        self.head.next=node
        
    def remove(self,node):
        prev=node.prev
        nxt=node.next
        node.prev=None
        node.next=None
        
        prev.next=nxt
        nxt.prev=prev
        
    def cut_tail(self):
        to_del=self.tail.prev
        self.remove(to_del)
        del self.dic[to_del.key]
        self.count -= 1
        
    def __init__(self, capacity: int):
        self.dic={}
        self.cap=capacity
        self.count=0
        self.head=Node(-1,-1)
        self.tail=Node(-1,-1)
        self.head.next=self.tail
        self.tail.pres=self.head
                

    def get(self, key: int) -> int:
        if key in self.dic.keys():
            node=self.dic[key]
            self.remove(node)
            self.add(node)
            return node.val
        else:
            return -1
        

    def put(self, key: int, value: int) -> None:
        if key in self.dic.keys():
            node=self.dic[key]
            self.remove(node)
            node.val=value
            self.add(node)
        else:
            new_node=Node(value, key)
            self.dic[key]=new_node
            self.add(new_node)
            self.count += 1            
            if self.count>self.cap:
                self.cut_tail()

```
