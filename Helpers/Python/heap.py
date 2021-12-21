import heapq

### HEAP
# initializing list 
li = [5, 7, 9, 1, 3] 
# using heapify to convert list into heap 
heapq.heapify(li) 
# printing created heap 
print ("The created heap is : "+str(list(li))) 
# using heappush() to push elements into heap 
# pushes 4 
heapq.heappush(li,4) 
  
# printing modified heap 
print ("The modified heap after push is : "+str(list(li))) 
  
# using heappop() to pop smallest element 
print ("The popped and smallest element is : "+str(heapq.heappop(li))) 
print (list(li)) 

print("The 3 largest numbers in list are : "+str(heapq.nlargest(3, li))) 
# using nsmallest to print 3 smallest numbers 
# prints 1, 3 and 4 
print("The 3 smallest numbers in list are : "+str(heapq.nsmallest(3, li))) 

print("The largest numbers in list are : "+str(heapq.nlargest(1, li))) 
