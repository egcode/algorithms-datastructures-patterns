### [Minimum Difference Between Largest and Smallest Value in Three Moves](https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/) <br>

Given an array `nums`, you are allowed to choose one element of `nums` and change it by any value in one move.

Return the minimum difference between the largest and smallest value of `nums` after perfoming at most 3 moves.



#### Example 1:

```
Input: nums = [5,3,2,4]
Output: 0
Explanation: Change the array [5,3,2,4] to [2,2,2,2].
The difference between the maximum and minimum is 2-2 = 0.

```

#### Example 2:

```
Input: nums = [1,5,0,10,14]
Output: 1
Explanation: Change the array [1,5,0,10,14] to [1,1,0,1,1]. 
The difference between the maximum and minimum is 1-0 = 1.

```

#### Example 3:

```
Input: nums = [6,6,0,1,1,4,6]
Output: 2

```

#### Example 4:

```
Input: nums = [1,5,6,14,15]
Output: 1

```

# Solutions

### Python
```
class Solution:
#     def minDifference(self, nums: List[int]) -> int:
#         '''
#         https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/discuss/730567/JavaC%2B%2BPython-Straight-Forward
        
        
#         - sort array
#         - get begin array and end array slices
#         - get smallest difference between smallest and biggest
        
#         '''
#         nums.sort()
#         res=sys.maxsize
        
#         begin=nums[:4]
#         end=nums[-4:]
        
#         for i in range(len(begin)):
#             res=min(res, end[i]-begin[i])
                
#         return res
        
    def minDifference(self, nums: List[int]) -> int:
        '''
        https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/discuss/731233/Similar-to-1423.-Maximum-Points-You-Can-Obtain-from-Cards
        
        Similar sliding window as in the `1423. Maximum Points You Can Obtain from Cards` problem
        Instead here we ignore this window
        
        1. Sort array
        
        2. Loop Isolate sliding window and extract difference between smallest and largest:
        
        Sliding window start from here:   [ 1, 4, 6, 7, 9, 15 ] 
                                                    |________|
        largest=6
        smallest=1
        6-1=5
        
                       continuing here:   [ 1, 4, 6, 7, 9, 15 ] 
                                          ____|        |______
        largest=7
        smallest=4
        7-4=3
        
             moving forward and end here: [ 1, 4, 6, 7, 9, 15 ] 
                                           |________|                                                 
        largest=15
        smallest=7
        15-7=7
        
        Result is smallest difference: 3
        
        '''
        if len(nums) < 4:
            return 0
        
        nums.sort()
        res=sys.maxsize
        
        n=len(nums)
        i=0
        j=n-4
        while i<4 and j<n:
            res=min(res, nums[j]-nums[i])
            i += 1
            j += 1
            
        return res

```
