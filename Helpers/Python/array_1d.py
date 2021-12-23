n=5
### 1d Array
arr=[0]*n
print(arr) # [0, 0, 0, 0, 0]


# LOOP ~ sign example
data=[1,2,3,4,5]
for i in range(len(data)):
    print(" data[i] : "+str(data[i]))
    print(" data[~i]: "+str(data[~i]))
'''
Output: 
 data[i] : 1
 data[~i]: 5
 data[i] : 2
 data[~i]: 4
 data[i] : 3
 data[~i]: 3
 data[i] : 4
 data[~i]: 2
 data[i] : 5


if i==0
      [1,2,3,4,5]
       ^       ^
  data[i]     data[~i]
'''

# Array slice:
'''
[1,2,3,4,5]
 0 1 2 3 4
   ^   ^  - not inclusive
'''
print(data[1:3]) # [2, 3]

