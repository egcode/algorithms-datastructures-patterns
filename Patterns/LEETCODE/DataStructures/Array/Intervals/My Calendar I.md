### [My Calendar I](https://leetcode.com/problems/my-calendar-i/) <br>

You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a **double booking**.

A **double booking** happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers `start` and `end` that represents a booking on the half-open interval `[start, end]`, the range of real numbers `x` such that `start <= x < end`.

Implement the `MyCalendar` class:

 - `MyCalendar()` Initializes the calendar object.
 - `boolean book(int start, int end)` Returns `true` if the event can be added to the calendar successfully without causing a **double booking**. Otherwise, return `false` and do not add the event to the calendar.


#### Example 1:

```
Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output
[null, true, false, true]

Explanation
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.

```


# Solutions

### Python
```
class MyCalendar:

#     def __init__(self):
#         self.cal=collections.deque()
        

#     def book(self, start: int, end: int) -> bool:
#         if self.cal:
#             if start>=self.cal[-1][1]:
#                 # add to end
#                 self.cal.append([start, end])
#                 return True
#             elif end<=self.cal[0][0]:
#                 # add to start
#                 self.cal.appendleft([start, end])
#                 return True
#             else:
#                 # add to middle
#                 lo=0
#                 hi=len(self.cal)-1
#                 while lo<hi:
#                     mid=lo+(hi-lo)//2
#                     if self.cal[mid][0]>=end and self.cal[mid-1][1]<=start:
#                         self.cal.insert(mid, [start, end])
#                         return True
                    
#                     elif max(self.cal[mid][0], start)-min(self.cal[mid][1], end) < 0:
#                         return False
                    
#                     elif self.cal[mid][0]>=end:
#                         hi=mid-1
#                     elif self.cal[mid][1]<=start:
#                         lo=mid+1

#                 if max(self.cal[lo][0], start)-min(self.cal[lo][1], end) < 0:
#                     return False
#                 else:
#                     self.cal.insert(lo, [start, end])
#                     return True
                        
#         else:
#             self.cal.append([start, end])
#             return True
        
        
    def __init__(self):
        self.ranges=[]
        

    def book(self, start: int, end: int) -> bool:
        # print("\ncal: "+str(self.ranges)+" start:"+str(start)+" end:"+str(end))
        
        
        st = bisect.bisect_right(self.ranges, start)
        # If the index is even, 
        # that means that it is currently OUTSIDE THE RANGE of start and end indexes being tracked. 
        if st % 2 != 0: # inside the range
            return False
        
        
        en = bisect.bisect_left(self.ranges, end)
        # if st == en that means range [start, end] is somewhere between ranges and don't overlaps
        if en != st: # overlaps with some range
            return False 
        
        self.ranges[en:en] = [start, end]
        # print("end cal: "+str(self.ranges)+" start:"+str(start)+" end:"+str(end))
        
        return True

```
