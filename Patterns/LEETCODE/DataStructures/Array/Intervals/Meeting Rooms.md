### [Meeting Rooms](https://leetcode.com/problems/meeting-rooms/) <br>

Given an array of meeting time `intervals` where `intervals[i] = [start_i, end_i]`, determine if a person could attend all meetings.



#### Example 1:

```
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false

```

#### Example 2:

```
Input: intervals = [[7,10],[2,4]]
Output: true

```

# Solutions

### Python
```
class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort(key=lambda x: x[0])
        n=len(intervals)
        
        for i in range(1, n):
            i1=intervals[i-1]
            i2=intervals[i]
            
            prod=max(i1[0], i2[0])-min(i1[1], i2[1])
            if prod < 0: # intersection
                return False
                
        return True

```
