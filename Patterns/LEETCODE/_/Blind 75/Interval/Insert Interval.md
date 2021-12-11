### [Insert Interval](https://leetcode.com/problems/insert-interval/) <br>

You are given an array of non-overlapping `intervals` intervals where <img src="https://render.githubusercontent.com/render/math?math=intervals[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=start_i">, <img src="https://render.githubusercontent.com/render/math?math=end_i">] represent the start and the end of the <img src="https://render.githubusercontent.com/render/math?math=i^{th}"> interval and intervals is sorted in ascending order by <img src="https://render.githubusercontent.com/render/math?math=start_i">. You are also given an interval `newInterval = [start, end]` that represents the start and end of another interval.

Insert `newInterval` into `intervals` such that `intervals` is still sorted in ascending order by <img src="https://render.githubusercontent.com/render/math?math=start_i"> and `intervals` still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return `intervals` *after the insertion*.



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
        '''
        The idea here is to have cur interval
        and merge it with all intervals, and when done with merging cancel loop
        
        '''
        if not intervals: return [newInterval]
        res=[]
        cur=newInterval
        
        for i, ivl in enumerate(intervals):
            prod=max(ivl[0], cur[0]) - min(ivl[1], cur[1])
            
            if prod <= 0:
                # intersected
                cur=[min(ivl[0], cur[0]), max(ivl[1], cur[1])]
            else:
                if cur and cur != newInterval: # done with merging
                    res.append(cur)
                    cur=None
                    res += intervals[i:]
                    break
                    
                res.append(ivl)
                
        # if not merged yet
        # merge and sort
        if cur:
            res.append(cur)
            res.sort(key=lambda x: x[0])
        
        return res
```
