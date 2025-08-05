### [Insert Interval](https://leetcode.com/problems/insert-interval/) <br>

You are given an array of non-overlapping intervals where intervals[i] = [start_i, end_i] represents the start and end of the i-th interval. The intervals are sorted in ascending order by start_i.

You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by start_i and the merged intervals remain non-overlapping.

Return the array intervals after the insertion.


#### Example 1:

```
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

```

#### Example 2:

```
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

```


#### Example 3:

```
Input: intervals = [], newInterval = [5,7]
Output: [[5,7]]

```

#### Example 4:

```
Input: intervals = [[1,5]], newInterval = [2,3]
Output: [[1,5]]

```

#### Example 5:

```
Input: intervals = [[1,5]], newInterval = [2,7]
Output: [[1,7]]

```


# Solutions

### Python
```
class Solution:

    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if not intervals:
            return [newInterval]

        res = []
        cur = newInterval
        inserted = False

        for interval in intervals:
            prod = max(interval[0], cur[0]) - min(interval[1], cur[1])

            if prod <= 0:
                # Overlapping: merge interval with current
                cur = [min(cur[0], interval[0]), max(cur[1], interval[1])]
            elif interval[0] < cur[0]:
                # Current interval is completely before the new interval
                res.append(interval)
            elif interval[0] > cur[0]:
                # Current interval is completely after the new interval
                if not inserted:
                    res.append(cur)
                    inserted = True
                res.append(interval)

        if not inserted:
            res.append(cur)

        return res
```
