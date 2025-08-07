### [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) <br>

Given an array of intervals intervals where intervals[i] = [start_i, end_i], return *the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping*.



#### Example 1:

```
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

```

#### Example 2:

```
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

```

#### Example 3:

```
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

```



# Solutions

### Python
```
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        '''
        Sort the intervals by their start time. 
        If two intervals overlap, the interval with larger end time will be removed        
        '''
        n=len(intervals)
        if n <= 1:
            return 0
        
        intervals.sort(key=lambda x: (x[0]))
        
        p1=0
        p2=1
        
        while p2<len(intervals):
            i1=intervals[p1]
            i2=intervals[p2]
            
            prod=max(i1[0], i2[0]) - min(i1[1], i2[1])
            
            if prod < 0: # overlap
                if i1[1]>i2[1]:
                    del intervals[p1]
                else:
                    del intervals[p2]
            else:
                p1 += 1
                p2 += 1
                
        return n-len(intervals)

```
