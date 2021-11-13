### [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) <br>

Given an array of meeting time intervals `intervals` where <img src="https://render.githubusercontent.com/render/math?math=intervals[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=start_i">, <img src="https://render.githubusercontent.com/render/math?math=end_i">], return *the minimum number of conference rooms required*.


#### Example 1:

```
Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2

```

#### Example 2:

```
Input: intervals = [[7,10],[2,4]]
Output: 1

```

# Solutions

### Python
```
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        '''
        Using heap. Heap stores meeting ENDS.
        
        '''
        
        ends_heap = []
        intervals.sort(key=lambda x: x[0]) #  sort by start
        
        for intrv in intervals:
            start, end = intrv[0], intrv[1]
            
            if ends_heap and start >= ends_heap[0]:
                # if smallest meeting END is smaller than current START
                # that means that meeting is finished 
                heappop(ends_heap)
            
            # add end to heap
            heappush(ends_heap, end)
            
        return len(ends_heap)

```
