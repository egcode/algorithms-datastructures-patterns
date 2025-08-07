### [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) <br>

Given an array of meeting time intervals `intervals` where `intervals[i] = [start_i, end_i]`, return *the minimum number of conference rooms required*.


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
        sort starts and ends of interval.
        Loop through both arrays with p1 and p2 pointers
        if current start les than end we increase meetings count,
        and decrease otherwise
        '''
        starts=sorted([i[0] for i in intervals])
        ends=sorted([i[1] for i in intervals])
        n=len(intervals)
        p1,p2 = 0,0
        res, count = 0, 0
        while p1<n:
            if starts[p1]<ends[p2]:
                count += 1
                p1 += 1
            else:
                count -= 1
                p2 += 1
            res = max(res, count)

        return res


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
