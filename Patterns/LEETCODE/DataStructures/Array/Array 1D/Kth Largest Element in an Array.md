### [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) <br>

Given an integer array nums and an integer <img src="https://render.githubusercontent.com/render/math?math=k">, return *the* <img src="https://render.githubusercontent.com/render/math?math=k^{th}"> *largest element in the array*.

Note that it is the <img src="https://render.githubusercontent.com/render/math?math=k^{th}"> largest element in the sorted order, not the <img src="https://render.githubusercontent.com/render/math?math=k^{th}"> distinct element.



#### Example 1:

```
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

```

#### Example 2:

```
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

```

# Solutions

### Python
```
class Solution:
    
#     def findKthLargest(self, nums: List[int], k: int) -> int:
#         '''
#         Time Limit Exceeded
#         '''
#         n=len(nums)
#         self.qsort(nums, 0, n-1)
#         # print(nums)
#         return nums[n-k]
    
#     def qsort(self, arr, l, h):
#         if l<h:
            
#             # Random Helper, avoids small value at 'up' index
#             randomInt = random.randint(l, h)
#             arr[randomInt], arr[h] = arr[h], arr[randomInt]
            
#             p=self.partition(arr, l, h)
#             self.qsort(arr, p+1, h)
#             self.qsort(arr, l, h-1)
            
#     def partition(self, arr, l, h):
#         pivot=arr[h]
#         i=l
#         for j in range(l, h):
#             if arr[j]<pivot:
#                 arr[j], arr[i] = arr[i], arr[j]
#                 i += 1
#         arr[i], arr[h] = arr[h], arr[i]
#         return i
                
        
    def findKthLargest(self, nums: List[int], k: int) -> int:
        '''
        Heap
        '''
        heapq.heapify(nums)
        # print(nums)
        klargest = heapq.nlargest(k, nums)
        # print(klargest)
        return klargest[-1]

```
