### [Sort an Array](https://leetcode.com/problems/sort-an-array/) <br>

Given an array of integers `nums`, sort the array in ascending order.



#### Example 1:

```
Input: nums = [5,2,3,1]
Output: [1,2,3,5]

```

#### Example 2:

```
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]

```

# Solutions

### Python
```
class Solution:
    
    def merge(self,left: List[int], right:List[int]) -> List[int]:
        res=[]
        l=0
        r=0
        while l < len(left) and r < len(right):
            if left[l] < right[r]:
                res.append(left[l])
                l += 1
            else:
                res.append(right[r])
                r += 1
                
        if l < (len(left)):
            for i in range(l, len(left)):
                res.append(left[i])
        if r < (len(right)):
            for i in range(r,len(right)):
                res.append(right[i])
        return res
    
    def sortArray(self, nums: List[int]) -> List[int]:
        '''
        merge sort
        '''
        if len(nums)==1:
            return nums
        
        midIndex=len(nums)//2
        # print("midIndex:"+str(midIndex))
        left_side=self.sortArray(nums[midIndex:])
        right_side=self.sortArray(nums[:midIndex])
        return self.merge(left_side, right_side)


    

#     def sortArray(self, nums: List[int]) -> List[int]:
#         '''
#         Quick Sort
#         '''
#         return self.qsort(nums, 0, len(nums)-1)
        
#     def qsort(self, nums, l, h):
#         if l<h:
#             p=self.partition(nums, l, h)
#             self.qsort(nums, l, p-1)
#             self.qsort(nums, p+1, h)
#         return nums
        
#     def partition(self, nums, l, h):
#         pivot=nums[h]
#         i=l
#         for j in range(l, h):
#             if nums[j] < pivot:
#                 nums[j], nums[i] = nums[i], nums[j]
#                 i += 1
#         nums[h], nums[i] = nums[i], nums[h]
#         return i

```
