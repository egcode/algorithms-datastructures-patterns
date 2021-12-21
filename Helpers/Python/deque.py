# #### DEQUEUE
import collections

d=collections.deque([1,2,3,4,5])
print(d)

d.appendleft(555)
print(d)

d.append(666)
print(d)

p=d.pop()
print("Popped: "+str(p))
print(d)
