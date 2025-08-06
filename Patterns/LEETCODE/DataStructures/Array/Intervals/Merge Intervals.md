### [Merge Intervals](https://leetcode.com/problems/merge-intervals/) <br>

Given an array of `intervals` where `intervals[i] = [start_i, end_i]`, merge all overlapping intervals, and return *an array of the non-overlapping intervals that cover all the intervals in the input*.


#### Example 1:

```
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

```

#### Example 2:

```
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

```

# Solutions

### Python
```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals)==1: return intervals
        intervals.sort(key=lambda tup:tup[0])

        res = [intervals[0]]        
        
        for inter in intervals:
            last = res[-1]
            prod = max(inter[0], last[0])-min(inter[1],last[1])
            if prod <= 0:
                # intersected
                res[-1]=[min(inter[0], last[0]), max(inter[1], last[1])]
            else:
                res.append(inter)

        return res
```
