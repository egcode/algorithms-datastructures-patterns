### [Range Module](https://leetcode.com/problems/range-module/) <br>

A Range Module is a module that tracks ranges of numbers. Design a data structure to track the ranges represented as **half-open intervals** and query about them.

A **half-open interval** `[left, right]` denotes all the real numbers x where `left <= x < right`.

Implement the RangeModule class:

 - `RangeModule()` Initializes the object of the data structure.
 - `void addRange(int left, int right)` Adds the **half-open interval** `[left, right]`, tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval `[left, right]` that are not already tracked.
 - `boolean queryRange(int left, int right)` Returns `true` if every real number in the interval `[left, right]` is currently being tracked, and `false` otherwise.
 - `void removeRange(int left, int right)` Stops tracking every real number currently being tracked in the **half-open interval** `[left, right]`.


#### Example 1:

```
Input
["RangeModule", "addRange", "removeRange", "queryRange", "queryRange", "queryRange"]
[[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
Output
[null, null, null, true, false, true]

Explanation
RangeModule rangeModule = new RangeModule();
rangeModule.addRange(10, 20);
rangeModule.removeRange(14, 16);
rangeModule.queryRange(10, 14); // return True,(Every number in [10, 14) is being tracked)
rangeModule.queryRange(13, 15); // return False,(Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
rangeModule.queryRange(16, 17); // return True, (The number 16 in [16, 17) is still being tracked, despite the remove operation)

```


# Solutions

### Python
```
class RangeModule:
    '''
    Explanation in comments:
    https://leetcode.com/problems/range-module/discuss/169353/Ultra-concise-Python-(only-6-lines-of-actual-code)-(also-236ms-beats-100)
    '''

    def __init__(self):
        self.ranges = []

    def addRange(self, left: int, right: int) -> None:
        # print("\nadd before: "+str(self.ranges)+"   left:"+str(left)+" right:"+str(right))
        
        # if interval start element exists in array bisect_left find it as even 
        start = bisect.bisect_left(self.ranges, left)
        # if interval end element exists in array bisect_right find it as even         
        end = bisect.bisect_right(self.ranges, right)
        
        subtrack = []
        # If the index is even, it means that it is currently OUTSIDE THE RANGE of start and end indexes being tracked. 
        # In this case, we include this index to be updated in the tracking array.
        if start % 2 == 0:
            subtrack.append(left)
        if end % 2 == 0:
            subtrack.append(right)
			
        self.ranges[start:end] = subtrack
        # print("add after: "+str(self.ranges)+"   left:"+str(left)+" right:"+str(right))
        # print("")
        
        
    def removeRange(self, left: int, right: int) -> None:
        # print("\nremove before: "+str(self.ranges)+"   left:"+str(left)+" right:"+str(right))
        
        # if interval start element exists in array bisect_left find it as even 
        start = bisect.bisect_left(self.ranges, left)
        # if interval end element exists in array bisect_right find it as even         
        end = bisect.bisect_right(self.ranges, right)
        
        subtrack = []
        # If the index is odd, it means that it is currently INSIDE THE RANGE of start and end indexes being tracked. 
        # In this case, we include this index to be updated in the tracking array.         
        if start % 2 == 1:
            subtrack.append(left)
        if end % 2 == 1:
            subtrack.append(right)
			
        self.ranges[start:end] = subtrack
        # print("remove after: "+str(self.ranges)+"   left:"+str(left)+" right:"+str(right))
        # print("")
        
    def queryRange(self, left: int, right: int) -> bool:
        start = bisect.bisect_right(self.ranges, left)
        end = bisect.bisect_left(self.ranges, right)
		
        
        #  start == end : Both start and end are same. i.e there is no range boundary in between left and right.
        cond1 = start == end
        # If both these indexes are equal and these indexes are odd, 
        # it means the range queried is inside the range of values being tracked.
        cond2 = start % 2 == 1
        
        return cond1 and cond2

```
