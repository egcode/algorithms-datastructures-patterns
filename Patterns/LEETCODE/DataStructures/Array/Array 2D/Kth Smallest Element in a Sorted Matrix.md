### [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) <br>

Given an `n x n` `matrix` where each of the rows and columns is sorted in ascending order, return the <img src="https://render.githubusercontent.com/render/math?math=k^{th}"> *smallest element in the matrix*.

Note that it is the <img src="https://render.githubusercontent.com/render/math?math=k^{th}"> smallest element **in the sorted order**, not the <img src="https://render.githubusercontent.com/render/math?math=k^{th}"> **distinct** element.

You must find a solution with a memory complexity better than <img src="https://render.githubusercontent.com/render/math?math=O(n^2)">.



#### Example 1:

```
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

```

#### Example 2:

```
Input: matrix = [[-5]], k = 1
Output: -5

```



# Solutions

### Python
```
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        heap=[]
        h=len(matrix)
        w=len(matrix[0])
        
        for i in range(h):
            for j in range(w):
                heapq.heappush(heap, matrix[i][j])
        
        smallest=heapq.nsmallest(k, heap)
        return smallest[-1]
        
#     def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        
#         # The size of the matrix
#         N = len(matrix)
#         # Preparing our min-heap
#         minHeap = []
#         for r in range(min(k, N)):
#             # We add triplets of information for each cell
#             minHeap.append((matrix[r][0], r, 0))
        
#         # Heapify our list
#         heapq.heapify(minHeap)    
#         # Until we find k elements
#         while k:
#             # Extract-Min
#             element, r, c = heapq.heappop(minHeap)
#             # If we have any new elements in the current row, add them
#             if c < N - 1:
#                 heapq.heappush(minHeap, (matrix[r][c+1], r, c+1))
#             # Decrement k
#             k -= 1
        
#         return element         

```
