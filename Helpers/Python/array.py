# LOOP ~ sign example
data=[1,2,3,4,5]
for i in range(len(data)):
    print(data[i])
print("--")
for i in range(len(data)):
    print(data[~i])



# #### MATRIX
'''
Split Matrix into 4 pieces. Quad-Tree
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9, 10,11,12],
  [13,14,15,16]
]

'''
grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
print(grid)
half=len(grid)//2
print([row[:half] for row in grid[:half]])
print([row[half:] for row in grid[:half]])
print([row[:half] for row in grid[half:]])
print([row[half:] for row in grid[half:]])




# Sort By tuple element
t=[[4,5],[1,4],[0,1]]
t.sort(key=lambda tup: tup[0]) 
print("Sorted Tuple: " + str(t))

print(60*"-")
