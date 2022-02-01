class Node:
    def __init__(self, val, key):
        self.key=key
        self.val=val
        self.prev=None
        self.next=None
        
    
class LRUCache:
        
    def __init__(self, capacity: int):
        self.dic={}
        self.cap=capacity
        self.count=0
        self.head=Node(-1,-1)
        self.tail=Node(-1,-1)
        self.head.next=self.tail
        self.tail.pres=self.head

    def connect(self, node):
        node.prev=self.head
        node.next=self.head.next
        
        self.head.next.prev=node
        self.head.next=node
        
    def disconnect(self,node):
        prev=node.prev
        nxt=node.next
        node.prev=None
        node.next=None
        
        prev.next=nxt
        nxt.prev=prev
        
    def cut_tail(self):
        to_del=self.tail.prev
        self.disconnect(to_del)
        del self.dic[to_del.key]
        self.count -= 1



    def get(self, key: int) -> int:
        '''
        Get Value if exists
        '''
        if key in self.dic.keys():
            node=self.dic[key]
            self.disconnect(node)
            self.connect(node)
            return node.val
        else:
            return -1
        

    def put(self, key: int, value: int) -> None:
        '''
        Put Value, remove least used one
        '''
        if key in self.dic.keys():
            node=self.dic[key]
            self.disconnect(node)
            node.val=value
            self.connect(node)
        else:
            new_node=Node(value, key)
            self.dic[key]=new_node
            self.connect(new_node)
            self.count += 1            
            if self.count>self.cap:
                self.cut_tail()


'''
Example from 146. LRU Cache in leetcode
'''
lRUCache = LRUCache(2)

print(lRUCache.put(1, 1)); # cache is {1=1}
print(lRUCache.put(2, 2)); # cache is {1=1, 2=2}
print(lRUCache.get(1));    # return 1
print(lRUCache.put(3, 3)); # LRU key was 2, evicts key 2, cache is {1=1, 3=3}
print(lRUCache.get(2));    # returns -1 (not found)
print(lRUCache.put(4, 4)); # LRU key was 1, evicts key 1, cache is {4=4, 3=3}
print(lRUCache.get(1));    # return -1 (not found)
print(lRUCache.get(3));    # return 3
print(lRUCache.get(4));    # return 4
