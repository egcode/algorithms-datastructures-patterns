# #### DEQUEUE
import collections

d=collections.deque([1,2,3,4,5])
print(d) # deque([1, 2, 3, 4, 5])

d.appendleft(555)
print(d) # deque([555, 1, 2, 3, 4, 5])

d.append(666)
print(d) # deque([555, 1, 2, 3, 4, 5, 666])

p=d.pop()
print("Popped: "+str(p)) # Popped: 666
print(d) # deque([555, 1, 2, 3, 4, 5])
