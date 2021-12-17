### [My Calendar II](https://leetcode.com/problems/my-calendar-ii/) <br>

You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a **triple booking**.

A **triple booking** happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

The event can be represented as a pair of integers `start` and `end` that represents a booking on the half-open interval `[start, end]`, the range of real numbers `x` such that `start <= x < end`.

Implement the MyCalendarTwo class:

 - `MyCalendarTwo()` Initializes the calendar object.
 - `boolean book(int start, int end)` Returns `true` if the event can be added to the calendar successfully without causing a **triple booking**. Otherwise, return `false` and do not add the event to the calendar.


#### Example 1:

```
Input
["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, true, true, true, false, true, true]

Explanation
MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
myCalendarTwo.book(10, 20); // return True, The event can be booked. 
myCalendarTwo.book(50, 60); // return True, The event can be booked. 
myCalendarTwo.book(10, 40); // return True, The event can be double booked. 
myCalendarTwo.book(5, 15);  // return False, The event ca not be booked, because it would result in a triple booking.
myCalendarTwo.book(5, 10); // return True, The event can be booked, as it does not use time 10 which is already double booked.
myCalendarTwo.book(25, 55); // return True, The event can be booked, as the time in [25, 40) will be double booked with the third event, the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.

```



# Solutions

### Python
```
class MyCalendarTwo:

    def __init__(self):
        self.calendar=[]
        self.overlaps=[]
        

    def book(self, start: int, end: int) -> bool:
        '''
        Explanation here: https://leetcode.com/problems/my-calendar-ii/discuss/109530/N2-Python-Short-and-Elegant
        
        We store an array self.overlaps of intervals that are double booked, and self.calendar for intervals which have been single booked.

        The clever idea is we do not need to "clean up" ranges in calendar: if we have [1, 3] and [2, 4], this will be calendar = [[1,3],               [2,4]] and overlaps = [[2,3]]. We don't need to spend time transforming the calendar to calendar = [[1,4]].
        
        '''
        # print("self.calendar: "+str(self.calendar))
        # print("self.overlaps: "+str(self.overlaps))
        # print("\n")        
        for l,r in self.overlaps:
            if max(start,l)-min(r,end) < 0:
                return False
            
        for l,r in self.calendar:
            lo=max(start,l)
            hi=min(r,end)
            if lo-hi < 0:
                self.overlaps.append([lo, hi]) 
                
        self.calendar.append([start, end])
        return True

```
