# LOOP ~ sign example
data=[1,2,3,4,5]
for i in range(len(data)):
    print(data[i])
print("--")
for i in range(len(data)):
    print(data[~i])




h=3
w=5

### 1d Array
arr=[0]*w
print(arr)

### 2d Array
arr=[[0]*w for _ in range(h)]
print(arr)



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

