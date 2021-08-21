# # String from array
# array = ["Andrew", "Ben", "John", "Paul", "Peter", "Laura"]
# joined = ", ".join(array)
# print("String from Array: "+joined)

# print(60*"-")

# # Array from string
# someStr = "super String with awesome TExt"
# arr = someStr.split(" ")
# print("Array from string: " + str(arr))

# print(60*"-")

# # Sort string
# some_str = "defbgca"
# str_sorted="".join(sorted(some_str))
# print("Sorted string: " + str_sorted)

# print(60*"-")

# # Sort Tuple
# t=[[4,5],[1,4],[0,1]]
# t.sort(key=lambda tup: tup[0]) 
# print("Sorted Tuple: " + str(t))

# print(60*"-")

# # Random integer
# print("Random: "+str(random.random()))
# print("Random integer: "+str(random.randint(3, 9)))


# # Split String
# s="leetcode"
# ss="leet"
# print(s[:len(ss)])
# print(s[len(ss):])

# # Random Dictionary element
# d={"one": 1, "two":2, "three":3, "four":4}
# print(random.choice(list(d.values())))

# ### SETs
# # Check if sets intersect
# s1={1,2,3,4}
# s2={4,5,6,7}
# if set(s1).isdisjoint(s2):
#     print("sets don't have intersection")
# else:
#     print("sets have intersection")
   
#  ### Find sets intersections or union
# s1={1,2,3,4}
# s2={4,5,6,7}
# set_union=s1.union(s2)
# set_intersection=s1.intersection(s2)
# print("Set union: "+str(set_union))
# print("Set intersection: "+str(set_intersection))


# ### HEAP
# # initializing list 
# li = [5, 7, 9, 1, 3] 
# # using heapify to convert list into heap 
# heapq.heapify(li) 
# # printing created heap 
# print ("The created heap is : "+str(list(li))) 
# # using heappush() to push elements into heap 
# # pushes 4 
# heapq.heappush(li,4) 
  
# # printing modified heap 
# print ("The modified heap after push is : "+str(list(li))) 
  
# # using heappop() to pop smallest element 
# print ("The popped and smallest element is : "+str(heapq.heappop(li))) 
# print (list(li)) 

# print("The 3 largest numbers in list are : "+str(heapq.nlargest(3, li))) 
# # using nsmallest to print 3 smallest numbers 
# # prints 1, 3 and 4 
# print("The 3 smallest numbers in list are : "+str(heapq.nsmallest(3, li))) 

# print("The largest numbers in list are : "+str(heapq.nlargest(1, li))) 


# # #### DEQUEUE
# d=collections.deque([1,2,3,4,5])
# print(d)

# d.appendleft(555)
# print(d)

# d.append(666)
# print(d)

# p=d.pop()
# print("Popped: "+str(p))
# print(d)

# # #### Frozenset, turn array into a hash
# arr=[(1,2), (3,4), (7,8)]
# t=tuple(arr)
# some_set=set()
# some_set.add(frozenset(t))
# print(some_set)


# #### CONCATENATE SETS
# s1=set([1,2,3])
# s2=set([4,5])
# s3 = s1 | s2
# print(s3)
# s3 |= {555}
# print(s3)


# # # #### BIT Wise Operations
# d1=512
# print(d1 >> 1) # = 256  - Divide by 2
# print(d1 << 1) # = 1024 - Multiply by 2


# # # #### LETTERS TO Alphabet ARRAY
# word='abczzz'
# alphabet=[0]*26
# for l in word:
#     alphabet[ord(l)-ord('a')] += 1
# print(alphabet)

# # #### Random Element in array
# foo = ['a', 'b', 'c', 'd', 'e']
# print(random.choice(foo))

# ##### Special characted for sting encoding/decoding
# separator = chr(256) # SEPARATE with this special character
# print(separator)

### CREATE BINARY MASK: 
# mask=0
# print(format(mask, '0{}b'.format(31)))
# for i in range(10):
#     mask |= 1<<i # adds one  to the mask
# binary_string = format(mask, '0{}b'.format(31))
# print(binary_string)
# # OR MASK ALL:
# mask=0
# for i in range(31):
#     mask |= 1<<i # adds one  to the mask
# binary_string = format(mask, '0{}b'.format(31))
# print(binary_string)

