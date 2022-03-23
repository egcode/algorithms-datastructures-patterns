h=3
w=5

### 2d Array
arr=[[0]*w for _ in range(h)]
print(arr) # [[0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]


print(60*"-")
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
print(grid) # [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
half=len(grid)//2
print([row[:half] for row in grid[:half]]) # [[1, 2], [5, 6]]
print([row[half:] for row in grid[:half]]) # [[3, 4], [7, 8]]
print([row[:half] for row in grid[half:]]) # [[9, 10], [13, 14]]
print([row[half:] for row in grid[half:]]) # [[11, 12], [15, 16]]
