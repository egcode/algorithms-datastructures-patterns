### [Sliding Window Maximum](https_problem_link) <br>

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return *the max sliding window*.

 


#### Example 1:

```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

```

#### Example 2:

```
Input: nums = [1], k = 1
Output: [1]

```

#### Example 3:

```
Input: nums = [1,-1], k = 1
Output: [1,-1]

```

#### Example 4:

```
Input: nums = [9,11], k = 2
Output: [11]

```

#### Example 5:

```
Input: nums = [4,-2], k = 2
Output: [4]

```



# Solutions

### Python
```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        '''
        Monotinically Decreasing queue
        
        You want to ensure the deque window only has decreasing elements. 
        That way, the leftmost element is always the largest.
        '''
    
        q=collections.deque() # stores indexes
        l=r=0
        res=[]
        
        while r<len(nums):
            
            # pop smaller values from q
            while q and nums[q[-1]] < nums[r]:
                q.pop()
            q.append(r)
            
            # cut the deque tail
            if l>q[0]:
                q.popleft()
            
            # check if window is size k
            if r+1 >= k:
                l += 1
                res.append(nums[q[0]])
            
            r += 1
        return res

```
