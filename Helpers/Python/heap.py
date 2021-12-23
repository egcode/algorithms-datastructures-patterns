import heapq

### HEAP
# initializing list 
li = [5, 7, 9, 1, 3] 
# using heapify to convert list into heap 
heapq.heapify(li) 
# printing created heap 
print ("The created heap is : "+str(list(li))) # The created heap is : [1, 3, 9, 7, 5]
# using heappush() to push elements into heap 
# pushes 4 
heapq.heappush(li,4) 
  
# printing modified heap 
print ("The modified heap after push is : "+str(list(li))) # The modified heap after push is : [1, 3, 4, 7, 5, 9]
  
# using heappop() to pop smallest element 
print ("The popped and smallest element is : "+str(heapq.heappop(li))) # The popped and smallest element is : 1
print (list(li)) # [3, 5, 4, 7, 9]

print("The 3 largest numbers in list are : "+str(heapq.nlargest(3, li))) # The 3 largest numbers in list are : [9, 7, 5]
# using nsmallest to print 3 smallest numbers 
# prints 1, 3 and 4 
print("The 3 smallest numbers in list are : "+str(heapq.nsmallest(3, li)))  # The 3 smallest numbers in list are : [3, 4, 5]

print("The largest numbers in list are : "+str(heapq.nlargest(1, li))) # The largest numbers in list are : [9]
